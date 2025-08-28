#include <iostream>
#include "templatespecial.h"
int main(){
    Printer<int> IntPrinter;
    IntPrinter.print(10);

    Printer<std::string> StringPrinter;
    StringPrinter.print("laohu will fly!!");

    Pair<int,std::string> Pair1(100,"terger will fly!");
    Pair1.print();
    double value = 10.5;
    Pair<int,double*> p2(19,&value);
    p2.print();

    printValue(100);
    printValue("tirger will fly.");

    printALL(10,20,30,102012031201,"djfis",1.212);
    printAll(10,20,30,102012031201,"djfis",1.212);
    std::cout<<sum(10,1.19,20,120)<<"\n";
    return 0;
}