//
// Created by XYXYXY on 25-8-9.
//

#include"parser/parser.h"
using namespace pi::parser;

std::shared_ptr<Expression> Parser::parse_string(){
    std::shared_ptr<String> e(new String());
    e->m_token = m_curr;
    e->m_value = m_curr.literal();
    return e;
};

