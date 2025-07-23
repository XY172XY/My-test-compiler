//
// Created by XYXYXY on 25-7-23.
//

#include"parser/parser.h"
using namespace pi::parser;

std::shared_ptr<Expression> Parser::parse_prefix(){
    std::shared_ptr<Prefix> prefix(new Prefix());
    prefix->m_token = m_curr;
    prefix->m_operator = m_curr.literal();
    next_token();
    prefix->m_right = parse_expression(PREFIX);

    return prefix;
};
