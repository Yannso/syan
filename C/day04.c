#include <stdio.h>
#include <string.h>
#include <ctype.h>

void createArray(){
    /*
     * 数组初始化时，如果给全部元素赋值，那么在定义数组时可以不给出数组长度，大小将会自动推算
     * 可以只给部分元素赋值。当{ }中值的个数少于元素个数时，只给前面部分元素赋值，而后面的元素会自动赋值为0
     * 只能逐个赋值，而不能整体赋值。
     * 如果指定的数组大小 大于 输入字符串的大小，也能够存储成功
     * 但如果指定的数组大小 小于 输入字符串的大小，有时候也可以存储成功，但是字符串写入字符数组可能会溢出。
     * */
    int arr[10] = {1};
    for (int i = 0; i < 10; ++i) {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    int arr2[5];
    for (int i = 0; i < 5; ++i) {
        //  scanf() 读取数据时需要一个地址（地址用来指明数据的存储位置），而 nums[i] 表示一个具体的数组元素
        //  所以需要加上&
        scanf("%d",&arr2[i]);
    }
    for (int i = 0; i < 5; ++i) {
        printf("%d\t",arr2[i]);
    }
    printf("\n");
    /*
     * 二维数组的初始化可以按行分段赋值，也可按行连续赋值。
     * 可以只对部分元素赋值，未赋值的元素自动取“零”值
     * 如果对全部元素赋值，那么第一维的长度可以不给出
    */
    int grid[1][3] = {{1,2,3}};
    int grid2[2][2] = {1,1,2,2};
    int grid3[3][3] = {{1},{2},{3}};
    int grid4[][3] = {1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d\t",grid3[i][j]);
        }
        printf("\n");
    }
}

void charArray() {
    /*
     * 在C语言中，没有专门的字符串变量，没有string类型，通常就用一个字符数组来存放一个字符串。
     * C语言规定，可以将字符串直接赋值给字符数组*/
    char string[] = "Bu Yansong";
    //  等价于 char string[] = {"Bu Yansong"};
    //  因为string在初始化时，末尾是有'\0'的，因此使用sizeof 表达式 得出数组大小为11，如果使用strlen函数 得出数组大小为10
    printf("%s size is %d \n",string, strlen(string));
    /*
     * string2 = "abcde";  会报错
     * 字符数组只有在定义时才能将整个字符串一次性地赋值给它，一旦定义完了，就只能一个字符一个字符地赋值了
     * 【大坑】
     * 将字符串直接赋值给字符数组时，C语言会自动在数组末尾添加一个'\0'代表结束
     * 逐个字符地给数组赋值时，不会自动添加 '\0'，因此需要手动添加'\0'来表示结束
     * string3为逐个赋值，但没有添加 '\0'，C语言会继续读取内存，至到读取到 '\0' 为止
     */
    char string2[6];
    string2[0] = 'a',string2[1] = 'b',string2[2] = 'c',string2[3] = 'd',string2[4] = 'e',string2[5] = '\0';
    printf("%s\n",string2);

    char string3[] = {'1','2','3','4','5'};
    printf("%s\n",string3);
    //  在很多编译器下，局部变量的初始值是随机的，是垃圾值，而不是我们通常认为的“零”值。
    //  局部数组（在函数内部定义的数组，本例中的 chars 数组就是在 charArray() 函数内部定义的）也有这个问题，
    //  很多编译器并不会把局部数组的内存都初始化为“零”值，而是放任不管，爱是什么就是什么，所以它们的值也是没有意义的，也是垃圾值。
    char chars[30];
    //  chars数组在定义完成以后并没有立即初始化，所以它所包含的元素的值都是随机的。
    //  循环结束以后，chars 的前 26 个元素被赋值了，剩下的 4 个元素的值依然是随机的，不知道是什么。
    for (int c = 65; c <= 90 ; ++c) {
        chars[c-65] = c;
    }
    printf("there are 4 redundant chars: %s\n",chars);
    //  为了避免手动加'\0'的方式，最好的办法是，为chars数组初始化为0。因为根据 ASCII 码表，字符'\0'的编码值就是 0。
    char chars2[30] = {0};
    for (int c = 65; c <= 90 ; ++c) {
        chars2[c-65] = c;
    }
    printf("there are only 24 chars: %s\n",chars2);
}

void inputOutputArray() {
    char * s = "Bu Yansong";
    puts(s);    //  自动换行
    /*
     * scanf()：通过格式控制符%s输入字符串。读取字符串时以空格为分隔
     * gets()：直接输入字符串，并且只能输入字符串。读取字符串时以换行为分隔
     * */
    char str1[30] = {0};
    printf("input a string:\n");
    gets(str1);
    printf("%s\n",str1);

    char str2[5] = {0};
    //  赋值内容给字符数组时不需要加取地址符，因为字符串名字或者数组名字在使用的过程中一般都会转换为地址
    scanf("%s",str2);
    //  int n = sizeof(str2);   获取字符数组大小，而不是字符串大小，因为字符数组中的字符可能没有全部占满
    int n = strlen(str2);// 虽然开辟了5个位置大小的字符数组，但实际上有效字符串只有3
    printf("%s 's size is %d\n",str2,n);
}

void charOperate() {
    char str1[100] = "My name's ";
    char str2[100] = {0};
    printf("input your name\n");
    gets(str2);
    //  strcat字符串拼接
    strcat(str1,str2);
    //  strncat字符串拼接n个字符
    strncat(str1,str2,2);
    puts(str1);
    //  strcopy字符串复制    dest,source
    strcpy(str1,str2);
    puts(str1);
    char str3[] = "abcdefg";
    char str4[] = "abcdeaa";
    if (strcmp(str3,str4)) {
        printf("str3 is bigger\n");
    } else {
        printf("str4 is smaller\n");
    }
}


int main() {
    return 0;
}

