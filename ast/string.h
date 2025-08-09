//
// Created by XYXYXY on 25-8-9.
//

#ifndef PI_AST_STRING_H
#define PI_AST_STRING_H
#include"ast/node.h"
using namespace pi::ast;

namespace pi{
    namespace ast{
        class String : public Expression{
        public:
            String() : Expression(NODE_STRING){};
            ~String(){};

            virtual Json json(){
                Json json;
                json["type"] = type();
                json["value"] = m_value;
                return json;
            }

        public:
            string m_value;
        };
    }
}

#endif //PI_AST_STRING_H
