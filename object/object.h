//
// Created by XYXYXY on 25-7-21.
//

#ifndef PI_OBJECT_H
#define PI_OBJECT_H

#include <map>
#include <string>
#include <memory>
#include <stdarg.h>
using namespace std;

namespace pi{
    namespace object{
        class Object {
        public:
            enum Type{
                OBJECT_ERROR = 0,
                OBJECT_INTEGER,
                OBJECT_FLOAT,
                OBJECT_BOOL,
                OBJECT_STRING,
            };


        public:
            Object(){};
            Object(Type type) : m_type(type){};
            virtual ~Object(){};

            Type type() const {return m_type;};
            std::string name() const;
            virtual std::string str() const = 0;

            static shared_ptr<Object> new_error(const char * format,...);
            static shared_ptr<Object> new_integer(int64_t value);
            static shared_ptr<Object> new_float(double value);
            static shared_ptr<Object> new_bool(bool value);
            static shared_ptr<Object> new_string(const string & value);

        protected:
            Type m_type;
            static std::map<Type,std::string> m_names;
        };
    }
}



#endif //PI_OBJECT_H
