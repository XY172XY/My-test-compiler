//
// Created by XYXYXY on 25-7-20.
//

#include "parser.h"
using namespace pi::parser;

std::map<Token::Type,int> Parser::m_precedences{
        {Token::TOKEN_PLUS,     SUM},
        {Token::TOKEN_MINUS,    SUM},
        {Token::TOKEN_ASTERISK, PRODUCT},
        {Token::TOKEN_SLASH,    PRODUCT}
};

std::map<Token::Type,Parser::prefix_parse_fn> Parser::m_prefix_parse_fns = {
        {Token::TOKEN_INTEGER,&Parser::parse_integer},
        {Token::TOKEN_LPAREN,&Parser::parse_group},
};
std::map<Token::Type,Parser::infix_parse_fn> Parser::m_infix_parse_fns = {
        {Token::TOKEN_MINUS,&Parser::parse_infix},
        {Token::TOKEN_PLUS,&Parser::parse_infix},
        {Token::TOKEN_SLASH,&Parser::parse_infix},
        {Token::TOKEN_ASTERISK,&Parser::parse_infix},
};

Parser::Parser(){};

Parser::Parser(const std::shared_ptr<Lexer> & lexer) : m_lexer(lexer) {
    next_token();
    next_token();
};

Parser::~Parser(){

};

void Parser::next_token(){
    m_curr = m_peek;
    m_peek = m_lexer->next_token();
};

bool Parser::curr_token_is(Token::Type type){
    return m_curr.type() == type;
};

bool Parser::peek_token_is(Token::Type type){
    return m_peek.type() == type;
};

bool Parser::expect_peek_token(Token::Type type){
    if(peek_token_is(type)){
        next_token();
        return true;
    }
    else{
        peek_error(type);
        return false;
    }
};

void Parser::peek_error(Token::Type type){
    ostringstream oss;
    oss<<"expected next token to be"<< type <<",get" << m_peek.type() << "instead";
    m_errors.push_back(oss.str());
};

int Parser::curr_token_precedence(){
    auto it = m_precedences.find(m_curr.type());
    if(it!=m_precedences.end()){
        return it->second;
    }
    return LOWEST;
};

int Parser::peek_token_precedence(){
    auto it = m_precedences.find(m_peek.type());
    if(it!=m_precedences.end()){
        return it->second;
    }
    return LOWEST;
};

void Parser::no_prefix_parse_fn_error(Token::Type type){
    ostringstream oss;
    oss<<"no prefix parse function for"<<type;
    m_errors.push_back(oss.str());
};

std::list<string>& Parser::errors(){
    return m_errors;
};

