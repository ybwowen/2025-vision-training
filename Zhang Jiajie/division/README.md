```
colcon build --symlink-install
source install/setup.sh
ros2 launch div_service div_launch.py
```
参数在`div_service/launch/div_launch.py`的`node_clt`下`arguments`修改