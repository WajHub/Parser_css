//
// Created by huber on 24.03.2023.
//

#ifndef PARSER_CSS_STRING_H
#define PARSER_CSS_STRING_H
#include <iostream>

class String {
private:
    int size=0;
    char *array;
public:
    String();
    String(char *tab);
    void inputString();
    char *getArray() const;
    int getSize() const;
    friend std::ostream& operator<<(std::ostream& out, const String& string);
    ~String();
};


#endif //PARSER_CSS_STRING_H
