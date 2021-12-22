#include <stdio.h>
#include <string.h>
#include <math.h>
/*
 * 函数
 * 头文件中包含的都是函数声明，而不是函数定义，
 * 函数定义都放在了其它的源文件中，这些源文件已经提前编译好了，并以动态链接库或者静态链接库的形式存在，
 * 只有头文件没有系统库的话，在链接阶段就会报错，程序根本不能运行。
 * */

//  没有函数体，只有函数名、返回值类型、参数列表（重点是参数类型）等与该函数有关的信息，这称为函数原型（Function Prototype）
int max(int x, int y);

int gcd(int x, int y);  //  求最大公约数

int gcd2(int x,int y);  //  递归求最大公约数

const int MOD = 15537;
const int n = 10;
//  在函数内部所创建的变量被称为局部变量，它的作用域仅限于函数内部， 离开该函数后就是无效的，再使用就会报错 【形参实际上就是局部变量】
//  在所有函数外部定义的变量称为全局变量，它的作用域默认是整个程序，也就是所有的源文件，包括 .c 和 .h 文件
int sum(int x,int y) {
    /*
     * 在函数定义中出现的参数可以看做是一个占位符，它没有数据，只能等到函数被调用时接收传递进来的数据，所以称为形式参数，简称形参。
     * 函数被调用时给出的参数包含了实实在在的数据，会被函数内部的代码使用，所以称为实际参数，简称实参。
     * 形参变量只有在函数被调用时才会分配内存，调用结束后，立刻释放内存，所以形参变量只有在函数内部有效，不能在函数外部使用。
     *实参和形参在数量上、类型上、顺序上必须严格一致，否则会发生“类型不匹配”的错误.
     * */
    int res = 0;
    for (int i = x; i < y+1; ++i) {
        res += i;
    }
    return res;
}


void prime(int n) {
    int is_prime = 1;
    //  return 语句是提前结束函数的唯一办法
    if (n < 0) {
        printf("%d is a illegal number.",n);
        return;
    }

    for (int i = 2; i < n; ++i) {
        if (n % i == 0) {
            is_prime = 0;
            break;
        }
    }
    if (is_prime) {
        printf("%d is a prime number.",n);
    } else {
        printf("%d is not a prime number.",n);
    }
}

long long factorial(int n) {
    if (n == 2) return 2;
    return n * factorial(n-1);
}

void func1() {
    /*
     * 变量的使用遵循就近原则，如果在当前作用域中存在同名变量，就不会向更大的作用域中去寻找变量。
     * */
    int n = 20;
    printf("func1 is %d\n",n);
}

void func2(int n) {
    printf("func2 is %d\n",n);
}

void func3() {
    printf("func3 is %d\n",n);
}

void localOrGlobal() {
    int n = 30;
    func1();
    func2(n);
    func3();
    {
        //  C语言允许在代码块 { } 内部定义变量，这样的变量具有块级作用域；
        //  换句话说，在代码块内部定义的变量只能在代码块内部使用，出了代码块就无效了。
        int n = 40;
        printf("localOrGlobal block is %d\n",n);
    }
    /*
     * 每个C语言程序都包含了多个作用域，不同的作用域中可以出现同名的变量，
     * C语言会按照从小到大的顺序、一层一层地去父级作用域中查找变量，如果在最顶层的全局作用域中还未找到这个变量，那么就会报错。*/
    printf("Main is %d\n",n);
}

int main() {
    int x = 1232;
    int y = 192388;
    printf("%d", gcd2(x,y));
    return 0;
}

int max(int x, int y) {
    return x > y ? x : y;
}

int gcd(int x, int y) {
    if (x < y) {
        int temp1 = x;  //  块级变量1
        int x = y;
        int y = temp1;
    }
    while (y != 0) {
        int temp2 = y;  //  块级变量2
        y = x % y;
        x = temp2;

    }
    return x;
}

int gcd2(int x,int y) {
    if (y == 0) return x;
    return gcd2(y,x % y);
}
