#include <iostream>
#include "LogSystem.h" 
int main(){
    try{
Looger looger("log.txt");
    looger.log("Starting application...");
    int uer_id = 41;
    std::string action = "login";
    double duration = 3.1;
    std::string world = world;
    looger.log("User {} performed {} in {} second ",uer_id,action,duration);
    
    }catch(const std::exception &e){
        std::cerr << "Erro is "<<e.what()<<"\n";

    }
    return 0;
}