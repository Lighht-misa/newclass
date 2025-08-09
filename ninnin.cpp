#include <iostream>

int main(){
    for(int i =1;i!=10;++i)
    {
        for(int j = i;j != 10;++j)
        {
            std::cout<< i <<"X"<< j << "="<<i * j<<"\t";
        }
        std::cout<<"\n";
    }

    for (int i = 1; i <= 9; ++i) {
        // 内层循环控制列数
        for (int j = 1; j <= 9; ++j) {
            std::cout << i << "x" << j << "=" << i * j << "\t";
        }
        std::cout << std::endl; // 每行结束后换行
    }
}