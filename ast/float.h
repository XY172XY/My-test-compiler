//
// Created by XYXYXY on 25-8-4.
//

#ifndef PI_AST_FLOAT_H
#define PI_AST_FLOAT_H

#include "ast/node.h"
using namespace pi::ast;

namespace pi{
    namespace ast{
        class Float : public Expression{
        public:
            Float() : Expression(NODE_FLOAT){};
            ~Float() {};

            Json json(){
                Json json;
                json["type"] = name();
                json["value"] = std::to_string(m_value);
                return json;
            };

        public:
            float m_value;
        };
    }
}




#endif //PI_AST_FLOAT_H
