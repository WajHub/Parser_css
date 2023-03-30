//
// Created by hubert on 29.03.2023.
//
#pragma once
#ifndef PARSER_CSS_SECTION_H
#define PARSER_CSS_SECTION_H
#include "Selector.h"
#include "Attribute.h"
#include "List.h"

class Section {
private:
    List<Selector> selectors;
    List<Attribute> attributes;
public:
    Section();
    void add_selector(Selector selector);
    void add_attribute(Attribute attribute);
    friend std::ostream& operator<<(std::ostream& out, const Section& section);
    ~Section();

};


#endif //PARSER_CSS_SECTION_H