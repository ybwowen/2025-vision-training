# ROS2 Division Service Communication Demo

这个项目演示了 ROS2 中的服务（Service）通信机制。它实现了一个简单的除法服务，客户端发送两个整数，服务器返回它们的商和余数。

## 工作原理

### 概述

1. 客户端节点发送两个整数（被除数和除数）给服务器节点。
2. 服务器节点执行除法运算，计算商和余数。
3. 服务器将结果返回给客户端。
4. 客户端接收并显示结果。

### 关键功能

- 执行整数除法
- 处理除数为零的情况
- 返回商和余数

### 详细流程

1. 客户端发送包含被除数和除数的请求。
2. 服务器接收请求，检查除数是否为零。
3. 如果除数不为零，服务器执行除法运算。
4. 服务器将商和余数作为响应发送回客户端。
5. 客户端接收响应并显示结果。

## 使用方法

### 先决条件

- ROS2 环境（推荐 Foxy 或更新版本）
- colcon 构建工具

### 构建项目

1. 将此项目克隆到您的 ROS2 工作空间的 `src` 目录中。
2. 在工作空间根目录下运行：
   ```
   colcon build --packages-select division_package
   ```
3. 源化安装文件：
   ```
   source install/setup.bash
   ```

### 运行演示

1. 在一个终端中启动服务器：
   ```
   ros2 run division_package division_server
   ```

2. 在另一个终端中运行客户端，提供两个整数作为参数：
   ```
   ros2 run division_package division_client 10 3
   ```
   这将计算 10 除以 3 的结果。

## 项目结构

- `src/division_server.cpp`: 实现除法服务器
- `src/division_client.cpp`: 实现除法客户端
- `srv/DivisionService.srv`: 定义服务消息结构

## 自定义和扩展

- 修改 `src/division_server.cpp` 以添加更复杂的数学运算。
- 在 `src/division_client.cpp` 中添加错误处理和重试逻辑。
- 扩展服务定义以支持更多的操作数或不同的数学运算。

## 故障排除

- 确保所有依赖都已正确安装。
- 检查 ROS2 环境是否正确设置。
- 如果遇到通信问题，请确保 ROS 主节点正在运行。
- 当使用除数为零时，检查服务器是否正确处理这种情况。
