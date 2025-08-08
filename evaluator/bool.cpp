//
// Created by XYXYXY on 25-8-8.
//
#include "evaluator/evaluator.h"
using namespace pi::evacuator;

std::shared_ptr<Object> Evaluator::eval_bool(std::shared_ptr<ast::Bool> & node){
    return new_bool(node->m_value);
};
