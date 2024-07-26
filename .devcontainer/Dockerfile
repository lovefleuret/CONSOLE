# 基于官方的 VS Code Dev Container 基础镜像
FROM mcr.microsoft.com/vscode/devcontainers/base:ubuntu-20.04

# 安装必要的软件包
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    vim \
    && rm -rf /var/lib/apt/lists/*


RUN wget https://github.com/clangd/clangd/releases/download/18.1.3/clangd-linux-18.1.3.zip && \
    unzip clangd-linux-18.1.3.zip && \
    mv clangd_18.1.3 /usr/local/clangd_18.1.3 && \
    ln -s /usr/local/clangd_18.1.3/bin/clangd /usr/local/bin/clangd && \
    rm clangd-linux-18.1.3.zip

# 设置环境变量
ENV PATH="/usr/local/clangd_18.1.3/bin:${PATH}"

# 切换到非root用户
USER vscode
