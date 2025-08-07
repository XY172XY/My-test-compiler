//
// Created by XYXYXY on 25-8-4.
//

#ifndef PI_OBJECT_FLOAT_H
#define PI_OBJECT_FLOAT_H

#include"object/object.h"
using namespace pi::object;

namespace pi{
    namespace object{
        class Float : public Object{
        public:
            Float() : Object(OBJECT_FLOAT),m_value(0){};
            Float(double value) : Object(OBJECT_FLOAT),m_value(value){};
            ~Float(){};

            virtual string str() const{
                return std::to_string(m_value);
            }

        public:
            double m_value;
        };
    }
}

#endif //PI_OBJECT_FLOAT_H
