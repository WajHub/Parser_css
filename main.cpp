#include <iostream>
#include "String.h"
#include "Selector.h"
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
    if(ch==',' || ch== ' ' || ch== '{' || ch=='}' || ch==';' || ch==':') return true;
    return false;
}

int main() {
    String selector;
    String atr_n;
    String atr_v;

    char ch=' ';
    while(cin>>ch && ch!='*'){
        cout<<ch;
        switch_reading(&reading,ch);
        if(!special_char(ch)) {
            if (reading.selectors) {
                selector.addChar(ch);
                cout<<selector<<endl;
            } else if (reading.attribute_name) {
                atr_n.addChar(ch);
            } else if (reading.attribute_values) {
                atr_v.addChar(ch);
            }
        }
    }
    cout<<selector<<endl;
    cout<<atr_n<<endl;
    cout<<atr_v<<endl;

    return 0;
}