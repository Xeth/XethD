#pragma once


#include <json/value.h>
#include <stdint.h>


namespace Xeth{


Json::Value::const_iterator moveBack(const Json::Value::const_iterator end, size_t count);


}
