//
// Created by XYXYXY on 25-7-20.
//
#include"parser/parser.h"
using namespace pi::parser;

std::shared_ptr<Program> Parser::parse_program(){
    std::shared_ptr<Program> s(new Program());
    while(m_curr.type()!= Token::TOKEN_EOF){
        auto stmt = parse_statement();
        if(stmt){
            s->m_statements.push_back(stmt);
        }
        next_token();
    }
    return s;
};