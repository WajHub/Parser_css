#include <iostream>
#include <string.h>
#include "String.h"
#include "Selector.h"
#include "List.h"
using namespace std;

struct Reading{
    bool selectors=true;
    bool attribute_name=false;
    bool attribute_values=false;
}reading;

void switch_reading(Reading *reading, char ch){
    if(ch=='{'){
        reading->selectors=false;
        reading->attribute_name=true;
    }
    else if(ch=='}'){
        reading->selectors=true;
        reading->attribute_values=false;
    }
    else if(ch==':'){
        reading->attribute_name=false;
        reading->attribute_values=true;
    }
    else if(ch==';'){
        reading->attribute_name=true;
        reading->attribute_values=false;
    }
}

bool special_char(char ch){
    if(ch==',' || ch== ' ' || ch== '{' || ch=='}' || ch==';' || ch==':' ||ch=='\n'||ch=='\0') return true;
    return false;
}

int main() {
    freopen("input.txt", "r", stdin);

    char buff [128];
    memset(buff, '\0', sizeof(buff));
    int size=0;
    String selector;
    String atr_n;
    String atr_v;

    char ch=' ';
    while(cin>>ch){
        if(!special_char(ch)) {
            buff[size]=ch;
            size++;
        }
        else{
            if (reading.selectors && ch!='}') {
                selector.inputString(buff,size);
            } else if (reading.attribute_name && ch!='}') {
                atr_n.inputString(buff,size);
            } else if (reading.attribute_values && ch!='}') {
                atr_v.inputString(buff,size);
            }
            switch_reading(&reading,ch);
            size=0;
        }
    }
    cout<<selector;
    cout<<atr_v;
    cout<<atr_n;

    return 0;
}