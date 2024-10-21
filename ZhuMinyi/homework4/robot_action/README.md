## How to compile

```shell
colcon build --symlink-install --packages-select robot_action 
source install/setup.zsh  # or source install/setup.sh
ros2 launch robot_action launch.py
```