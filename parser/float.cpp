//
// Created by XYXYXY on 25-8-4.
//
#include<parser/parser.h>


using namespace pi::parser;

std::shared_ptr<Expression> Parser::parse_float() {
    std::shared_ptr<Float> e(new Float());
    e->m_token = m_curr;
    e->m_value = std::atof(m_curr.literal().c_str());
    return e;
};
