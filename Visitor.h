#ifndef VISITOR_H
#define VISITOR_H

#include <string>

class Visitor {
private:
    std::string visitorName;
    int ticketsBought;
public:
    Visitor( std::string& name, int ticketsBought);
    void displayInfo() ;
};

#endif
