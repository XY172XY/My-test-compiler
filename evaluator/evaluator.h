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
            std::shared_ptr<Object> new_float(double value);
            std::shared_ptr<Object> new_bool(bool value);
            std::shared_ptr<Object> new_string(const string & value);
            std::shared_ptr<Object> cast_from_integer_to_float(const std::shared_ptr<Object> & obj);


            std::shared_ptr<Object> eval(const std::shared_ptr<ast::Node> & node);
            std::shared_ptr<Object> eval_program(std::list<shared_ptr<ast::Statement>> & stmts);
            std::shared_ptr<Object> eval_integer(std::shared_ptr<ast::Integer> & node);
            std::shared_ptr<Object> eval_float(std::shared_ptr<ast::Float> & node);
            std::shared_ptr<Object> eval_bool(std::shared_ptr<ast::Bool> & node);
            std::shared_ptr<Object> eval_string(const std::shared_ptr<ast::String> & node);



            //prefix
            std::shared_ptr<Object> eval_prefix(const std::shared_ptr<Prefix> & node);
            std::shared_ptr<Object> eval_minus_prefix_expression(const std::shared_ptr<Object> & right);
            std::shared_ptr<Object> eval_tidle_prefix_expression(const std::shared_ptr<Object> & right);
            std::shared_ptr<Object> eval_bang_prefix_expression(const std::shared_ptr<Object> & right);




            //infix
            std::shared_ptr<Object> eval_infix(const string & op,const std::shared_ptr<Object> & left,const std::shared_ptr<Object> & right);
            std::shared_ptr<Object> eval_integer_infix_expression(const string & op,const std::shared_ptr<Object> & left,const std::shared_ptr<Object> & right);
            std::shared_ptr<Object> eval_float_infix_expression(const string & op,const std::shared_ptr<Object> & left,const std::shared_ptr<Object> & right);
            std::shared_ptr<Object> eval_bool_infix_expression(const string & op,const std::shared_ptr<Object> & left,const std::shared_ptr<Object> & right);

        };
    }
}




#endif //PI_EVALUATOR_H
