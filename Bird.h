#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"

class Bird : public Animal {
private:
    float wingSpan;
public:
    Bird( std::string& name, int age, bool isHungry, float wingSpan);
    ~Bird() override;
    void display() override;
};

#endif
