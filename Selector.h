#pragma once
#ifndef PARSER_CSS_SELECTOR_H
#define PARSER_CSS_SELECTOR_H
#include "String.h"

class Selector {
private:
    String name;
public:
    Selector();
    String getName_();
    String* getName();
    friend std::ostream& operator<<(std::ostream& out, const Selector& selector);
    ~Selector();
};


#endif //PARSER_CSS_SELECTOR_H
