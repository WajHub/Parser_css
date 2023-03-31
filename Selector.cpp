//
// Created by huber on 24.03.2023.
//

#include "Selector.h"
Selector::Selector() {
    name = String();
}

String& Selector::getName() {
    return name;
}
Selector::~Selector() {
}

std::ostream &operator<<(std::ostream &out, const Selector &selector) {
    out<<"Selektor name: "<<selector.name;
    return out;
}

bool Selector::isEmpty() {
    if(name.isEmpty()) return true;
    return false;
}
