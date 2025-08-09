//
// Created by XYXYXY on 2025/7/15.
//

#include "token/token.h"
using namespace pi::token;

std::map<Token::Type,string> Token::m_names = {
        {TOKEN_ILLEGAL,     "illegal"},
        {TOKEN_EOF,         "eof"},
        {TOKEN_INTEGER,     "integer"},
        {TOKEN_FLOAT,       "float"},
        {TOKEN_STRING,      "string"},
        {TOKEN_PLUS,        "+"},
        {TOKEN_MINUS,       "-"},
        {TOKEN_ASTERISK,    "*"},
        {TOKEN_SLASH,       "/"},
        {TOKEN_MODULO,      "%"},
        {TOKEN_TIDLE,       "~"},
        {TOKEN_BIT_AND,     "&"},
        {TOKEN_BIT_OR,      "|"},
        {TOKEN_BIT_XOR,     "^"},
        {TOKEN_BIT_LSHIFT,  "<<"},
        {TOKEN_BIT_RSHIFT,  ">>"},
        {TOKEN_LT,          "<"},
        {TOKEN_GT,          ">"},
        {TOKEN_LE,          "<="},
        {TOKEN_GE,          ">="},
        {TOKEN_EQ,          "=="},
        {TOKEN_NE,          "!="},
        {TOKEN_AND,         "&&"},
        {TOKEN_OR,          "||"},
        {TOKEN_NOT,         "!"},
        {TOKEN_LPAREN,      "("},
        {TOKEN_RPAREN,      ")"},
        {TOKEN_SEMICOLON,   ";"},
        {TOKEN_TRUE,        "true"},
        {TOKEN_FALSE,       "false"},
};
std::map<string,Token::Type> Token::m_keywords = {
        {"true",            TOKEN_TRUE},
        {"false",           TOKEN_FALSE},
};


Token::Token() : m_type(TOKEN_ILLEGAL)  {}

Token::Token(Type type, const std::string & literal) : m_type(type), m_literal(literal) {}

Token::Type Token::type() const {
    return m_type;
}
string Token::name() const {
    auto it = m_names.find(m_type);
    if (it != m_names.end()) {
        return it->second;
    }
    return "";
};
string Token::literal() const {
    return m_literal;
};

Token & Token::operator=(const Token &other) {
    if (this == &other) {
        return *this;
    }
    m_type = other.m_type;
    m_literal = other.m_literal;
    return *this;
}

Token::Type Token::lookup(const string & identifier){
    auto it = m_keywords.find(identifier);
    if(it != m_keywords.end()){
        return it->second;
    }
    return TOKEN_IDENTIFIER;
};


void Token::show() const {
    printf("type= %d name= %s literal= %s\n",m_type,name().c_str(),literal().c_str());
}

Json Token::json() const {
    Json json;
    json["type"] = name();
    json["name"] = m_literal;
    return json;
}


