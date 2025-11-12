#ifndef REPTILE_H
#define REPTILE_H

#include "Animal.h"

class Reptile : public Animal {
private:
    bool isVenomous;
public:
    Reptile( std::string& name, int age, bool isHungry, bool isVenomous);
    ~Reptile() override;
    void display() override;
    bool getIsVenomous() ;
};

#endif
