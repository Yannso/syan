#include <stdio.h>
#include <string.h>

/*
 * 指针(pointer)   http://c.biancheng.net/view/1991.html
 * 需要注意的是，虽然变量名、函数名、字符串名和数组名在本质上是一样的，它们都是地址的助记符，
 * 但在编写代码的过程中，我们认为变量名表示的是数据本身，而函数名、字符串名和数组名表示的是代码块或数据块的首地址。
 * */

void outputAddress() {
    int a = 100;
    char str[20] = "Bu YanSong";    //  str变量本生就代表字符串的首地址，取地址时，不需要加&
    //  内存地址一般使用十六进制表示，%#X表示以十六进制形式输出，并附带前缀0X  【如果不带# 就不会附带前缀0X】
    printf("a 's address in memory is %#X and str is %#X\n", &a, str);
}

void pointer() {
    int *p_a;   //  表明该变量是一个指针变量
    int a = 15;    //  普通变量，数据类型是int
    p_a = &a;   //  指针变量指向普通变量的地址，所以是&a。该指针的数据类型不是int，而是int*
    //  打印变量a的地址和变量a的值
    printf("The address of variable a is %#X and the value of variable is %d\n", &a, a);
    //  打印指针变量p_a的地址和指针变量p_a的值      ->  发现p_a的值是变量a的地址
    printf("The address of pointer p1 is %#X and the value of pointer is %#X\n", &p_a, p_a);
    //  指针变量只是存储了数据的地址！如果想获取其内容，必须加上*，例如 *p_a
    printf("The address of variable a is %#X and the value of variable is %d\n", &*p_a, *p_a);

    //  指针除了可以获取内存上的数据，也可以修改内存上的数据，例如：
    int x = 15, y = 99, z = 120;
    int *p = &a;
    printf("*p = %d\n", *p);
    //  此处代表的意思是，为指针变量p指向的变量x赋值，而不是给指针变量p本身赋值
    *p = y;
    printf("*p = %d\n", *p);
    z = *p;
    printf("%d %d %d %d\n", x, y, z, *p);
    int *p2;
    p2 = &x;    //  此处是不加*的，因为这是在为指针变量p2本身赋值，且赋值的是一个地址。
    printf("%d\n", *p2);
}

void swap() {
    int x = 10, y = 20;
    int *p1 = &x, *p2 = &y;
    printf("*p1 = %d *p2 = %d\n", *p1, *p2);
    int *temp = p1; //  指针变量给指针变量赋值不需要*
    //  这与上面等价int *temp = &*p1;
    p1 = p2;
    p2 = temp;
    puts("Have swap p1 and p2:");
    printf("*p1 = %d *p2 = %d\n", *p1, *p2);
    printf("x = %d y = %d\n", x, y);
}

void pointerOperate() {
    int a = 10;
    double b = 20;
    char c = 'c';
    int *pa = &a;
    double *pb = &b;
    char *pc = &c;
    //  original data a b c
    printf("&a=%#X, &b=%#X, &c=%#X\n", &a, &b, &c);
    //  the pointer of a b c
    printf("pa=%#X, pb=%#X, pc=%#X\n", pa, pb, pc);
    pa++;
    pb++;
    pc++;
    //  increase pointer a and pointer b
    printf("pa=%#X, pb=%#X, pc=%#X\n", pa, pb, pc);
    //  可以发现指针pa、pb、pc不是真的加了1，而是加了4、8、1，正好对应int、double、char数据类型的长度
    //  数组中的所有元素在内存中是连续排列的，如果一个指针指向了数组中的某个元素，那么加 1 就表示指向下一个元素，减 1 就表示指向上一个元素

}

void arrayPointer() {
    /*
     * 数组（Array）是一系列具有相同类型的数据的集合，每一份数据叫做一个数组元素（Element）
     * 数组中的所有元素在内存中是连续排列的，整个数组占用的是一块内存
     * 定义数组时，要给出数组名和数组长度，数组名可以认为是一个指针（但不完全是一个指针），它指向数组的第 0 个元素。
     * 在C语言中，我们将第 0 个元素的地址称为数组的首地址。指针不等价于数组名，见下面这个这个函数
     *
     * */
    int arr[] = {99, 15, 100, 892, 252};
    int len = sizeof(arr) / sizeof(int);
    //  这两种获取数组元素方法等价
    for (int i = 0; i < len; ++i) {
        printf("%d\t", arr[i]);
    }
    puts("");
    for (int i = 0; i < len; ++i) {
        printf("%d\t", *(arr + i));
    }
    puts("");
    int *p = arr;
    //  int *p = &arr[0]
    //  arr p &arr[0] 这三者都等价 都指向了数组开头，第0个元素
    for (int i = 0; i < len; ++i) {
        printf("%d\t", *(p + i));
    }
    puts("");
    //  使用指针来遍历数组
    for (int i = 0; i < len; ++i) {
        //  注意  *p++ 等价于 *(p++)     先对指针p取地址获得指向的值，指针p再自加
        //  （*p）++  先取指针p指向的值，指向的值再自加，
        printf("%d \t",*p++);
    }
    puts("");
    int a = 99;
    int *ap = &a;
    printf("%d\n",++(*ap));

}

void differenceOfArrayAndPointer() {
    /*
     * https://blog.csdn.net/qq_17200837/article/details/82860219
     * 指针和数组名字的区别
     * 第一，数组名作为一种特殊的指针，它不能改写，诸如a++，这样都是非法的；然而指针变量是可以改写的
     * 第二，使用sizeof获得大小，两者并不一致。
     *      例如，a数组的大小是3*4 = 12个字节大小，因为该数组有3个整型元素，1个整型元素占4个字节。而p指针，求得的是p指针变量本身的字节数
     * 第三，“数组类型”的对象虽然不完全是指针，但是可以隐式转化为指针
     * */
    int a[] = {1, 2, 3, 4, 5};
    int *p = a;
    printf("%#X %#X\n", &a[0], p);    //  指向的地址相同
    //  p += 3; //  指针可以改写   而数组名不可以改写
    //  显然，a数组名和p指针的大小不同，所代表的含义也不同
    int a_N = sizeof(a);
    int p_N = sizeof(p);
    printf("arrayName a size is %d pointer p size is %d\n", a_N, p_N);
    //  事实上还可以将数组中某一个元素地址赋值给指针
    //  等价于 int *pp = &a[2];
    int *pp = a + 2;
    printf("%d %d %d %d %d\n", *(pp - 2), *(pp - 1), *(pp), *(pp + 1), *(pp + 2));
    int *ppp = pp - 1;
    printf("%d\n", *ppp);
}

int main() {
    arrayPointer();
    return 0;
}
