//
// Created by XYXYXY on 25-7-23.
//

#ifndef PI_PREFIX_H
#define PI_PREFIX_H
#include"ast/node.h"
using namespace pi::ast;

namespace pi{
    namespace ast{
        class Prefix : public Expression{
        public:
            Prefix() : Expression(NODE_PREFIX){};
            ~Prefix(){};

            virtual Json json(){
                Json json;
                json["type"] = name();
                json["operator"] = m_operator;
                json["right"] = m_right->json();
                return json;
            }

        public:
            string m_operator;
            std::shared_ptr<Expression> m_right;

        };
    }
}

#endif //PI_PREFIX_H
