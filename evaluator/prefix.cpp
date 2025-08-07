//
// Created by XYXYXY on 25-7-23.
//
#include"evaluator/evaluator.h"
using namespace pi::evacuator;

std::shared_ptr<Object> Evaluator::eval_prefix(const std::shared_ptr<Prefix> & node){
    string op = node->m_operator;
    auto right = eval(node->m_right);
    if(is_error(right)){
        return right;
    }
    if(op == "-"){
        return eval_minus_prefix_expression(right);
    }
    else if(op == "~"){
        return eval_tidle_prefix_expression(right);
    }
    else{
        return new_error("unknown operator %s",op.c_str(),right->name().c_str());
    }
};

std::shared_ptr<Object> Evaluator::eval_minus_prefix_expression(const std::shared_ptr<Object> & right){
    switch(right->type()){
        case Object::OBJECT_INTEGER:{
            auto o = std::dynamic_pointer_cast<object::Integer>(right);
            return new_integer(-(o->m_value));
        }

        default:{
            return new_error("unknown operator -%s",right->name().c_str());
        }
    }

};

std::shared_ptr<Object> Evaluator::eval_tidle_prefix_expression(const std::shared_ptr<Object> & right){
    switch(right->type()){
        case Object::OBJECT_INTEGER:{
            auto o = std::dynamic_pointer_cast<object::Integer>(right);
            return new_integer(~(o->m_value));
        }

        default:{
            return new_error("unknown operator ~%s",right->name().c_str());
        }
    }
};


