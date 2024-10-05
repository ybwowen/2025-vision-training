import numpy as np
import matplotlib.pyplot as plt
from matplotlib import font_manager

# 设置中文字体
plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号

# 读取数据
with open('dollar.txt', 'r') as f:
    data = [float(line.strip()) for line in f]

# 卡尔曼滤波器参数
dt = 1.0  # 时间步长
N = len(data)  # 观测数量

# 初始化状态
x = np.array([[data[0]], [0]])  # 初始状态 [位置, 速度]
P = np.diag([1.0, 1.0])  # 初始协方差矩阵

# 状态转移矩阵
F = np.array([[1, dt],
              [0, 1]])

# 观测矩阵
H = np.array([[1, 0]])

# 过程噪声协方差
Q = np.diag([0.01, 0.01])

# 测量噪声协方差
R = np.array([[0.1]])

# 存储结果
filtered_state_means = []
filtered_state_covariances = []

# 卡尔曼滤波
for measurement in data:
    # 预测
    x = F @ x
    P = F @ P @ F.T + Q

    # 更新
    y = measurement - H @ x
    S = H @ P @ H.T + R
    K = P @ H.T @ np.linalg.inv(S)
    x = x + K @ y
    P = (np.eye(2) - K @ H) @ P

    filtered_state_means.append(x)
    filtered_state_covariances.append(P)

# 预测未来10天
future_days = 10
future_predictions = []
for _ in range(future_days):
    x = F @ x
    P = F @ P @ F.T + Q
    future_predictions.append(x[0, 0])

# 绘图
plt.figure(figsize=(12, 6))
plt.plot(range(N), data, label='观测值')
plt.plot(range(N), [m[0, 0] for m in filtered_state_means], label='滤波估计')
plt.plot(range(N, N+future_days), future_predictions, label='未来预测', linestyle='--')
plt.xlabel('天数')
plt.ylabel('美元汇率')
plt.title('美元汇率卡尔曼滤波预测')
plt.legend()
plt.grid(True)
plt.show()

# 打印未来10天的预测值
print("未来10天的预测值:")
for i, pred in enumerate(future_predictions, 1):
    print(f"第{i}天: {pred:.4f}")