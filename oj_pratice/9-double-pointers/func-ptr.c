#include <stdio.h>

// 待拆解的目标声明
int* (*(*(**(*target)[2])[3])(int (*(*)[4])(char), const int* (*)[5]))(double (*)[6]);

// 函数的返回值类型
typedef int* (*Ret)(double (*)[6]); 

// 函数的参数类型列表
#define PARAMS (int (*(*)[4])(char), const int* (*)[5])

// 装函数指针的数据结构
#define CONTAINER(FN, x) FN (**(*x)[2])[3]

// 以下代码不需要理解
#undef target
#undef Ret
#undef _Expected
#undef _RealFn
#undef _FakeFn
#undef _Tag
#undef _p
#undef _a
#undef _b
#undef __typeof__
#undef typeof
#undef _Static_assert
#undef _Generic
#undef extern
#undef int
#undef void
#undef char
#undef const
#undef struct
#undef return
#undef printf
#undef main
typedef __typeof__(target) _Expected;
typedef Ret (*_RealFn) PARAMS;
extern CONTAINER(_RealFn, target);
struct _Tag { int _; };
typedef struct _Tag (*_FakeFn)(struct _Tag);
void _ban_semicolon(CONTAINER(_FakeFn, _p));
int main(void) {
    int target = 0;
    CONTAINER(_RealFn, _a);
    CONTAINER(_FakeFn, _b);
    (void)target;
    (void)&_a;
    (void)&_b;
    _Static_assert(_Generic((_RealFn)0, Ret (*)(struct _Tag): 0, default: 1),
                   "Invalid PARAMS.");
    _Static_assert(_Generic(&_a, __typeof__(&_b): 0, default: 1),
                   "Invalid CONTAINER.");
    _Static_assert(_Generic(&_a, _Expected *: 1, default: 0),
                   "Invalid decomposition.");
    printf("PASSED\n");
    return 0;
}
