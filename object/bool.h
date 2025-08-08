//
// Created by XYXYXY on 25-8-8.
//

#ifndef PI_OBJECT_BOOL_H
#define PI_OBJECT_BOOL_H

#include"object/object.h"
using namespace pi::object;

namespace pi{
    namespace object{
        class Bool : public Object{
        public:
            Bool() : Object(OBJECT_BOOL),m_value(false){};
            Bool(bool value) : Object(OBJECT_BOOL),m_value(value){};
            ~Bool(){};

            virtual string str() const{
                return m_value ? "true" : "false";
            }

        public:
            bool m_value;


        };
    }
}

#endif //PI_OBJECT_BOOL_H
