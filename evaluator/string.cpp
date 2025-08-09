//
// Created by XYXYXY on 25-8-9.
//
#include"evaluator/evaluator.h"
using namespace pi::evacuator;

std::shared_ptr<Object> Evaluator::eval_string(const std::shared_ptr<ast::String> & node){
    return new_string(node->m_value);
};

