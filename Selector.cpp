//
// Created by huber on 24.03.2023.
//

#include "Selector.h"
Selector::Selector() {
    name = String();
}
String Selector::getName_() {
    return name;
}

String* Selector::getName() {
    return &name;
}
Selector::~Selector() {
    delete &name;
}

std::ostream &operator<<(std::ostream &out, const Selector &selector) {
    out<<"Selektor name: "<<selector.name;
    return out;
}
