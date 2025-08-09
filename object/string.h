//
// Created by XYXYXY on 25-8-9.
//

#ifndef PI_OBJECT_STRING_H
#define PI_OBJECT_STRING_H

#include"object.h"
using namespace pi::object;

namespace pi{
    namespace object{
        class String : public Object{
        public:
            String() : Object(OBJECT_STRING){};
            String(const string & value) : Object(OBJECT_STRING),m_value(value){};
            ~String(){};

            virtual string str() const{
                return m_value;
            }

        public:
            string m_value;
        };
    }
}

#endif //PI_OBJECT_STRING_H
