//
// Created by huber on 24.03.2023.
//

#include "Selector.h"
Selector::Selector() {
    name = String();
}
String* Selector::getName() {
    return &name;
}

Selector::Selector(const String name) : name(name) {

}
Selector::~Selector() {

}