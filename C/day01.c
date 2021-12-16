#include <stdio.h>
#include <locale.h>

void print() {
    int a = 1;
    float b = 123.1;
    double c = 3147483647.1;
    double cc = 3.14e5; //  指数形式表示
    char d = 'd';
    //  构建字符串的两种方式  char 变量名[]  这样构建的方式，字符串的内容是可以可改的。（相当于Java中的char[]）
    //  []内可以不指定长度，原因是可以通过 = 后的内容自动推断数据长度。但如果只是定义一个字符串，没有赋值，就不能这么写
    char* string = "I love C program";
    char string1[] = "I really like C program";
    string1[0] = 'i';
    //  %d  十进制     %o  八进制     %x  十六进制
    //  %d  整型十进制       %hd 短整型     %ld 长整型     %lld    长长整型
    //  %c  char字符型    %f  浮点型      %s  字符串型
    printf("a=%d\n"
           "b=%f\n"
           "c=%lf\n"
           "cc=%lf\n"
           "d=%c\n"
           "string = %s\n"
           "string1 = %s\n",
           a, b, c, cc, d, string, string1
    );
}

void rangeAndLength() {
    short a = 32767;    //  short数据类型   一共占2个字节，8个位，最多表示 -32768-32767
    int b = 2147483647;    //  int数据类型   一共占4个字节，32个位，最多表示 -2147483648-2147483647
    long c = 2147483647;    //  long数据类型   一共占4个字节，32个位，最多表示 -2147483648-2147483647
    long long d = 9223372036854775807;  //  long long数据类型   一共占8个字节，64个位，最多表示 -9223372036854775808-9223372036854775807
    printf("%hd size is %d\n%d size is %d\n%ld size is %d\n%lld size is %d",
           a, sizeof(a),
           b, sizeof(b),
           c, sizeof(c),
           d, sizeof(d)
    );
}

void numeration() {
    //  二进制、八进制、十六进制
    int a = 0b101;  //  0b开头
    int b = 011;    //  0开头
    int c = 0x1a;   //  0x开头
    //  C编译器不能使用 printf 函数输出二进制
    //  在格式控制符中加上#，就可以在输出时带上特定的前缀，以便区分不同进制数字。
    printf("a=%d\n"
           "b=%o\n"
           "c=%#x\n", a, b, c
    );
}

void signedNumber() {
    //  int 可表示的数据范围是 0-30位，31位是符号位
    //  short、int 和 long 类型默认都是带符号位的
    //  unsigned表示数字不带符号位，可以表示的数字范围会更大
    int a = 10;
    short b = 20;
    long c = 2554464;
    long long d = 9223372036854775807;

    unsigned int aa = 2147483648;
    unsigned short bb = 32768;
    unsigned long cc = 2147483648;

    printf("%d size is %d\n"
           "%hd size is %d\n"
           "%ld size is %d\n"
           "%lld size is %d\n"
           "=================\n",
           a, sizeof(a),
           b, sizeof(b),
           c, sizeof(c),
           d, sizeof(d)
    );
    printf("%lld size is %d\n"
           "%lld size is %d\n"
           "%lld size is %d\n",
           aa, sizeof(aa),
           bb, sizeof(bb),
           cc, sizeof(cc)
    );
    //  运行上面结果，发现不带符号位的数字，所有的位都用来表示数值，正数的取值范围更大了
}

void printChinese() {
    setlocale(LC_ALL, "chs");
    wchar_t str[] = L"我是李华，来自加利福尼亚大学\n";
    wprintf(L"%ls",str);
    wprintf(L"%lc %lc %lc %lc",str[0],str[1],str[2],str[3]);
}

void convert() {
    //  转义字符
    //  \开头表示后跟八进制形式的编码值
    //  \x开头表示跟十六进制的编码值
    //  \n换行    \t水平制表tab   \'单引号   \"双引号   \\  反斜杠
    //  \t水平制表tab
    char a = 97;        //  97对应ASCII码的a
    char b = '\142';    //  \142 八进制 = 98
    char c = '\x63';    //  \x63 十六进制 = 99
    printf("a = %c\n"
           "b = %c\n"
           "c = %c\n",a,b,c);

    printf("b = \142\tc = \x63");
}

void identifyCode() {
    //  约束变量名称
    /*
     *   C语言规定，标识符（或者叫变量名）只能由字母（A~Z, a~z）、数字（0~9）和下划线（_）组成，
     *   并且第一个字符必须是字母或下划线，不能是数字。
     *   int 3s = 1;
     *   int -x = 2;
     *   int s#t = 3;
     *   标识符不能和关键字相同（关键字也被称成为保留字）
     *   单行注释以//开头，直到本行末尾（不能换行）；
     *   多行注释以"\/*"开头，以"*\/"结尾，注释内容可以有一行或多行。
     */
}

void operateSign() {
    //  加减乘除操作
    int a = 100;
    int b = 12;
    float c = 12.0;
    //  两int数相除，只保留整数部分，1个int和1个float相除，保留小数部分。
    double res1 = a / b;
    double res2 = a / c;
    printf("res1= %f, res2= %f\n",res1,res2);

    //  对变量本身进行某种运算
    //  a = a + b ~ a += b      同理 - * / %
    int d = 10, e = 20;
    d += e;
    e *= d;
    printf("d= %d, e= %d\n",d,e);
    //  变量的自增 a++ 或者 ++a 等价于 a = a + 1  或者  a += 1
    //  变量的自减 a-- 或者 --a 等价于 a = a - 1  或者  a -= 1
    //  ++a 表示 先自增 再进行其他操作  a++ 表示 先进行其他操作，操作完之后再自增
    //  --a 表示 先自减 再进行其他操作  a-- 表示 先进行其他操作，操作完之后再自增
    int f = 10,g = 20, h = 30, i = 40;
    int f1 = ++f;   //  先自加，再赋值
    int g1 = g++;   //  先复制，再自加
    int h1 = --h;   //  先自减，再复制
    int i1 = i--;   //  先复制，再自减
    printf("f=%d, f1=%d\n", f, f1);
    printf("g=%d, g1=%d\n", g, g1);
    printf("h=%d, h1=%d\n", h, h1);
    printf("i=%d, i1=%d\n", i, i1);

}


int main() {
    print();
    return 0;
}
