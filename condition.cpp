#include <iostream>
#include <stdexcept>


double divide(double num, double benum){
    if( num == 0 && benum ==0)
    {
        throw std::invalid_argument("分母或者分子不能为0\n");
    }
    return num / benum;
}
int main(){
    int num= 0;
    for(int i =0;i!=10;i++)
    {
        if(i == 5)
        {
            //结束当前循环
            break;
        }
        std::cout<<i;
    }
    std::cout<<std::endl;

    for(int i =0;i != 10;i++)
    {
        if ( i % 2 == 0)
        {
            ///跳过当前循环
            continue;
        }
        std::cout<<i<<" ";
    }


    std::cout<<"Please entered two numbers\n";
    int num1,num2;
    std::cin>>num1>>num2;
    
    try{
    double resule = divide(num1,num2);
    }catch(std::invalid_argument &e){
        std::cerr<<"Error "<<e.what();
    }

}