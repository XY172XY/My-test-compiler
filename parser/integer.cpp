//
// Created by XYXYXY on 25-7-20.
//

#include<parser/parser.h>
using namespace pi::parser;

std::shared_ptr<Expression> Parser::parse_integer(){
    std::shared_ptr<Integer> e(new Integer());
    e->m_token = m_curr;
    e->m_value = std::atol(m_curr.literal().c_str());
    return e;
};
