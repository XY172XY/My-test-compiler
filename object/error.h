//
// Created by XYXYXY on 25-7-21.
//

#ifndef PI_OBJECT_ERROR_H
#define PI_OBJECT_ERROR_H



#include"object/object.h"
using namespace pi::object;

namespace pi{
    namespace object{
        class Error : public Object{
        public:
            Error() : Object(OBJECT_ERROR){};
            Error(const string & message) : Object(OBJECT_ERROR),m_messsge(message){};
            ~Error(){};

            virtual string str() const{
                return "error: " + m_messsge;
            };

        public:
            string m_messsge;
        };
    }
}


#endif //PI_OBJECT_ERROR_H