//
// Created by XYXYXY on 25-7-21.
//
#include"evaluator/evaluator.h"
using namespace pi::evacuator;

std::shared_ptr<Object> Evaluator::eval_program(std::list<shared_ptr<ast::Statement>> & stmts){
    std::shared_ptr<Object> result;
    for(auto & stmt : stmts){
        result = eval(stmt);
        if(is_error(result)){
            break;
        }
        return result;
    }
    return result;
};