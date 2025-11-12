#ifndef MAMMAL_H
#define MAMMAL_H

#include "Animal.h"
#include <string>

class Mammal : public Animal {
private:
    std::string furColor;
public:
    Mammal( std::string& name, int age, bool isHungry, std::string& furColor);
    ~Mammal() override;
    void display() override;
};

#endif
