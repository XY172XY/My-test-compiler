//
// Created by XYXYXY on 25-7-19.
//

#include "node.h"
using namespace pi::ast;

std::map<Node::Type,std::string> Node::m_names{
        {NODE_INTEGER,               "Integer"},
        {NODE_FLOAT,                 "Float"},
        {NODE_BOOL,                  "Bool"},
        {NODE_INFIX,                 "Infix"},
        {NODE_EXPRESSION_STATEMENT,  "ExpressionStatement"},
        {NODE_PROGRAM,               "Program"},
        {NODE_PREFIX,                "Prefix"},
        {NODE_STRING,                "String"},
};

string Node::name() const{
    auto it = m_names.find(m_type);
    if(it!=m_names.end()){
        return it->second;
    }
    return "";
};

