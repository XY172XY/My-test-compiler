//
// Created by XYXYXY on 25-7-21.
//

#ifndef PI_INTEGER_H
#define PI_INTEGER_H
#include"object/object.h"
using namespace pi::object;

namespace pi{
    namespace {
        class Integer : public Object{
        public:
            Integer() : Object(OBJECT_INTEGER),m_value(0){};
            Integer(int64_t value) : Object(OBJECT_INTEGER),m_value(value){};
            ~Integer(){};

            virtual string str() const{
                return std::to_string(m_value);
            }

        public:
            int64_t m_value;
        };
    };
}



#endif //PI_INTEGER_H
