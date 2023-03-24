//
// Created by huber on 24.03.2023.
//

#include "String.h"

String::String() {

}
String::String(char *buff) {
    if(buff == nullptr) {
        size = 0;
        array = new char[1];
        array[0] = '\0';
    }
    else {
        while (buff[size] != '\0') {
            size++;
        }
        array = new char[size];
        for (int i = 0; i < size; i++) {
            array[i] = buff[i];
        }
        array[size] = '\0';
    }
}

void String::inputString() {
    char *buff = new char[128];
    std::cin >> buff;
    if(buff == nullptr) {
        size = 0;
        array = new char[1];
        array[0] = '\0';
    }
    else {
        while (buff[size] != '\0') {
            size++;
        }
        array = new char[size];
        for (int i = 0; i < size; i++) {
            array[i] = buff[i];
        }
        array[size] = '\0';
    }
    delete [] buff;
}

char *String::getArray() const {
    return array;
}


int String::getSize() const {
    return size;
}

String::~String() {
    delete [] array;
}

std::ostream& operator<<(std::ostream& out, const String& string)
{
    out << string.array << std::endl;
    return out;
}


