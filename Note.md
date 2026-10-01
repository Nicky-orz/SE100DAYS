# Gain From CS50

## lec1 C
- 代码质量评估：正确性、设计、风格

## lec2 Arrays
- string的本质是\0结尾的字符数组，在C中用char*（指向字符串第一位字符）或char[]表示
- 小黄鸭调试法：解释自己的代码逻辑

## lec4 Memory
- 内存分为：代码区，全局区，只读区，栈，堆
- 32位指针和64位指针的区别：能指向内存地址的总数量
- 存储元件：寄存器->CPU缓存->内存RAM->外存SSD
- &（取地址）表示变量的地址，\*（解引用）表示指针或者指针所指的变量，这些习惯上跟在类型后面，空格前面
- 0x前缀代表十六进制，优势在于能用更少位数表示二进制信息
- 动态内存分配应该检查分配失效情况（NULL）
- malloc后应该有free
- 缓冲区溢出会覆盖相邻内存，应该检查缓冲区内容长度
- 文件读写：1.文件指针类型FILE; 2.打开文件，返回指针`fopen(文件名,"r"/"w"/"a");` 3.`fread/fwrite(类型,字节数,数量,指针)`，`fprintf(指针,"格式符",变量)` 4.`fclose(指针)`
- 命令行参数会返回1.argc参数个数（包括命令）2.argv具体参数

## lec6 Python
- `print(f"hello,{name}")`进行占位符形式的输出
- `print`中字符串可以+和*
- 命名参数:`end=""`取消默认换行
- python中单双引号都可以定义字符串，社区中倾向用单引号
- python中的数据类型有:bool,float,int,str
- 面向对象编程：`.lower()`，(类型、库)->对象，函数->方法
- 用不到的循环变量写成_
- `if __name__ == "__main__"` 避免导入库时执行main函数
- `//`用于进行整数除法
- 异常处理机制：`try-except`
- python对作用域的处理并不严格
- 列表:增加`.append()` 求和`sum()` 长度`len()`
- `for-else`遍历整个循环没有执行`break`，则执行`else`
- `if a in list`遍历list判断是否存在a
- 键值对定义:`dic={"key":"value",...}`
- csv:追加模式打开文件`with open("doc.csv","a") as filename:`，创建对象 `writername = csv.writer(filename)`，写入`writername.writerow([content])`，字典`writername = csv.DictWriter(filename,fieldnames=[])`，`writer.writerow({...})`，字典读写的健壮性比列表强


# Gain From CPL

## Lesson1
- C语言的翻译：.c--预处理->.i--编译->.s--汇编->.o--链接->.exe

## Lesson2
- scanf的输入最好一一对应缓冲区输入
- scanf同时支持控制数量（数组），精度，用变量赋值的话，宽度或精度 \* 各取一个 int
- scanf不使用无宽度限制的%s，检查scanf的返回值，以防止缓冲区溢出
- `fgets(line, sizeof(line), stdin)`
- sscanf使用同scanf,第一个参数是字符串
- fgets+sscanf比scanf安全
- `%.Ns`(前N位);`%.Nf`(小数);`%.NG`(有效数字);`%.NE`(小数);`%0Nd`(N位，不足补0);`%Nd`(右对齐补空格)
- pow在开负数的奇数次根时会出错

## Lesson3
- 输出失败要处理剩余字符，用 `%*` 赋值抑制符
- 或、与、非
- 三则表达式?:

## Lesson4
- `go-while`语句的使用

# Gain From deepseek
- `#define A B`  宏定义，作用是把代码中的A替换成B
- `memset(a,-1,sizeof(a));`  初始化C++
- `strlen(a);`   字符串长度C
- `realloc(p,sizeof(int));` 重新分配内存
- `void *memcpy(void *dest, const void *src, size_t n);` 从 src 复制 n 个字节到 dest，返回 dest
- 学会读像上面一样的说明
- `static int` 函数内初始化一次，全局访问，或者是只读
- memset按字节填充,极大0x3f,
- 图和集合往往可以转化。
- 不确定数据组数时使用`while(cin)`
- 偏序是集合上满足自反性、反对称性和传递性的二元关系；它允许有些元素之间不可比较