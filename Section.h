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
public:
    List<Selector> selectors;
    List<Attribute> attributes;
    Section();
    void add_selector(Selector selector);
    void add_attribute(Attribute attribute);
    List<Selector>& get_selectors();
    List<Attribute>& get_attributes();
    friend std::ostream& operator<<(std::ostream& out, const Section& section);
    ~Section();

};


#endif //PARSER_CSS_SECTION_H
