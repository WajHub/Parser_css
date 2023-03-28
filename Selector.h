#ifndef PARSER_CSS_SELECTOR_H
#define PARSER_CSS_SELECTOR_H
#include "String.h"

class Selector {
private:
    String name;
public:
    Selector();
    String* getName();
    Selector(const String name);
    friend std::ostream& operator<<(std::ostream& out, const String& string);
    ~Selector();
};


#endif //PARSER_CSS_SELECTOR_H
