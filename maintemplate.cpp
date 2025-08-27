#include <iostream>
#include "template.h"
#include <vector>
#include <list>
 int main(){
//     std::cout<<"This is my int type compare function :"<<Maxvalue(10,20)<<"\n";
//     std::cout<<"This is my double type compare function :"<<Maxvalue(10.21,2.20)<<"\n";
//     std::cout<<"This is my string type compare function :"<<Maxvalue("bac","abd")<<"\n";
    Pair<int> p1(10,20);
    p1.print();
    FixedArray<int,10> array;
    for(int i =0;i!=10;++i)
    {
        array[i] = i *10;
    }
    for(int i =0;i!=10;++i)
    {
        std::cout<<array[i]<<"  ";
    }
    std::cout<<"\n";
    //声明一个模板模板类类型
    ContainerPrinter<std::vector,int> vecPrinter;
    std::vector<int> v1={1,2,3,4,5,6,7,8,9,10};
    //通过调用这个类的实例化的成员函数 把函数要求的传入的容器传进去进行输出
    vecPrinter.print(v1);

    ContainerPrinter<std::list,int> listPrinter;
    std::list<int> list1={321,31322,12,321123,534};
    listPrinter.print(list1);
    return 0;
}