# 基于官方的 VS Code Dev Container 基础镜像
FROM mcr.microsoft.com/vscode/devcontainers/base:ubuntu-20.04

# 安装必要的软件包
RUN apt-get update && apt-get install -y \
    build-essential \
    clangd \
    cmake \
    git \
    wget \
    vim \
    && rm -rf /var/lib/apt/lists/*


ENV PATH="/usr/bin/clangd:${PATH}"
# 切换到非root用户
USER vscode
