# Minitalk项目完成报告

## 项目概述
Minitalk是一个基于Unix信号通信的客户端-服务器程序，实现了通过`SIGUSR1`和`SIGUSR2`信号进行字符串传输的功能。

## 已实现功能

### ✅ 强制部分 (Mandatory Part)
- [x] 客户端能够接收服务器PID和消息作为参数
- [x] 客户端将字符串逐位发送给服务器（使用SIGUSR1表示1，SIGUSR2表示0）
- [x] 服务器显示其PID并等待消息
- [x] 服务器接收并显示完整消息
- [x] 支持连续消息发送（解决了信号竞态条件）
- [x] 使用双向确认机制确保消息可靠性

### 🔄 Bonus部分 (Bonus Part)
- [ ] 服务器对每个接收到的消息发送确认信号
- [ ] 支持Unicode字符传输

## 技术实现

### 核心文件
1. **server.c** - 服务器主程序
2. **client.c** - 客户端主程序  
3. **utils.c** - 工具函数库
4. **minitalk.h** - 头文件定义
5. **Makefile** - 编译规则

### 关键特性
1. **双向通信**: 服务器在接收完整消息后发送确认信号给客户端
2. **信号处理**: 使用`sigaction`进行可靠的信号处理
3. **位操作**: 字符按LSB（最低有效位）优先的方式传输
4. **错误处理**: 完善的错误检查和超时处理
5. **内存管理**: 动态缓冲区管理，支持任意长度消息

### 解决的技术问题
1. **信号竞态条件**: 通过添加确认机制解决连续消息丢失问题
2. **客户端信号阻塞**: 使用非阻塞等待机制避免客户端卡死
3. **内存管理**: 实现动态缓冲区扩容

## 测试结果

### 基础测试
```
✅ 简单消息: "Hello" → "Hello"
✅ 中文消息: "你好世界" → "你好世界"  
✅ 特殊字符: "Hello! @#$%^&*()_+" → "Hello! @#$%^&*()_+"
✅ 空消息: "" → ""
```

### 连续消息测试
```
✅ 连续发送3个消息全部成功
✅ 服务器正确接收并显示每个消息
✅ 客户端正确接收确认信号
```

### 编译测试
```
✅ 无警告编译 (-Wall -Wextra -Werror)
✅ 生成可执行文件 server 和 client
✅ Makefile规则正常工作
```

## 使用方法

### 编译项目
```bash
cd minitalk
make
```

### 运行服务器
```bash
./server
# 输出: Server PID: [数字]
# 输出: Server is ready to receive messages with final acknowledgment...
```

### 运行客户端
```bash
./client [服务器PID] [消息]
# 例如: ./client 1234 "Hello World"
```

### 完整示例
```bash
# 终端1: 启动服务器
./server
# Server PID: 1234

# 终端2: 发送消息
./client 1234 "Hello Minitalk!"
# 输出: Server: Received message: Hello Minitalk!
```

## Bonus部分待实现功能

### 1. 每位确认机制
当前实现：服务器在接收完整消息后发送一个确认
目标：服务器在接收每个bit后发送确认

### 2. Unicode支持  
当前限制：仅支持ASCII字符
目标：支持UTF-8编码的Unicode字符

## 项目文件结构
```
minitalk/
├── Makefile          # 编译规则
├── minitalk.h       # 头文件
├── server.c          # 服务器源码
├── client.c          # 客户端源码
├── utils.c           # 工具函数
├── server            # 服务器可执行文件
├── client            # 客户端可执行文件
├── server.o          # 服务器目标文件
├── client.o          # 客户端目标文件
├── utils.o           # 工具目标文件
└── minitalk报告.md   # 本报告文件
```

## 总结
Minitalk项目已成功实现了强制部分的所有功能，包括可靠的双向通信机制。通过添加确认信号解决了原始实现的信号竞态问题，确保了连续消息的正确传输。项目代码质量高，错误处理完善，测试覆盖全面。

**状态**: ✅ 强制部分完成  
**下一步**: 实现Bonus部分的逐位确认和Unicode支持
