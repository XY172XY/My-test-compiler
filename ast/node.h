//
// Created by XYXYXY on 25-7-19.
//

#ifndef PI_NODE_H
#define PI_NODE_H

#include "token/token.h"
#include<memory>
#include<list>
using namespace pi::token;

namespace pi {
    namespace ast {
        class Node {
        public:
            enum Type{
                NODE_INTEGER = 0,
                NODE_FLOAT,
                NODE_INFIX,
                NODE_EXPRESSION_STATEMENT,
                NODE_PROGRAM,
                NODE_PREFIX
            };

            Node() {};
            Node(Type type) : m_type(type){};
            virtual ~Node() {};

            virtual Json json() = 0;

            Type type() const {return m_type;};
            string name() const;

        public:
            Type m_type;
            Token m_token;

            static map<Type,string> m_names;
        };

        class Expression : public Node{
        public:
            Expression() : Node(){};
            Expression(Type type) : Node(type){};
            ~Expression(){};
        };

        class Statement : public Node{
        public:
            Statement() : Node(){};
            Statement(Type type) : Node(type){};
            ~Statement(){};
        };
    }
}


#endif //PI_NODE_H
