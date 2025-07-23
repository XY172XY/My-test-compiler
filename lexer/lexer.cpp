//
// Created by XYXYXY on 2025/7/15.
//

#include "lexer/lexer.h"
using namespace pi::lexer;

Lexer::Lexer(){};
Lexer::Lexer(const string& file) {
    m_ch = 0;
    m_next_pos = 0;
    m_pos = 0;

    std::ifstream ifs(file);

    if (!ifs.good()) {
        std::cout<<"Error opening file "<<file<<std::endl;
    }

    std::ostringstream oss;
    oss<<ifs.rdbuf();
    m_input = oss.str();

} ;

Lexer::Lexer(const char * buf,int len) {
    m_ch = 0;
    m_next_pos = 0;
    m_pos = 0;
    m_input.assign(buf,len);
}

Token Lexer::next_token() {
    read_char();
    skip_white_space();
    switch (m_ch) {
        case '+': {
            string literal;
            literal += m_ch;
            return new_token(Token::TOKEN_PLUS, literal);
        }
        case '-': {
            string literal;
            literal += m_ch;
            return new_token(Token::TOKEN_MINUS, literal);
        }
        case '*': {
            string literal;
            literal += m_ch;
            return new_token(Token::TOKEN_ASTERISK, literal);
        }
        case '/': {
            string literal;
            literal += m_ch;
            return new_token(Token::TOKEN_SLASH, literal);
        }
        case '%': {
            string literal;
            literal += m_ch;
            return new_token(Token::TOKEN_MODULO, literal);
        }
        case '(': {
            string literal;
            literal += m_ch;
            return new_token(Token::TOKEN_LPAREN, literal);
        }
        case ')': {
            string literal;
            literal += m_ch;
            return new_token(Token::TOKEN_RPAREN, literal);
        }
        case 0: {
            return new_token(Token::TOKEN_EOF, "");
        }
        default: {
            if (is_digit(m_ch)) {
                string integer = read_number();
                unread_char();
                return new_token(Token::TOKEN_INTEGER, integer);
            } else {
                string literal;
                literal += m_ch;
                return new_token(Token::TOKEN_ILLEGAL,literal);
            }
        }
    }
}

void Lexer::skip_white_space() {
    while(m_ch == ' ' || m_ch == '\t' || m_ch == '\n'  || m_ch == '\r'){
        read_char();
    }
};

void Lexer::read_char() {
    if(m_next_pos >= m_input.length()){
        m_ch = 0;
    }
    else{
        m_ch = m_input[m_next_pos];
    }
    m_pos = m_next_pos;
    m_next_pos++;
};

void Lexer::unread_char(){//回档函数
    m_next_pos = m_pos;
    m_pos--;
};

bool Lexer::is_digit(char c){
    return (m_ch >= '0' && m_ch <= '9');
};

string Lexer::read_number(){
    int pos = m_pos;
    while(is_digit(m_ch)){
        read_char();
    }
    return m_input.substr(pos,m_pos-pos);
};

Token Lexer::new_token(Token::Type type,const string& literal){
    Token token(type,literal);
    return token;
};

