//
// Created by huber on 24.03.2023.
//

#ifndef PARSER_CSS_ATTRIBUTE_H
#define PARSER_CSS_ATTRIBUTE_H
#include "string.h"

class Attribute {
private:
    String name;
    String value;
public:
    Attribute();
    String& getName();
    String& getValue();
    bool isEmpty();
    friend std::ostream& operator<<(std::ostream& out, const Attribute& attribute);
    ~Attribute();
};


#endif //PARSER_CSS_ATTRIBUTE_H
