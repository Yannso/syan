#include <stdio.h>
#include <string.h>

void stringArray() {
    /*  day04
     * C语言没有特定的字符串类型，通常是将字符串放在一个字符数组中
     * 将字符串直接赋值给字符数组时，C语言会自动在数组末尾添加一个'\0'代表结束
     * 逐个字符地给数组赋值时，不会自动添加 '\0'，因此需要手动添加'\0'来表示结束
     * 果不加'\0'的话，C语言将会一直读取内存的数据，直到遇到'\0'为止
     * */
    char str[] = "Bu Yansong";
    int len = strlen(str);
    //  直接打印字符串
    printf("%s\n", str);
    //  循环遍历打印字符串
    for (int i = 0; i < len; ++i) {
        printf("%c", str[i]);
    }
    puts("");
}

void printStringArray() {
    char str[] = "Bu Yansong";
    //  字符串数组也是数组的一种，因此指针和普通数组的规则也同样适用于字符数组
    char *pstr = &str;
    int len = strlen(str);
    puts("*(pstr+i):");
    for (int i = 0; i < len; ++i) {
        printf("%c", *(pstr + i));
    }
    puts("");
    puts("str[i]:");
    for (int i = 0; i < len; ++i) {
        printf("%c", str[i]);
    }
    puts("");
    puts("*(arr+i):");
    for (int i = 0; i < len; ++i) {
        printf("%c", *(str + i));
    }
    puts("");
    puts("*pstr++:");
    for (int i = 0; i < len; ++i) {
        printf("%c", *pstr++);
    }
    puts("");
}

void pointerString() {
    /*
     * 除了字符数组，C语言还支持直接使用一个指针指向字符串
     * 字符串中的所有字符在内存中是连续排列的，str 指向的是字符串的第0个字符；
     * 我们通常将第 0 个字符的地址称为字符串的首地址
     * */
    char *str = "Welcome to SZPT";
    char str1[] = "Bu Yansong";
    int len = strlen(str);
    printf("pointer 's address is %#X \nstring 's address is %#X\t", &str, str);
    puts("");
    printf("%s\n", str);
    for (int i = 0; i < len; ++i) {
        printf("%c", *(str + i));
    }
    puts("");

    for (int i = 0; i < len; ++i) {
        printf("%c", str[i]);
    }
    puts("");

    /*
     * 字符数组存储在全局数据区或栈区，指针指向的字符串存储在存储在常量区
     * 全局数据区或栈区的字符串可访问可修改，而常量区的字符串可访问但不可修改
     * 往往把指针指向的字符串成为字符串常量。
     * 具体使用 字符数组  还是  指针指向的字符串  视具体情况而定
     * */
    str1[0] = 'P';
    puts(str1); //  字符数组被修改

    char inputStr[30] = {0};
    gets(inputStr);
    puts(inputStr);
    int len1 = sizeof(inputStr);
    int len2 = strlen(inputStr);
    printf("%d, %d", len1, len2);
}
void swap(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

void swapPointer(int *p1, int *p2) {
    /*
     *  此处需要注意的一个点：指针本身没有交换，而指针指向的数据交换
     *  那么为什么不是交换指针，而是交换指针指向的数据呢？
     *  一个变量一旦被初始化后，它就在内存中分配了一个地址，并且这个地址无法再被更改，于是交换指针并不会更改原有数据
     *  如果是交换指针指向的数据，地址没变，地址存储的数据被交换了
     * */
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    //  函数运行完之后，局部作用域的变量将会被销毁
}

void pointerAsFuncParament() {
    /*
     *  像数字，字符char等数据类型作为参数传递给函数时，其实是对该数据进行了复制，函数内的对该变量运算结果不会影响函数外该变量原本的数值
     *  而像数组、字符串、动态分配的内存等都是一系列数据的集合，没有办法通过一个参数全部传入函数内部，只能传递它们的指针，在函数内部通过指针来影响这些数据集合。
     * */
    int x = 100;    //  一个变量一旦被初始化后，其被分配在内存的地址就固定了，无法再更改
    int y = 200;
    //  将普通变量传入函数，函数内的运算结果不会影响函数外原来的变量值
    swap(x,y);
    printf("Use variable--- x: %d y: %d\n",x,y);
    //  若将指针传入函数，则可以改变
    int *p1 = &x;
    int *p2 = &y;
    swapPointer(p1,p2);     //  传入的是指针，而不是指针指向的数值   如果是后者则应该传入 &p1 &p2
    printf("Use pointer--- x= %d y= %d\n",x,y);
}

int max(int *p, int n) {
    //  因为传入的是指针，无法通过这个指针获得数组长度，无法通过这个指针获得数组长度
    int maxVal = *p;    //  maxVal = p[0]
    for (int i = 1; i < n; ++i) {
        if (maxVal < p[i]) {
            //  p[i] = *(p+i)
            maxVal = p[i];
        }
    }
    return maxVal;
}

int max2(int arr[], int n) {
    //  虽然看起来传入的是数组，但其实传入的是指针，无法计算其数组大小
    int nn = sizeof(arr) / sizeof(int);
    printf("%d\n",nn);
    int maxVal = arr[0];    //  maxVal = p[0]
    for (int i = 1; i < n; ++i) {
        if (maxVal < arr[i]) {
            //  p[i] = *(p+i)
            maxVal = arr[i];
        }
    }
    return maxVal;
}


void pointerParament1() {
    int nums[] = {20,-2,5,-7,88,22,29};
    int len = sizeof(nums) / sizeof(int);
    //  将数组传入给函数时，必须再传递其长度
    int maxNum1 = max(nums,len);
    int maxNum2 = max2(nums,len);
    printf("The array climax is %d and %d\n",maxNum1,maxNum2);
}

char *strlong(char *str1, char *str2) {
    //  printf("%c\n",*str1);   //  指向开头
    //  printf("%s\n",str1);    //  代表整个字符串
    return strlen(str1) >= strlen(str2) ? str1 : str2;
}

int *func() {
    /*
     * 函数结束调用后，会销毁所有局部作用域的变量、数组等数据
     * 这里所谓的销毁并不是将局部数据所占用的内存全部抹掉，而是程序放弃对它的使用权限，弃之不理，后面的代码可以随意使用这块内存。
     * 函数返回的指针请尽量不要指向这些数据，C语言没有任何机制来保证这些数据会一直有效，
     * 它们在后续使用过程中可能会引发运行时错误。下面这个例子就是错误的
     * */
    int n = 100;
    return &n;
}
int main() {

}

