//
// Created by XYXYXY on 25-8-8.
//

#ifndef PI_AST_BOOL_H
#define PI_AST_BOOL_H

#include "ast/node.h"
using namespace pi::ast;

namespace pi{
    namespace ast{
        class Bool : public Expression{
        public:
            Bool() : Expression(NODE_BOOL){};
            ~Bool(){};

            Json json(){
                Json json;
                json["type"] = name();
                json["value"] = m_value ? "true" : "false";
                return json;
            }

        public:
            bool m_value;
        };
    }
}

#endif //PI_AST_BOOL_H
