//
// Created by XYXYXY on 25-7-19.
//

#ifndef PI_INFIX_H
#define PI_INFIX_H
#include "ast/node.h"
using namespace pi::ast;

namespace pi{
    namespace ast{
        class Infix : public Expression{
        public:
            Infix() : Expression(){};
            Infix(Type type) : Expression(NODE_INFIX){};
            ~Infix(){};

            virtual Json json(){
                Json json;
                json["type"] = name();
                json["operator"] = m_operator;
                json["left"] = m_left->json();
                json["right"] = m_right->json();
                return json;
            }

        public:
            string m_operator;
            std::shared_ptr<Expression> m_left;
            std::shared_ptr<Expression> m_right;
        };
    }
}



#endif //PI_INFIX_H
