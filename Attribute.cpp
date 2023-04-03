//
// Created by huber on 24.03.2023.
//

#include "Attribute.h"
#include <iostream>
using namespace std;
Attribute::Attribute() {
    name = String();
    value = String();
}
String& Attribute::getName()  {
    return name;
}
String& Attribute::getValue()  {
    return value;
}

std::ostream &operator<<(std::ostream &out, const Attribute &attribute) {
    out<<"Attibute name: "<<attribute.name;
    out<<"Attibute value: "<<attribute.value;
    return out;
}

Attribute::~Attribute() {

}

bool Attribute::isEmpty() {
    if(name.isEmpty() && value.isEmpty()) return true;
    return false;
}

bool Attribute::contains_name(String name) {
    if(name==this->name) return true;
    return false;
}




