//
// Created by XYXYXY on 25-7-21.
//

#ifndef PI_EVALUATOR_H
#define PI_EVALUATOR_H


#include"ast/header.h"
using namespace pi::ast;

#include"object/header.h"
using namespace pi::object;

namespace pi{
    namespace evacuator{
        class Evaluator {
        public:
            Evaluator(){};
            ~Evaluator(){};

            bool is_error(const shared_ptr<Object> & object);
            std::shared_ptr<Object> new_error(const char * format,...);
            std::shared_ptr<Object> new_integer(int64_t value);

            std::shared_ptr<Object> eval(const std::shared_ptr<ast::Node> & node);
            std::shared_ptr<Object> eval_program(std::list<shared_ptr<ast::Statement>> & stmts);
            std::shared_ptr<Object> eval_integer(std::shared_ptr<ast::Integer> & integer);

            //infix
            std::shared_ptr<Object> eval_infix(const string & op,std::shared_ptr<Object> & left,std::shared_ptr<Object> & right);
            std::shared_ptr<Object> eval_integer_infix_expression(const string & op,std::shared_ptr<Object> & left,std::shared_ptr<Object> & right);


        };
    }
}




#endif //PI_EVALUATOR_H
