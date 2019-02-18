# C 语言 extern 关键字使用
---
### 常见用法

1. 修饰变量
   举例来说，如果文件a.c需要引用b.c中变量int v，就可以在a.c中声明extern int v，然后就可以引用变量v。能够被其他模块以extern修饰符引用到的变量通常是全局变量。还有很重要的一点是，extern int v可以放在a.c中的任何地方，比如你可以在a.c中的函数fun定义的开头处声明extern int v，然后就可以引用到变量v了，只不过这样只能在函数fun作用域中引用v罢了，这还是变量作用域的问题。对于这一点来说，很多人使用的时候都心存顾虑。好像extern声明只能用于文件作用域似的
  （apue中提到的是出错处理的变量） 
2. 修饰方法
   extern修饰函数声明。从本质上来讲，变量和函数没有区别。函数名是指向函数二进制块开头处的指针。如果文件a.c需要引用b.c中的函数，比如在b.c中原型是int fun(int mu)，那么就可以在a.c中声明extern int fun（int mu），然后就能使用fun来做任何事情。就像变量的声明一样，extern int fun（int mu）可以放在a.c中任何地方，而不一定非要放在a.c的文件作用域的范围中。对其他模块中函数的引用，最常用的方法是包含这些函数声明的头文件。 
   使用extern和包含头文件来引用函数有什么区别呢？extern的引用方式比包含头文件要简洁得多！extern的使用方法是直接了当的，想引用哪个函数就用extern声明哪个函数。这大概是KISS原则的一种体现吧！这样做的一个明显的好处是，会加速程序的编译（确切的说是预处理）的过程，节省时间。在大型C程序编译过程中，这种差异是非常明显的
   
### 举例说明

a.c
```$xslt
#include <stdio.h> 
int i = 3; 
int p(void) { 
    printf("%d\n",i);     
    return 0;      
 }
```   

b.c 
```$xslt
#include <stdlib.h> 
extern int p(void); 
extern int i; 
int main() { 
    p(); 
    system("pause");     
    return 0;      
}

```