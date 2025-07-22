//
// Created by XYXYXY on 25-7-21.
//
#include"evaluator/evaluator.h"
using namespace pi::evacuator;

std::shared_ptr<Object> Evaluator::eval_integer(std::shared_ptr<ast::Integer> & integer){
    return new_integer(integer->m_value);
};