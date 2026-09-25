# Gain From CS50

## lec1
- 代码质量评估：正确性、设计、风格

## lec2
- string的本质是\0结尾的字符数组，在C中用char*（指向字符串第一位字符）或char[]表示
- 小黄鸭调试法：解释自己的代码逻辑

## lec4
- 内存分为：代码区，全局区，只读区，栈，堆
- 32位指针和64位指针的区别：能指向内存地址的总数量
- 存储元件：寄存器->CPU缓存->内存RAM->外存SSD
- &（取地址）表示变量的地址，*（解引用）表示指针或者指针所指的变量，这些习惯上跟在类型后面，空格前面
- 0x前缀代表十六进制，优势在于能用更少位数表示二进制信息
- 动态内存分配应该检查分配失效情况（NULL）
- malloc后应该有free
- 缓冲区溢出会覆盖相邻内存，应该检查缓冲区内容长度
- 文件读写：1.文件指针FILE;2.fopen(文件名,"`r`/`w`/`a`");3.fread/fwrite(类型,字节数,数量,指针)4.fclose(指针)
- 命令行参数会返回1.参数个数（包括命令）2.具体参数


# Gain From CPL

## Lesson1
- C语言的翻译：.c--预处理->.i--编译->.s--汇编->.o--链接->.exe

## Lesson2
- scanf的输入最好一一对应缓冲区输入
- scanf同时支持控制数量（数组），精度，用变量赋值的话，宽度或精度 * 各取一个 int
- scanf不使用无宽度限制的%s，检查scanf的返回值，以防止缓冲区溢出
- fgets(`line`, sizeof(`line`), stdin)
- sscanf使用同scanf,第一个参数是字符串
- fgets+sscanf比scanf安全
- %.Ns(前N位);%.Nf(小数);%.NG(有效数字);%.NE(小数);%0Nd(N位，不足补0);%Nd(右对齐补空格)
- pow在开负数的奇数次根时会出错

## Lesson3
- 输出失败要处理剩余字符，用 %* 赋值抑制符
- 或、与、非
- 三则表达式?:

# Gain From deepseek
- #define `A` `B`  宏定义，作用是把代码中的A替换成B
- memset(`a`,`-1`,sizeof(`a`));  初始化C++
- strlen(`a`);   字符串长度C
- realloc(`p`,sizeof(`int`)); 重新分配内存
- void *memcpy(void *dest, const void *src, size_t n); 从 src 复制 n 个字节到 dest，返回 dest
- 学会读像上面一样的说明
- static `int` 函数内初始化一次，全局访问，或者是只读
- memset按字节填充,极大0x3f,极小0xc0,快；fill按值填充，慢