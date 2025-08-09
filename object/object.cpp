//
// Created by XYXYXY on 25-7-21.
//

#include "object/object.h"
#include "object/integer.h"
#include "object/error.h"
#include "object/float.h"
#include "object/bool.h"
#include "object/string.h"

using namespace pi::object;


std::map<Object::Type,string> Object::m_names = {
        {OBJECT_ERROR,      "error"},
        {OBJECT_INTEGER,    "integer"},
        {OBJECT_FLOAT,      "float"},
        {OBJECT_BOOL,       "bool"},
        {OBJECT_STRING,     "string"},
};

std::string Object::name() const{
    auto it = m_names.find(m_type);
    if(it == m_names.end()){
        return "";
    }
    return it->second;
};

shared_ptr<Object> Object::new_error(const char * format,...){
    char buf[1024] = {0};
    va_list arg_prt;
    va_start(arg_prt,format);
    vsnprintf(buf,sizeof(buf),format,arg_prt);
    va_end(arg_prt);
    return shared_ptr<Error>(new Error(buf));

};

shared_ptr<Object> Object::new_integer(int64_t value){
    return shared_ptr<Integer>(new Integer(value));
};

shared_ptr<Object> Object::new_float(double value){
    return shared_ptr<Float>(new Float(value));
};

shared_ptr<Object> Object::new_bool(bool value){
    return shared_ptr<Bool>(new Bool(value));
};

shared_ptr<Object> Object::new_string(const string & value){
    return shared_ptr<String>(new String(value));
};



