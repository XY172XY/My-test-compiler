//
// Created by XYXYXY on 25-7-19.
//

#ifndef PI_EXPRESSION_STATEMENT_H
#define PI_EXPRESSION_STATEMENT_H
#include"ast/node.h"
using namespace pi::ast;

namespace pi{
    namespace ast{
        class ExpressionStatement : public Statement {
        public:
            ExpressionStatement() : Statement(NODE_EXPRESSION_STATEMENT){};
            ~ExpressionStatement(){};

            virtual Json json(){
                Json json;
                json["type"] = name();
                json["expression"] = m_expression->json();
                return json;
            }

        public:
            std::shared_ptr<Expression> m_expression;
        };
    }
}



#endif //PI_EXPRESSION_STATEMENT_H
