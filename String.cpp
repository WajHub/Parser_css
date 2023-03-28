//
// Created by huber on 24.03.2023.
//

#include "String.h"
#include "Selector.h"


String::String() {
    size=1;
    array = new char[size];
    array[0]='\0';
}

String::String(char *buff, int size) {
    this->size=size;
    if(buff == nullptr) {
        size = 0;
        array = new char[1];
        array[0] = '\0';
    }
    else {
        array = new char[size+1];
        for (int i = 0; i < size; i++) {
            array[i] = buff[i];
        }
    }
    array[size]='\0';
}
void String::inputString(char *buff, int size) {
    this->size=size;
    if(buff == nullptr) {
        size = 0;
        array = new char[1];
        array[0] = '\0';
    }
    else {
        array = new char[size+1];
        for (int i = 0; i < size; i++) {
            array[i] = buff[i];
        }
    }
    array[size]='\0';
}

void String::addChar(char ch) {
    char tmp[size];
    for(int i=0;i<size;i++){
        tmp[i]=array[i];
    }
    size++;
    delete [] array;
    array = new char [size];
    for(int i=0;i<size-1;i++){
        array[i]=tmp[i];
    }
    array[size-2]=ch;
    array[size-1] ='\0';
}

char *String::getArray() const {
    return array;
}


int String::getSize() const {
    return size;
}

std::ostream& operator<<(std::ostream& out, const String& string)
{
    for(int i=0;i<string.size;i++) {
        out << string.array[i];
    }
    out<<std::endl;
    return out;
}

bool String::operator==(const String &other) const {
    if(other.getSize()==size){
        for(int i=0;i<size;i++){
            if(other.array[i]==array[i]);
            else return false;
        }
        return true;
    }
    return false;
}
String::~String() {
    delete [] array;
}



