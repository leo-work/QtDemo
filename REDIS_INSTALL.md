# Redis 安装文档

---

## redis安装
    1. 配置编译环境：
    sudo yum install gcc-c++
    2. 下载源码：
    wget http://download.redis.io/releases/redis-3.2.8.tar.gz 
    
    // 可以去官网选择最新版
    3. 解压源码：
    tar -zxvf redis-3.2.8.tar.gz
    4. 进入到解压目录：
    cd redis-3.2.8
    5. 执行make编译Redis：
    make MALLOC=libc
    注意：make命令执行完成编译后，会在src目录下生成6个可执行文件，分别是redis-server、redis-cli、redis-benchmark、redis-check-aof、redis-check-rdb、redis-sentinel。
    6. 安装Redis：
    make install 
    7. 配置Redis能随系统启动:
    ./utils/install_server.sh 
    
    显示结果信息如下：
    一直选择默认配置
    看见Installation successful! 配置结束

## hiredis安装（git安装：yum install git）
    1. 拉取代码
      git clone https://github.com/redis/hiredis.git
    2. 编译
      cd hiredis && make 
    3. 安装
      sudo make install
## libevent安装
    1. 拉取代码
      git clone https://github.com/nmathewson/Libevent.git
    2. cmake 配置
      cd Libevent && mkdir build 
      ln -s /usr/local/Cellar/openssl/1.0.2d_1/include/openssl/ ./include/openssl
      cd build && cmake ..
    3. 编译
      make
    4. 安装
      sudo make install
## openssl安装
    1. 拉取代码
      git clone https://github.com/openssl/openssl.git
    2. cmake 配置
      ./config --prefix=/usr/local/ssl --openssldir=/usr/local/ssl
    3. 编译
      make
    4. 安装
      sudo make install


