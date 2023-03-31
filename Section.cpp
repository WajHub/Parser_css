//
// Created by hubert on 29.03.2023.
//

#include "Section.h"

Section::Section() {
    List<Selector> selectors=List<Selector>();
    List<Attribute> attributes=List<Attribute>();
}



Section::~Section() {

}

void Section::add_selector(Selector selector) {
    selectors.push(selector);
}

void Section::add_attribute(Attribute attribute) {
    attributes.push(attribute);
}

std::ostream &operator<<(std::ostream &out, const Section &section) {
    out<<"Section: "<<std::endl;
    out<<section.selectors<<std::endl;
    out<<section.attributes<<std::endl;
    return out;
}

List<Selector>& Section::get_selectors() {
    return selectors;
}

List<Attribute>& Section::get_attributes() {
    return attributes;
}

bool Section::contains_attribute(String name) {
    int x=attributes.get_amount();
    for(int i=1;i<=x;i++){
        if(attributes.exist_element(i)){
            if(attributes.get_element(i).getName()==name) return true;
        }
    }
    return false;
}

String Section::attribute_value(String name) {
    if(contains_attribute(name)){
        int x=attributes.get_amount();
        for(int i=1;i<=x;i++){
            if(attributes.exist_element(i)){
                if(attributes.get_element(i).getName()==name) {
                    return attributes.get_element(i).getValue();
                }
            }
        }
        return String();
    }
    return String();
}

