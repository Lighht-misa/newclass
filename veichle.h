#include <iostream>

class veichle{
public:
    virtual void stradEnge() = 0;
};

class car:public veichle{
    public:
    void stradEnge() override{
        std::cout<<"car endingged\n";
    }
};
class motorcycle:public veichle{
    public:
    void stradEnge() override{
        std::cout<<"motorcycle engine stared!\n";
    }
};