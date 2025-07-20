//
// Created by XYXYXY on 25-7-20.
//
#include"parser/parser.h"
using namespace pi::parser;

std::shared_ptr<Statement> Parser::parse_statement(){
    return parse_expression_statement();
};

std::shared_ptr<ExpressionStatement> Parser::parse_expression_statement(){
    std::shared_ptr<ExpressionStatement> s(new ExpressionStatement());
    s->m_token = m_curr;
    s->m_expression = parse_expression(LOWEST);
    while(peek_token_is(Token::TOKEN_SEMICOLON)){
        next_token();
    }
    return s;
};
