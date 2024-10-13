# 除法实现

## 编译

```shell
colcon build
```

## 运行

```shell
source install/setup.bash
ros2 run division division
```

## 发送消息示例

```shell
ros2 topic pub /command std_msgs/msg/String 'data: "30 9"' #30为被除数 9为除数
```
