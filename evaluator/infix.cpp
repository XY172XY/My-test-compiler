//
// Created by XYXYXY on 25-7-21.
//
#include"evaluator/evaluator.h"
using namespace pi::evacuator;


std::shared_ptr<Object> Evaluator::eval_infix(const string & op,std::shared_ptr<Object> & left,std::shared_ptr<Object> & right){
    switch(left->type()){
        case Object::OBJECT_INTEGER:{
            if(right->type() == Object::OBJECT_INTEGER){
                return eval_integer_infix_expression(op,left,right);
            }
        }
        default:{
            break;
        }

    }
    return new_error("unknown operator %s %s %s",left->name().c_str(),op.c_str(),right->name().c_str());
};


std::shared_ptr<Object> Evaluator::eval_integer_infix_expression(const string & op,std::shared_ptr<Object> & left,std::shared_ptr<Object> & right){
    auto l = std::dynamic_pointer_cast<object::Integer>(left);
    auto r = std::dynamic_pointer_cast<object::Integer>(right);
    if(op == "+"){
        return new_integer(l->m_value + r->m_value);
    }
    if(op == "*"){
        return new_integer(l->m_value * r->m_value);
    }
    if(op == "-"){
        return new_integer(l->m_value - r->m_value);
    }
    if(op == "/"){
        return new_integer(l->m_value / r->m_value);
    }
    if(op == "%"){
        return new_integer(l->m_value % r->m_value);
    }
    return new_error("unknown operator %s %s %s",left->name().c_str(),op.c_str(),right->name().c_str());

};