# Ubuntu 系统安装第三方库 Opencv

```shell
# 安装必要依赖
sudo apt install -y \
                    git \
                    vim \
                    htop \
                    cmake \
                    cmake-gui \
                    screen \
                    libavcodec-dev \
                    libavformat-dev \
                    libavutil-dev \
                    qtbase5-dev \
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
                    python3-pip \
                    libxcb*
sudo apt update
sudo apt install python3-pip
sudo -H pip3 install Cython -i https://pypi.tuna.tsinghua.edu.cn/simple
sudo -H pip3 install numpy -i https://pypi.tuna.tsinghua.edu.cn/simple

```

```shell
# clone OpenCV & 编译 & 安装
cd /tmp
git clone https://github.com/opencv/opencv.git --depth=1
cd /tmp/opencv/ 
mkdir build && cd build 
cmake .. && make -j10 
sudo make install
```
