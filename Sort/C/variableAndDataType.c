#include <stdio.h>
#include <locale.h>


void print() {
    int a = 1;
    float b = 123.1;
    double c = 3147483647.1;
    double cc = 3.14e5; //  指数形式表示
    char d = 'd';
    char *string = "I love C program";
    //  %d  十进制     %o  八进制     %x  十六进制
    //  %d  整型十进制       %hd 短整型     %ld 长整型     %lld    长长整型
    //  %c  char字符型    %f  浮点型      %s  字符串型
    printf("a=%d\n"
           "b=%f\n"
           "c=%lf\n"
           "cc=%lf\n"
           "d=%c\n"
           "string = %s",
           a, b, c, cc, d, string
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

int main() {
    printChinese();
    return 0;
}
