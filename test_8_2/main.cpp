#include <iostream>
#include <cstdlib>

/*
// 1. 正常的命名空间定义
namespace bin
{

    int rand = 10;
    int Add(int left, int right)
    {
    return left + right;
    } 

    struct Node
    {
        struct Node* next;
        int val;
    };

}


int main()
{
// 这⾥默认是访问的是全局的rand函数指针
printf("%p\n", rand);
// 这⾥指定bit命名空间中的rand
printf("%d\n", bin::rand);
return 0;
}*/

/*
// 2. 命名空间可以嵌套
namespace wu
{

    namespace bin
    {
        int rand = 12;
        int Add(int left, int right)
        {
        return left + right;
        } 
    }
    

        namespace san
    {
        int rand = 16;
        int Add(int left, int right)
        {
        return (left + right)*2;
        } 
    }

}

int main()
{
    printf("%d\n", wu::bin::rand);
    printf("%d\n", wu::san::rand);
    printf("%d\n", wu::bin::Add(1, 2));
    printf("%d\n", wu::san::Add(1, 2));

    return 0;
}*/

// 多⽂件中可以定义同名namespace，他们会默认合并到⼀起，就像同⼀个namespace⼀样

/*namespace gege
{
    int a = 2;
    int b = 13; 
}

 //using将命名空间中某个成员展开
  using gege::a;

int main()
{
    //编译报错：error C2065: “a”: 未声明的标识符
    //printf("%d\n", a);

    // 指定命名空间访问
    //printf("%d\n",gege::b);

    std::cout<< a;
    
    return 0;
}*/


namespace gege
{
    int a = 2;
    int b = 13; 
}

// 展开命名空间中全部成员
using namespace gege;

int main()
{
    std::cout<<a<<" "<<b;
    return 0;
}