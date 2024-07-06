# Ubuntu 系统安装第三方库 Opencv 脚本

#!/bin/bash

# 设置日志格式
readonly COLOR_RED='\033[31m'
readonly COLOR_FULL_RED='\033[41m'
readonly COLOR_GREY='\033[90m'
readonly COLOR_GREEN='\033[92m'
readonly COLOR_YELLOW='\033[93m'
# define style
readonly STYLE_BOLD='\033[1m'
# define reset
readonly RESET='\033[0m'
# logger level
log_debug() { echo -e "${COLOR_GREY}  [DEBUG] $1${RESET}" | tee -a ../log/log_debug.log; }
log_info() { echo -e "${COLOR_GREEN}  [INFO] $1${RESET}" | tee -a ../log/log_info.log; }
log_warning() { echo -e "${COLOR_YELLOW}  [WARNING] $1${RESET}" | tee -a ../log/log_warning.log; }
log_error() { echo -e "${STYLE_BOLD}${COLOR_RED}  [ERROR] $1${RESET}" | tee -a ../log/log_error.log; }
log_critical() { echo -e "${COLOR_FULL_RED}  [CRITICAL] $1${RESET}" | tee -a ./log/log_critical.log; }

# 通过交互式脚本读取获取密码
export password
log_info "请输入密码 :"
read password

# 用户名 username
uid=1000 # 替换为你要查询的 uid
export username=$(id $uid | awk -F'(' '{print $2}' | cut -d')' -f1)

# 默认下载路径 downFinder
export downFinder=~/Downloads/

# 当前路径
current_dir=$PWD

log_info "qt && opencv depend installing..."
echo ${password} | sudo -S apt update
echo ${password} | sudo -S apt install -y \
                    git \
                    vim \
                    htop \
                    cmake \
                    cmake-gui \
                    screen \
                    qtbase5-dev \
                    libavcodec-dev \
                    libavformat-dev \
                    libavutil-dev \
                    libeigen3-dev \
                    libglew-dev \
                    libgtk2.0-dev \
                    libgtk-3-dev \
                    libjpeg-dev \
                    libpostproc-dev \
                    libswscale-dev \
                    libtbb-dev \
                    libtiff5-dev \
                    libv4l-dev \
                    libxvidcore-dev \
                    libx264-dev \
                    zlib1g-dev \
                    pkg-config \
                    libxcb*
echo ${password} | sudo -S apt install -y python3-pip
echo ${password} | sudo -S -H pip3 install Cython -i https://pypi.tuna.tsinghua.edu.cn/simple
echo ${password} | sudo -S -H pip3 install numpy -i https://pypi.tuna.tsinghua.edu.cn/simple
log_info "qt && opencv depend installation complete !!"

log_info "opencv clone & install !!"
cd /tmp && \
git clone https://github.com/opencv/opencv.git --depth=1 && \
cd /tmp/opencv/ && \
mkdir build && cd build && \
cmake .. && make -j10 && \
echo ${password} | sudo -S make install
log_info "OpenCV 安装完毕 !!!"
cd ${current_dir}


