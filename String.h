#pragma once
//
// Created by huber on 24.03.2023.
//

#ifndef PARSER_CSS_STRING_H
#define PARSER_CSS_STRING_H
#include <iostream>
#define LENGTH_BUFF 256

class String {
private:
    int size=0;
    char *array;
public:
    String();
//    String(char *buff,int size);
    String(const String &other);
    void inputString(char buff[LENGTH_BUFF], int size);
    char *getArray() const;
    int getSize() const;
    bool operator==(const String& other) const;
    bool isEmpty();
    String& operator=(const String& other);
    friend std::ostream& operator<<(std::ostream& out, const String& string);
    ~String();
};


#endif //PARSER_CSS_STRING_H
