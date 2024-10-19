```
colcon build --symlink-install
source install/setup.sh
ros2 launch move_service move_launch.py
```
参数在`move_service/config/params.yaml`下修改