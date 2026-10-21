本地编译与运行

在 .dotoj 目录的上一级（工程根目录）执行以下命令（Linux、macOS 或 WSL）：

cmake -S './' -B .dotoj/build -G 'Unix Makefiles' -DCMAKE_BUILD_TYPE=Release
cmake --build .dotoj/build --parallel 1
'./.dotoj/build/label'

请安装 CMake / GNU Make 及对应 C/C++ 编译器。源码、标准、优化和 ONLINE_JUDGE 宏由构建文件设置。运行后从标准输入读入数据。本地运行不模拟服务器的资源限制；服务器只运行选定的单个 ELF 程序。
工程构建暂不提供自动 sanitizer 诊断，也不在评测中下载依赖。
.dotoj 是本地说明和构建产物保留目录，导入源码 ZIP 时忽略该目录；Make 产生的其他二进制和中间文件须先移除。
