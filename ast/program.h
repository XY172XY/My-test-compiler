//
// Created by XYXYXY on 25-7-19.
//

#ifndef PI_PROGRAM_H
#define PI_PROGRAM_H

#include"ast/node.h"
using namespace pi::ast;

namespace pi{
    namespace ast{
        class Program : public Statement {
        public:
            Program() : Statement(NODE_PROGRAM){};
            Program(Type type) : Statement(type){};
            ~Program(){};

            virtual Json json(){
                Json json;
                json["type"] = name();
                Json statements;
                for(auto & s : m_statements){
                    statements.append(s->json());
                }
                json["statements"] = statements;
                return json;
            }

        public:
            std::list<std::shared_ptr<Statement>> m_statements;
        };
    }
}



#endif //PI_PROGRAM_H
