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
    List<Attribute> atrributes;
public:


};


#endif //PARSER_CSS_SECTION_H
