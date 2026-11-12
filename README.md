# ROS 2 C++ Communication Template

ROS 2 C++ 通信模板：包含 Publisher/Subscriber 和 Service Server/Client 的最小可运行示例。

## 环境版本

| 项目 | 版本 |
|------|------|
| ROS 2 | Humble |
| C++ | C++17 |
| 构建工具 | colcon + ament_cmake |

## 通信接口说明

### Topic

| 名称 | 类型 | 方向 | 说明 |
|------|------|------|------|
| `/demo_topic` | `example_interfaces/msg/String` | Publisher → Subscriber | 示例数据话题，周期 500 ms |

### Service

| 名称 | 类型 | 说明 |
|------|------|------|
| `/add_two_ints` | `example_interfaces/srv/AddTwoInts` | 输入两个整数，返回它们的和 |

## 依赖

- ROS 2 (Humble 或 Jazzy)
- `rclcpp`
- `example_interfaces`

## 构建

```bash
# 1. 创建工作空间并克隆仓库
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws/src
git clone <your-repo-url> ros2-cpp-comm-template

# 2. 安装依赖
cd ~/ros2_ws
rosdep install --from-paths src --ignore-src -r -y

# 3. 编译
colcon build --packages-select comm_demo

# 4. 加载环境变量
source install/setup.bash