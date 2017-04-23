#include "DataSerializer.hpp"


namespace Xeth{

/* Json::Value serialization */

Json::Value DataSerializer<Json::Value>::operator()(const char *key, const char *value) const
{
    Json::Value result;
    operator()(key, value, result);
    return result;
}


bool DataSerializer<Json::Value>::operator()(const char *key, const char *value, Json::Value &result) const
{
    Json::Reader reader;
    return reader.parse(content, result, false);
}


std::string DataSerializer<Json::Value>::operator ()(const Json::Value &object) const
{
    Json::FastWriter writer;
    return writer.write(object);
}


/* std::string serialization */

std::string DataSerializer<std::string>::operator()(const char *key, const char *value) const
{
    return value;
}


bool DataSerializer<std::string>::operator()(const char *key, const char *value, std::string &result) const
{
    result = value;
    return true;
}


std::string DataSerializer<std::string>::operator()(const std::string &value) const
{
    return value;
}





}
