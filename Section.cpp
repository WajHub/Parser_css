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
}

