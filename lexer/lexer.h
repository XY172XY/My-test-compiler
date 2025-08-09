//
// Created by XYXYXY on 2025/7/15.
//

#ifndef LEXER_H
#define LEXER_H


#include "token/token.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace pi::token;


namespace pi {
    namespace lexer {
        class Lexer {
            public:
                Lexer();
                Lexer(const string& file);
                Lexer(const char * buf,int len);
                ~Lexer() = default;

                Token next_token();

            private:
                void skip_white_space();
                void read_char();
                char peek_char();
                void unread_char();
                bool is_digit(char c);
                bool is_letter(char c);

                string read_number();
                string read_identifier();
                string read_single_quote_string();
                string read_double_quote_string();
                Token new_token(Token::Type type,const string& literal);

                string      m_input;
                char        m_ch;
                int         m_pos;
                int         m_next_pos;
        };
    }
}


#endif //LEXER_H
