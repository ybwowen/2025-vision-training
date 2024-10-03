import numpy as np
import matplotlib.pyplot as plt
import torch
from torch.autograd.functional import jacobian
from tqdm import tqdm

class Kalman:
    def __init__(self, x, P, H):
        self.x = x # [state * 1]
        self.P = P # [state * state]
        self.H = H # [obs * state]
        
    def predict(self, F, Q):
        self.x = np.dot(F, self.x)
        self.P = F @ self.P @ F.T + Q
    
    def update(self, z, R):
        y = z - self.H @ self.x
        S = self.H @ self.P @ self.H.T + R
        K = self.P @ self.H.T @ np.linalg.inv(S)
        self.x = self.x + K @ y
        self.P = (np.eye(self.P.shape[0]) - K @ self.H) @ self.P

    def get_n_predict(self, n : int, F):
        res_lst = []
        now_x = self.x
        for i in range(n):
            now_x = F @ now_x
            res_lst.append(now_x)
        return res_lst


class Ekf:
    def __init__(self, x, P, measure_func):
        self.x = x # [state * 1]
        self.P = P # [state * state]
        self.measure_func = measure_func
        
    def predict(self, predict_func, Q):
        F = jacobian(predict_func, self.x)
        # print(f"{F=}")
        self.x = predict_func(self.x)
        self.P = F @ self.P @ F.mT + Q
        
    def update(self, z, R):
        y = z - self.measure_func(self.x)
        H : torch.Tensor = jacobian(self.measure_func, self.x)
        if H.dim() == 1:
            H = H.unsqueeze(0)
        S = H @ self.P @ H.mT + R
        K = self.P @ H.mT @ np.linalg.inv(S)
        self.x = self.x + K @ y
        self.P = (torch.eye(self.P.shape[0]) - K @ H) @ self.P
    
    def get_n_predict(self, n : int, predict_func):
        res_lst = []
        now_x = self.x
        for i in range(n):
            now_x = predict_func(now_x)
            res_lst.append(now_x)
        return res_lst


dollar_lst = []
with open("dollar.txt","r") as f:
    for fi in f:
        dollar_lst.append(float(fi[:-1]))

kalman = Kalman(np.array([0, 0]), P=np.array([[1e6, 0], [0, 0]]), H=np.array([[1, 0]]))
t = list(range(len(dollar_lst)))
predict_state = []
for i in tqdm(range(len(dollar_lst)), desc="kalman"):
    kalman.predict(F=np.array([[1, t[i] - t[i - 1] if i > 0 else 0], [0, 1]]), Q=np.array([[0.1, 0], [0, 10]]))
    kalman.update(z=np.array([dollar_lst[i]]), R=np.eye(1) * 50)
    predict_state.append(kalman.x)
predict_state += kalman.get_n_predict(10, np.array([[1, 1],[0, 1]]))

# use [x, phi, v, A, w] as state prameter : x = c_0 + vt + A sin(wt + phi_0)
# x' = x + v * dt + A* sin(phi + w*dt) - A * sin(phi)
# phi' = phi + w * dt
# v' = v
# A' = A
# w' = w
def predict_func_with_dt(dt):
    def predict_func(x: torch.Tensor):
        x0_new = x[0] + x[2]*dt + x[3] * (torch.sin(x[1] + x[4]* dt) - torch.sin(x[1]))
        x1_new = x[1] + x[4]*dt
        return torch.cat([x0_new.unsqueeze(0), x1_new.unsqueeze(0), x[2:]])
    return predict_func


def measure_func(x: torch.Tensor):
    pos = x[0]
    return pos

P = 1e3 * torch.eye(5)
P[0,0] = 1e6
kalman_ekf = Ekf(torch.tensor([0., 0., 0., 1., 1.]), P= P, measure_func= measure_func)
dollar_ekf = []
for i in tqdm(range(len(dollar_lst)), desc="ekf"):
    kalman_ekf.predict(
        predict_func=predict_func_with_dt(1),
        Q=5 * torch.eye(5)
    )
    kalman_ekf.update(z=torch.tensor([dollar_lst[i]], dtype=torch.float32), R=torch.eye(1) * 50.0)
    # print(f"# {i+1}: {kalman_ekf.x}")
    dollar_ekf.append(kalman_ekf.x)
dollar_ekf += kalman_ekf.get_n_predict(10, predict_func_with_dt(1))

predict_dollar = [i[0] for i in predict_state]
predict_dollar_ekf = [i[0] for i in dollar_ekf]
plt.plot(dollar_lst, label = "real")
plt.plot(predict_dollar, label = "predict")
plt.plot(predict_dollar_ekf, label = "predict(ekf)")
plt.legend()
plt.savefig('out.png')
