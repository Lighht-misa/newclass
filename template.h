#include<iostream>
//模板函数
template<typename T>
T Maxvalue(T a,T b){
    return (a >b)?a:b;
}
//模板类Pair
template<typename T>
class Pair{
    public:
    T first;
    T second;
    Pair(T a,T b):first(a),second(b){ }
    void print()const {
        std::cout<<"Pair: "<<first<<", "<<second<<"\n";
    }
   
}; 

//这个模板类要求传入两个参数 T在实例化的时候会进行推导，第二个参数则是智能传入正整数
    template<typename T,std::size_t N>
    class FixedArray{
        public:
        //声明了一个T类型的N大小的数组
        T data[N];

        T&operator[](std::size_t index){
            return data[index];
        }
        void print()const{
            std::cout<<"一共有"<<N<<"个元素\n";
            for(int i =0; i<N;i++)
            {
            std::cout<<"第"<<i<<"个元素为"<<data[i]<<" ";
            }
            std::cout<<"\n";
        }

    };

    template<template <typename,typename>class Container,typename T>
    class ContainerPrinter{
      public:
      void print(const Container<T,std::allocator<T>>&container)const{
        for(const auto &elem:container)
        {
            std::cout<<elem<<" ";
        }
        std::cout<<"\n";
      }  
    };