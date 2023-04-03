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
};

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

void input_string(char buff[LENGTH_BUFF],String &str, int &size){
    delete_space(buff,size);
    str.inputString(buff,size);
    memset(buff, '\0', LENGTH_BUFF);
    size=0;
}

void delete_dupplicate(Section &section, String &name){
    int index = section.index_attribute(name);
    if(index > 0){
        section.get_attributes().delete_element(index);
    }
}

void load_data(char buff[LENGTH_BUFF],char ch,int &size,Selector &selector,Attribute &attribute,
               Section &section, List<Section> &sections, Reading &reading){
    if (reading.selectors && ch != '\n') {
        if (ch != '{' && ch != ',' && ch!=';') {
            buff[size++] = ch;
        } else {
            if(ch==';') memset(buff, '\0', LENGTH_BUFF);
            input_string(buff, selector.getName(), size);
            switch_reading(reading,ch);
            if(!selector.isEmpty()) section.add_selector(selector);
        }
    } else if (reading.attribute_name && ch != '\n') {
        if (ch != ':' && ch != '}') {
            buff[size++] = ch;
        } else if (ch != '}') {
            input_string(buff, attribute.getName(), size);
            switch_reading(reading,ch);
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
            input_string(buff, attribute.getValue(), size);
            switch_reading(reading,ch);
            delete_dupplicate(section,attribute.getName());
            section.add_attribute(attribute);
        }
        if (ch == '}') {
            sections.push(section);
            section = Section();
        }
    }
}

int load_int(char buff[LENGTH_BUFF],int &size, char ch){
    int number=0;
    buff[0]=ch;
    size++;
    while(cin.get(ch) && ch!=',' && ch!=' ' && ch!='\n' ){
        buff[size++]=ch;
    }
    for(int i=0;i<size;i++){
        number = number*10 +(buff[i]-'0');
    }
    memset(buff, '\0', LENGTH_BUFF);
    size=0;
    return number;
}

int count_attributes(List<Section> &sections, String &name){
    int result=0;
    int amount_sections = sections.get_amount();
    for(int j=1;j<=amount_sections;j++){
        if(sections.exist_element(j)) result=result + sections.get_element(j).count_attributes(name);
        else amount_sections++;
    }
    return result;
}

int count_selectors(List<Section> &sections, String &name){
    int result=0;
    int amount_sections = sections.get_amount();
    for(int j=1;j<=amount_sections;j++){
        if(sections.exist_element(j)) result=result + sections.get_element(j).count_selectors(name);
        else amount_sections++;
    }
    return result;
}

String get_attr_for_sel(List<Section> &sections,String &name, String &name2){
    String result;
    int amount_sections = sections.get_amount();
    for(int i=1;i<=amount_sections;i++){
        if(sections.exist_element_(i)){
            Section &section = sections.get_element_(i);
            if(section.contains_selector(name)){
                if(section.contains_attribute(name2)){
                    result=section.attribute_value(name2);
                    return result;
                }
            }
        }
        else amount_sections++;
    }
    return result;
}



int main() {

    freopen("input.txt", "r", stdin);
    char buff [LENGTH_BUFF];
    memset(buff, '\0', sizeof(buff));
    int size=0;
    Reading reading;
    List<Section> sections;
    Selector selector;
    Attribute attribute;
    Section section;
    String name;
    String name2;
    String answer;
    char ch=' ';
    while(cin.get(ch) && ch!=EOF){
        if(reading.css && ch>=' ') {
            if(ch=='?'){
                reading.css=false;
                reading.commands=true;
                for(int i=0;i<3;i++) cin.get(ch);
            }
            else load_data(buff,ch,size,selector,attribute,section,sections, reading);
        }
        else if(ch>=' '){
            if(ch=='*'){
                reading.css=true;
                reading.commands=false;
                for(int i=0;i<3;i++) cin.get(ch);
            }
            else if(ch=='?'){
                cout<<"? == "<<sections.get_amount()<<endl;
            }
            else if(ch >= '0' && ch <= '9'){
                int i = load_int(buff,size,ch);
                cin.get(ch);
                if(ch=='S'){
                    cin.get(ch);
                    cin.get(ch);
                    if(ch=='?') {
                        if (sections.exist_element(i)) {
                            cout<<i << ",S,? == " << sections.get_element(i).get_selectors().get_amount() << endl;
                        }
                    }
                    else{
                        int j = load_int(buff,size,ch);
                        if(sections.exist_element(i)){
                            if(sections.get_element(i).get_selectors().exist_element(j)){
                                cout<<i<<",S,"<<j<<" == "<<sections.get_element(i).get_selectors().get_element(j)<<endl;
                            }
                        }
                    }
                }
                else if(ch=='A'){
                    cin.get(ch);
                    cin.get(ch);
                    if(ch=='?') {
                        if (sections.exist_element(i)) {
                            cout<<i << ",A,? == " << sections.get_element(i).get_attributes().get_amount() << endl;
                        }
                    }
                    else{
                        name=String();
                        buff[size++]=ch;
                        while(cin.get(ch) && ch!='\0' && ch!='\n'){
                            buff[size]=ch;
                            size++;
                        }
                        input_string(buff,name,size);
                        if(sections.exist_element(i)){
                            if(sections.get_element(i).contains_attribute(name)){
                                cout<<i<<",A,"<<name<<" == "<<sections.get_element(i).attribute_value(name)<<endl;
                            }
                        }
                    }
                }
                else if(ch=='D'){
                    cin.get(ch);
                    cin.get(ch);
                    if(ch=='*'){
                        if(sections.exist_element(i)){
                            sections.get_element(i).get_selectors().delete_all();
                            sections.get_element(i).get_attributes().delete_all();
                            if(sections.delete_element(i)) cout<<i<<",D,* == deleted"<<endl;
                        }
                    }
                    else{
                        name=String();
                        buff[size++]=ch;
                        while(cin.get(ch) && ch!=',' && ch!='\n' && ch!='\0'){
                            buff[size]=ch;
                            size++;
                        }
                        input_string(buff,name,size);
                        if(sections.exist_element(i)) {
                            if (sections.get_element(i).delete_attribute(name))
                                cout << i << ",D," << name << " == deleted" << endl;
                            if (sections.get_element(i).isEmpty()) sections.delete_element(i);
                        }
                    }
                }
            }
            else if(ch!='\n' && ch!='\0' && ch!=' '){
                name=String();
                buff[size++]=ch;
                while(cin.get(ch) && ch!=','){
                    buff[size]=ch;
                    size++;
                }
                input_string(buff,name,size);
                cin.get(ch);
                if(ch=='A'){
                    cin.get(ch);
                    cin.get(ch);
                    cout<<name<<",A,? == "<<count_attributes(sections,name)<<endl;
                }
                else if(ch=='S'){
                    cin.get(ch);
                    cin.get(ch);
                    cout<<name<<",S,? == "<<count_selectors(sections,name)<<endl;
                }
                else if(ch=='E'){
                    name2=String();
                    cin.get(ch);
                    while(cin.get(ch) && ch!='\n'){
                        buff[size]=ch;
                        size++;
                    }
                    input_string(buff,name2,size);
                    answer = get_attr_for_sel(sections,name,name2);
                    if(!answer.isEmpty()) cout<<name<<",E,"<<name2<<" == "<<answer<<endl;
                }
            }
        }
    }
//    cout<<sections;
    return 0;
}