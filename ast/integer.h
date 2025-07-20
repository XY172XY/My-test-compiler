//
// Created by XYXYXY on 25-7-19.
//

#ifndef PI_INTEGER_H
#define PI_INTEGER_H
#include"ast/node.h"
#include<cstdint>
using namespace pi::ast;

namespace pi{
    namespace ast{
        class Integer : public Expression{
        public:
            Integer() : Expression(NODE_INTEGER){};
            ~Integer(){}

            virtual Json json(){
                Json json;
                json["type"] = name();
                json["value"] = std::to_string(m_value);
                return json;
            }


        public:
           int64_t m_value;
        };
    }
}



#endif //PI_INTEGER_H
