
import os
import numpy as np

import matplotlib.pyplot as plt
def plot_tuple(tup_xyname):
    for x, y, name in tup_xyname:
        plt.plot(x, y, label=name)
    plt.legend()
    plt.show()
    
dollars = np.array([])
with open('stocks/dollar.txt', 'r') as f:
  dollars = np.array([float(x.strip()) for x in f.readlines()])
N = len(dollars)

# plot_tuple([(range(N), dollars, 'dollars')])

class Kalman:
  def __init__(self, x, P, H):
    self.x = x # [state * 1]
    self.P = P # [state * state]
    self.H = H # [obs * state]
        
  def predict(self, F, Q):
    self.x = F @ self.x
    self.P = F @ self.P @ F.T + Q
    
  def update(self, z, R):
    y = z - self.H @ self.x
    S = self.H @ self.P @ self.H.T + R
    K = self.P @ self.H.T @ np.linalg.inv(S)
    self.x = self.x + K @ y
    self.P = self.P - K @ self.H @ self.P

alpha = 0.1
Q = np.eye(2)
R = np.eye(1)
P = np.array([[1e18, 0], [0, 0]])
kalman = Kalman(np.array([0, 0]), P = P, H = np.array([[1, 0]]))
predict_dollars = []
for i in range(N):
  F = np.array([[1, 1 if i > 0 else 0], [0, 1]])
  kalman.predict(F, Q)
  kalman.update(np.array([dollars[i]]), R)
  predict_dollars.append(kalman.x[0])

# plot_tuple([(range(N), dollars, 'past dollars'), (range(N), predict_dollars, 'predict')])

M = 20
for i in range(M):
  F = np.array([[1, 1], [0, 1]])
  kalman.predict(F, Q)
  predict_dollars.append(kalman.x[0])

future_dollars = np.array([])
with open('stocks/future.txt', 'r') as f:
  future_dollars = np.array([dollars[-1]] + [float(x.strip()) for (i, x) in zip(range(M), f.readlines())])

plot_tuple([(range(N), dollars, 'past dollars'), (range(N + M), predict_dollars, 'predict future'), (range(N - 1, N + M), future_dollars, 'future real')])
