#include <stdio.h>

int normalx;//  默认是0

void ifelse() {
    int max,a,b;
    scanf("%d %d",&a,&b);
    //  当语句只有一条时，可以不使用花括号{}
    if (a > b) max = a;
    else max = b;
    printf("max = %d\n",max);
    int score;
    scanf("%d",&score);
    //  当语句有多条的时候，必须使用花括号{}
    if (score >= 90) {
        printf("Excellent");
        printf("\n");
    } else if (score >= 80) {
        printf("Middle ");
        printf("\n");
    } else if (score >= 70) {
        printf("Pass ");
        printf("\n");
    } else {
        printf("Failed");
        printf("\n");
    }
}

void specialIfElse() {
    //  if 语句的判断条件中不是必须要包含关系运算符，它可以是赋值表达式，甚至也可以是一个变量，例如：
    //  C语言没有boolean数据类型 0代表false 非0代表true
    //  只声明，但是没有赋值的整型，默认是0
    int valve = 10;
    if (valve) {
        printf("valve is not 0\n");
    } else {
        printf("value is 0\n");
    }
    int valve2;
    if (valve2 = 1) {
        printf("valve2 is not 0\n");
    } else {
        printf("valve2 = %d\n",valve2);
        printf("valve2 is 0\n");
    }
    printf("%d\n",normalx);
}

void logicalOperation() {
    //  赋值运算符(=) < 逻辑运算符【&&和||】 < 关系运算符 < 算术运算符 < 非(!)
    int i,j,k;
    double x,y;
    char c;
    i = 1;
    j = 2;
    k = 3;
    x = 3e+5;
    y = 0.75;
    c = 'a';
    //  逻辑运算符和非(!)  把非0数字转成 0    把0转成1
    printf("%d %d\n", !i * !j, !!!i);
    printf("%d %d\n", x || i && j - 3, i < j && x < y);
    printf("%d %d\n", i == 1 && c && (j=8), x + y || i + j + k);
}

void switchCase() {
    int day;
    printf("Please input a day:\n");
    scanf("%d",&day);
    /*
     * switch(表达式){
    case 整型数值1: 语句 1;
    case 整型数值2: 语句 2;
    ......
    case 整型数值n: 语句 n;
    default: 语句 n+1;
    }
     */
    switch (day) {
        //  必须加上break，否则就算匹配上了相应语句，不会停止而是继续运行接下来的语句。
        case 1:
            printf("Monday\n"); break;
        case 2:
            printf("Tuesday\n");break;
        case 3:
            printf("Wednesday\n");break;
        case 4:
            printf("Thursday\n"); break;
        case 5:
            printf("Friday\n"); break;
        case 6:
            printf("Saturday\n"); break;
        case 7:
            printf("Sunday\n"); break;
        default:
            printf("error\n"); break;
    }
}

void threeOperation() {
    int a,b,max;
    scanf("%d %d",&a,&b);
    //  ? 前面为真 则输出 : 前面的变量 否则输出后面的变量
    max = a > b ? a : b;
    printf("The maximum is %d\n",max);
    //  嵌套使用 三目运算符
    int c,d;
    scanf("%d %d", &c, &d);
    //  等价于 a > b ? a : (c > d ? c : d)
    int num = a > b ? a : c > d ? c : d;
    printf("%d\n", num);
}

void loop() {
    int i = 1,sum = 0;
    //  先执行 再判断循环条件
    do {
        sum += i;
        i++;
    } while (i <= 100);
    printf("%d\n",sum);

    int j = 1,total = 0;
    while (j <= 100) {
        total += j;
        j++;
    }
    printf("%d\n",total);

    int goss = 0;
    for (int k = 0; k < 101; ++k) {
        goss += k;
    }
    printf("%d\n",goss);

    int s = 0;
    //  省略两个表达式
    for (; s <= 10;) {
        printf("%d\t",s++);
    }
    printf("\n");
    int m,n;
    for (m = 0, n = 1; n < 101; n++) {
        m += n;
    }
    printf("%d\n",m);
    char c;
    for( ; (c=getchar())!='\n' ; ) {
        printf("%c",c);
    }
}

int main() {
    loop();
    return 0;
}

