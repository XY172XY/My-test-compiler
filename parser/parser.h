//
// Created by XYXYXY on 25-7-20.
//

#ifndef PI_PARSER_H
#define PI_PARSER_H
#include<ast/header.h>
#include<lexer/lexer.h>
using namespace pi::ast;
using namespace pi::lexer;


namespace pi{
    namespace parser{
        class Parser {
        public:
            enum Precedence{
                LOWEST = 0,
                SUM,
                PRODUCT,
            };

            Parser();
            Parser(const std::shared_ptr<Lexer> & lexer);
            ~Parser();

            //prefix
            std::shared_ptr<Expression> parse_integer();
            std::shared_ptr<Expression> parse_group();

            //infix
            std::shared_ptr<Expression> parse_infix(const shared_ptr<Expression> & left);

            std::shared_ptr<Expression> parse_expression(int precedence);
            std::shared_ptr<Program> parse_program();
            std::shared_ptr<Statement> parse_statement();
            std::shared_ptr<ExpressionStatement> parse_expression_statement();


            //前缀表达式构建函数指针类型定义
            typedef std::shared_ptr<Expression> (Parser::*prefix_parse_fn)();
            //中缀表达式构造函数指针类型定义
            typedef std::shared_ptr<Expression> (Parser::*infix_parse_fn)(const std::shared_ptr<Expression> &);

            void next_token();
            bool curr_token_is(Token::Type type);
            bool peek_token_is(Token::Type type);
            bool expect_peek_token(Token::Type type);
            void peek_error(Token::Type type);

            int curr_token_precedence();
            int peek_token_precedence();

            void no_prefix_parse_fn_error(Token::Type type);
            std::list<string>& errors();


        private:
            std::shared_ptr<Lexer> m_lexer;
            Token m_curr;
            Token m_peek;
            std::list<string> m_errors;
            static std::map<Token::Type,int> m_precedences;
            static std::map<Token::Type,prefix_parse_fn> m_prefix_parse_fns;
            static std::map<Token::Type,infix_parse_fn> m_infix_parse_fns;
        };
    }
}



#endif //PI_PARSER_H
