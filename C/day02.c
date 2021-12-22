#include <stdio.h>

/*
 * 运算操作*/
void operation() {
    int ff = 0;
    int gg = 0;
    int oo = 1;
    int x = 10;
    int y = 100;
    //  三目运算符是从右向左计算的
    //  加号的运算优先级比三目运算符高
    int a = 1 + ff | gg ? x + 9 : y + 99;
    int b = ff  | gg ? x : y;
    int c = 1 + (ff | gg ? x : y);
    printf("a=%d\tb=%d\tc=%d\n",a,b,c);
    //  && 和 || 从左到右运算
    if (ff && gg || oo) {
        printf("true\n");
    } else{
        printf("false\n");
    }
    //  先运算 1 << 2 = 4 再与10做或运算 = 14
    printf("e=%d\n",10 | 1 << 2);
}

void transform() {
    //  自动数据类型转换
    double Pi = 3.1415926;
    int s1;
    int r = 5;
    double s2;
    //  左边Doule类型进行运算，但因为s1是int型，所以最后强制转换为int，丢掉小数部分。
    s1 = r * r * Pi;
    s2 = r * r * Pi;
    printf("s1=%d s2=%f\n",s1,s2);
    //  手动数据类型转换
    int sum = 103;
    int count = 7;
    int average1 = sum / count;
    double average2 = (double) sum / count;
    //  如果不使用强制类型转换的话,会发现，小数被提前丢掉了，只能接收整数部分，然后再赋值给double类型的average3
    double average3 = sum / count;
    printf("average1=%d\taverage2=%f\taverange3=%f",average1,average2,average3);
}

void arrayLength() {
    int arr[5] = {0,1,2,3,4};
    //  sizeof获取的是数组的总长度，除以元素的长度，等于个数
    int n = sizeof arr / sizeof arr[0];
    printf("%d\n",n);
    for (int i = 0; i < n; ++i) {
        printf("%d\n",arr[i]);
    }
    printf("finish");
}

void printMore() {
    //  puts()  putchar()   printf()
    int a1=-22, a2=345, a3=777, a4=888;
    //  d表示十进制输出，- 表示左对齐 不加 - 默认右对齐 9 表示 最少占9个字符的宽度，宽度不足以空格补齐
    //  + 表示输出符号（正负号）
    printf("%-9d%-9d%-9d%-9d\n",a1,a2,a3,a4);
    printf("%+9d%9d%9d%9d\n",a1,a2,a3,a4);
    //  用于整数时，.precision 表示最小输出宽度。与 width 不同的是，整数的宽度不足时会在左边补 0，而不是补空格。
    printf("%.9d%.9d%.9d%.9d\n",a1,a2,a3,a4);
    //  用于字符串时，.precision 表示最大输出宽度，或者说截取字符串。
    //  当字符串的长度大于 precision 时，会截掉多余的字符；当字符串的长度小于 precision 时，.precision 就不再起作用。
    char *str = "abcde";
    printf("str: %.4s\n",str);
    printf("str: %.6s\n",str);
}

void input() {
    /*
     * scanf()：和 printf() 类似，scanf() 可以输入多种类型的数据。
     * getchar()、getche()、getch()：这三个函数都用于输入单个字符。
     * gets()：获取一行数据，并作为字符串处理。
     */
    //  &称为取地址符，即获取变量在内存中的地址。
    int a,b,c,d;//  int a 表示 在内存中分配四个字节的空间给变量a
    /*
     * 从本质上讲，我们从键盘输入的数据并没有直接交给 scanf()，而是放入了缓冲区中，直到我们按下回车键，scanf() 才到缓冲区中读取数据。
     * 如果缓冲区中的数据符合 scanf() 的要求，那么就读取结束；如果不符合要求，那么就继续等待用户输入，或者干脆读取失败。
     * 因此连续输入数据，scanf是可以识别的，下面有2个scanf函数，既可以分两次输入，也可以一次性输入。
     * */
    scanf("%d %d",&a,&b);
    printf("%d %d\n",a,b);
    //  %p  表示以十六进制的形式（带小写的前缀）输出数据的地址
    printf("a 's address in memory is %p\nb 's address in memory is %p\n",&a,&b);
    scanf("%d %d",&c,&d);
    printf("%d %d\n",c,d);

    //  getchar()	有缓冲区	头文件stdio.h	有回显	适用于Windows、Linux、Mac OS 等所有平台
    //  getche()    getch() 没有缓冲区
}



int main() {
    input();
    return 0;
}

