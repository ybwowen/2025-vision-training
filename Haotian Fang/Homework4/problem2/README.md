# ROS2 Action Communication Demo

这个项目演示了 ROS2 中的动作（Action）通信机制。它模拟了一个简单的机器人移动场景，其中客户端发送移动指令，服务器执行移动并提供反馈。

## 工作原理

### 概述

1. 客户端节点发送一个目标距离给服务器节点。
2. 服务器节点以固定速度模拟机器人移动。
3. 服务器持续向客户端发送剩余距离的反馈。
4. 如果在指定时间内完成移动，动作成功；否则，动作失败。
5. 如果动作失败，客户端会将距离减半并重新尝试。

### 关键参数

- `s`: 目标移动距离（由客户端设置）
- `v`: 移动速度（由服务器使用）
- `time_limit`: 允许的最大执行时间（由服务器使用）

### 详细流程

1. 客户端发送包含目标距离 `s` 的请求。
2. 服务器接收请求，开始以速度 `v` 模拟移动。
3. 每 0.1 秒，服务器更新并发送剩余距离的反馈。
4. 如果剩余距离达到 0，动作成功完成。
5. 如果执行时间超过 `time_limit`，服务器中止动作。
6. 如果动作失败，客户端将距离减半并重新发送请求。
7. 这个过程持续到动作成功完成。

## 使用方法

### 先决条件

- ROS2 环境（推荐 Foxy 或更新版本）
- colcon 构建工具

### 构建项目

1. 将此项目克隆到您的 ROS2 工作空间的 `src` 目录中。
2. 在工作空间根目录下运行：
   ```
   colcon build --packages-select robot_action_demo
   ```
3. 源化安装文件：
   ```
   source install/setup.bash
   ```

### 运行演示

使用提供的 launch 文件运行演示：

```
ros2 launch robot_action_demo move_demo.launch.py
```

### 自定义参数

您可以在启动时自定义参数：

```
ros2 launch robot_action_demo move_demo.launch.py 'move_action_server:={v: 0.5, time_limit: 5.0}' 'move_action_client:={s: 10.0}'
```

这将设置速度为 0.5 m/s，时间限制为 5 秒，初始距离为 10 米。

## 项目结构

- `src/move_action_server.cpp`: 实现动作服务器
- `src/move_action_client.cpp`: 实现动作客户端
- `action/Move.action`: 定义动作消息结构
- `launch/move_demo.launch.py`: launch 文件for启动服务器和客户端

## 自定义和扩展

- 修改 `config/params.yaml` 来永久更改默认参数。
- 在 `src/move_action_server.cpp` 中调整移动逻辑以实现更复杂的行为。
- 在 `src/move_action_client.cpp` 中修改重试逻辑以实现不同的错误处理策略。

## 故障排除

- 确保所有依赖都已正确安装。
- 检查 ROS2 环境是否正确设置。
- 如果遇到通信问题，请确保 ROS 主节点正在运行。