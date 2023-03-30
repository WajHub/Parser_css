#include <iostream>
#include <string.h>
#include "String.h"
#include "Selector.h"
#include "Attribute.h"
#include "List.h"
#include "Section.h"
using namespace std;
#define LENGTH_BUFF 256

struct Reading{
    bool selectors=true;
    bool attribute_name=false;
    bool attribute_values=false;
    bool css=true;
    bool commands=false;
}reading;

void switch_reading(Reading &reading, char ch){
    if(ch=='{'){
        reading.selectors=false;
        reading.attribute_name=true;
    }
    else if(ch=='}'){
        reading.selectors=true;
        reading.attribute_values=false;
    }
    else if(ch==':'){
        reading.attribute_name=false;
        reading.attribute_values=true;
    }
    else if(ch==';'){
        reading.attribute_name=true;
        reading.attribute_values=false;
    }
}

void delete_space(char buff[LENGTH_BUFF], int &size){
    int i=0;
    int amount_space_front=0;
    int amount_space_back=0;
    while(buff[i]==' '){
        amount_space_front++;
        i++;
    }
    i=size-1;
    while(buff[i]==' '){
        amount_space_back++;
        i--;
    }
    size=size-amount_space_front-amount_space_back;
    if(amount_space_front!=0 || amount_space_back!=0) {
        for (int j = 0; j < size; j++) {
            char tmp = buff[amount_space_front + j];
            buff[j] = tmp;
        }
    }
    buff[size]='\0';
}

void input_string(char buff[LENGTH_BUFF],String &str,char ch, int &size){
    delete_space(buff,size);
    str.inputString(buff,size);
    switch_reading(reading,ch);
    memset(buff, '\0', LENGTH_BUFF);
    size=0;
}

void load_data(char buff[LENGTH_BUFF],char ch,int &size,Selector &selector,Attribute &attribute,
               Section &section, List<Section> &sections){
    if (reading.selectors && ch != '\n') {
        if (ch != '{' && ch != ',') {
            buff[size++] = ch;
        } else {
            input_string(buff, selector.getName(), ch, size);
            section.add_selector(selector);
        }
    } else if (reading.attribute_name && ch != '\n') {
        if (ch != ':' && ch != '}') {
            buff[size++] = ch;
        } else if (ch != '}') {
            input_string(buff, attribute.getName(), ch, size);
        } else {
            switch_reading(reading, ch);
        }
        if (ch == '}') {
            sections.push(section);
            section = Section();
        }
    } else if (reading.attribute_values && ch != '\n') {
        if (ch != ';' && ch != '}') {
            buff[size++] = ch;
        } else {
            input_string(buff, attribute.getValue(), ch, size);
            section.add_attribute(attribute);
        }
        if (ch == '}') {
            sections.push(section);
            section = Section();
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    char buff [LENGTH_BUFF];
    memset(buff, '\0', sizeof(buff));
    int size=0;
    List<Section> sections;
    Selector selector;
    Attribute attribute;
    Section section;
    char ch=' ';

    while(cin.get(ch)){
        if(reading.css) {
            if(ch=='?'){
                reading.css=false;
                reading.commands=true;
                for(int i=0;i<3;i++) cin.get(ch);
            }
            load_data(buff,ch,size,selector,attribute,section,sections);
        }
        else{
            if(ch=='*'){
                reading.css=true;
                reading.commands=false;
                for(int i=0;i<3;i++) cin.get(ch);
            }
            else if(ch=='?'){

            }
            else if(ch=='z'){

            }
            else if(ch >= '0' && ch <= '9'){

            }
            else{

            }
        }
    }
    cout<<sections;
    return 0;
}