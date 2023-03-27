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
    String(char *buff,int size);
    void inputString(char *buff, int size);
    void addChar(char ch);
    char *getArray() const;
    int getSize() const;
    bool operator==(const String& other) const;
    friend std::ostream& operator<<(std::ostream& out, const String& string) ;
    ~String();
};


#endif //PARSER_CSS_STRING_H
