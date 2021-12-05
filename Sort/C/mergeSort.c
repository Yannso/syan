#include <stdio.h>

void print() {
    int a = 1;
    float b = 20.21;
    char c = 'c';
    //  打印各种不同数据类型的变量
    printf("a=%d\nb=%f\nc=%c", a, b, c);
    //  多行打印
    printf("bysbysbysbysbysbys"
           "hqhqhqhqhqhqhqhq"
           "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"
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
    
}

int main() {
    rangeAndLength();
    return 0;
}
