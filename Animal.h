#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
private:
    std::string name;
    int age;
    bool isHungry;
public:
    Animal( std::string& name, int age, bool isHungry);
    virtual ~Animal();
    std::string& getName() ;
    int getAge() ;
    bool getIsHungry() ;
    void setHungry(bool hungry);
    virtual void display() ;
    void feed();
};

#endif
