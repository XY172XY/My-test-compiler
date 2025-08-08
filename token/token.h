//
// Created by XYXYXY on 2025/7/15.
//

#ifndef TOKEN_H
#define TOKEN_H
#include <map>
#include <string>
#include "json/json.h"
using namespace yazi::json;
using namespace std;

namespace pi {
 namespace token{
    class Token {
  public:
     enum Type {
      TOKEN_ILLEGAL = 0,  // illegal
      TOKEN_EOF,          // eof
      TOKEN_INTEGER,      // integer
      TOKEN_FLOAT,        // float
      TOKEN_PLUS,         // +
      TOKEN_MINUS,        // -
      TOKEN_ASTERISK,     // *
      TOKEN_SLASH,        // /
      TOKEN_MODULO,       // %
      TOKEN_TIDLE,        // ~
      TOKEN_BIT_AND,      // &
      TOKEN_BIT_OR,       // |
      TOKEN_BIT_XOR,      // ^
      TOKEN_BIT_LSHIFT,   // <<
      TOKEN_BIT_RSHIFT,   // >>
      TOKEN_LT,           // <
      TOKEN_GT,           // >
      TOKEN_LE,           // <=
      TOKEN_GE,           // >=
      TOKEN_EQ,           // ==
      TOKEN_NE,           // !=
      TOKEN_LPAREN,       // (
      TOKEN_RPAREN,       // )
      TOKEN_SEMICOLON,    // ;
      TOKEN_IDENTIFIER,   // identifier
      TOKEN_TRUE,         // true
      TOKEN_FALSE,        // false
      };
     Token();
     Token(Type type,const string & literal );
     ~Token() = default;

     Type type() const;
     string name() const;
     string literal() const;

     Token & operator = (const Token & other);
     static Type lookup(const string & identifier);

     void show() const;
     Json json() const;

    private:
     Type m_type;
     string m_literal;
     static map<Type,string> m_names;
     static map<string,Type> m_keywords;
    };
 };
}


#endif //TOKEN_H
