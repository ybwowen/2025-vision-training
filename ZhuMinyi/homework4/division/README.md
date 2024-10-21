## How to compile

```shell
colcon build --symlink-install --packages-select division 
```
### In one terminal:

```shell
source install/setup.zsh  # or source install/setup.sh
ros2 run division client 
```

### In another terminal:

```shell
source install/setup.zsh  # or source install/setup.sh
ros2 run division server
```