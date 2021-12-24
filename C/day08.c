#include <stdio.h>
#include <string.h>

/*
 * 二级指针、三级指针
 * 指针数组（数组每个元素都是指针）
 * 二维数组指针（指向二维数组的指针）
 * 函数指针（指向函数的指针）
 * */

void multiPointer() {
    int a = 100;
    /*
     *  指针变量也是一种变量，也会占用存储空间，也可以使用&获取它的地址。
     *  C语言不限制指针的级数，每增加一级指针，在定义指针变量时就得增加一个星号*
     *  记忆：二级指针是指向一级指针的指针，（高等数学）二阶导数是一阶导数的导数
     * */
    int *p1 = &a;
    int **p2 = &p1;
    int ***p3 = &p2;
    printf("a = %d p1 = %d p2 = %d p3 = %d", a, *p1, **p2, ***p3);
}

void pointerArray() {
    //  如果一个数组中的所有元素保存的都是指针，那么我们就称它为指针数组
    int a = 10;
    int b = 20;
    int c = 30;
    int *arr[] = {&a,&b,&c};
    int **parr = arr;   //  因为数组名可以隐式转换为指针，所以不需要加&
    int n = sizeof(arr) / sizeof(int *);

    for (int i = 0; i < n; ++i) {
        //  这三者等价
        printf("%d ",*(arr[i]));
        printf("%d ",**(arr+i));
        printf("%d ",**(parr+i));
    }
    puts("");
    //  指针数组还可以和字符串数组结合使用
    //  字符数组 str 中存放的是字符串的首地址，不是字符串本身，字符串本身位于其他的内存区域，和字符数组是分开的
    //  所以给数组赋值时，只能将字符指针赋值给指针数组
    char *str[3] = {
            "Welcome",
            "to",
            "SZPT"
    };
    int len = sizeof(str) / sizeof(char *);
    for (int i = 0; i < len; ++i) {
        printf("%s ",str[i]);
    }
    puts("");
    char str1[] = "Hello ";
    char str2[] = "World!";
    //  char *str1 = "Hello ";
    //  char *str2 = "World";
    char *string[] = {str1,str2};
    printf("%s %s",string[0],string[1]);
}

void twoDArray() {
    int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int (*p)[3] = a;    //  意思是 先创建一个指针，该指针指向一个大小为3的数组
    //  int *p[3] 等价于 int *(p[3]) 意思是 先创建一个数组，数组中每个元素是int类型的指针
    //  它指向二维数组的第一个元素，第一个元素是长度为3的一维数组
    printf("%d\n",sizeof(*(p+1)));  //  3 * 4 = 12
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            //  *(p+i)  代表第i行   （从0开始）
            //  *(p+i) + j 代表第i行的第j个元素 （从0开始）
            printf("%d ",*(*(p+i)+j));
        }
        puts("");
    }
}

int max(int x, int y) {
    return x > y ? x : y;
}
void funcPointer() {
    /*
     * 一个函数总是占用一段连续的内存区域，函数名在表达式中有时也会被转换为函数所在内存区域的首地址，这和数组名非常类似。
     * 我们可以把函数的这个首地址（或称入口地址）赋予一个指针变量，使指针变量指向函数所在的内存区域，然后通过指针变量就可以找到并调用该函数。
     * */
    int x,y,maxval;
    //  必须要加括号 否则非法
    int (*pmax)(int ,int ) = max;
    printf("Input tow numbers:\n");
    scanf("%d %d",&x,&y);
    maxval = (*pmax)(x,y);
    printf("Max value is %d", maxval);
}

int main() {
    int a = 100;
    int *p = &a;
    printf("%d",*p);
    return 0;
}

