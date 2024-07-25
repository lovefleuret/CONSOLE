# 基于官方的 VS Code Dev Container 基础镜像
FROM mcr.microsoft.com/vscode/devcontainers/base:ubuntu-20.04

# 安装必要的软件包
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    clangd-10 \
    && rm -rf /var/lib/apt/lists/*

# 切换到非root用户
USER vscode
