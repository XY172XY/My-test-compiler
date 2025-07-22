//
// Created by XYXYXY on 25-7-21.
//

#include "evaluator.h"
#include <iostream>
using namespace pi::evacuator;

bool Evaluator::is_error(const shared_ptr<Object> & object){
    return object->type() == object::Object::OBJECT_ERROR;
};

std::shared_ptr<Object> Evaluator::new_error(const char * format,...){
    char buf[1024] = {0};
    va_list ags_ptr;
    va_start(ags_ptr,format);
    vsnprintf(buf,sizeof(buf),format,ags_ptr);
    return std::shared_ptr<Error>(new Error(buf));
};

std::shared_ptr<Object> Evaluator::new_integer(int64_t value){
    return Object::new_intger(value);
};

std::shared_ptr<Object> Evaluator::eval(const std::shared_ptr<Node> & node){
    switch(node->m_type){
        case Node::NODE_INTEGER:{
            auto s = std::dynamic_pointer_cast<ast::Integer>(node);
            return eval_integer(s);
        }

        case Node::NODE_PROGRAM:{
            auto s = std::dynamic_pointer_cast<ast::Program>(node);
            return eval_program(s->m_statements);
        }
        case Node::NODE_INFIX:{
            auto s = std::dynamic_pointer_cast<ast::Infix>(node);
            auto left = eval(s->m_left);
            if(is_error(left)){
                return left;
            }

            auto right = eval(s->m_right);
            if(is_error(right)){
                return right;
            }

            return eval_integer_infix_expression(s->m_operator,left,right);
        }

        case Node::NODE_EXPRESSION_STATEMENT:{
            auto s = std::dynamic_pointer_cast<ast::ExpressionStatement>(node);
            return eval(s->m_expression);
        }

        default:{
            std::cout<<node->type()<< std::endl;
            return new_error("node type error");
        }
    }
};
