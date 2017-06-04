#include "JsonUtils.hpp"


namespace Xeth{

Json::Value::const_iterator moveBack(const Json::Value::const_iterator end, size_t count)
{
    Json::Value::const_iterator it = end;
    for(size_t i=0; i<count; i++)
    {
        it --;
    }
    return it;
}


}
