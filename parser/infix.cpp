//
// Created by XYXYXY on 25-7-20.
//
#include"parser/parser.h"
using namespace pi::parser;

std::shared_ptr<Expression> Parser::parse_infix(const shared_ptr<pi::ast::Expression> &left) {
    std::shared_ptr<Infix> e(new Infix());
    e->m_token = m_curr;
    e->m_left = left;
    e->m_operator = m_curr.literal();
    int precedence = curr_token_precedence();
    next_token();
    e->m_right = parse_expression(precedence);
    return e;
}