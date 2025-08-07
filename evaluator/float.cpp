//
// Created by XYXYXY on 25-8-4.
//

#include"evaluator/evaluator.h"
using namespace pi::evacuator;

std::shared_ptr<Object> Evaluator::eval_float(std::shared_ptr<ast::Float> & node) {
    return new_float(node->m_value);
};