#pragma once

#include <string>

#include <boost/lexical_cast.hpp>
#include <json/value.h>
#include <json/reader.h>
#include <json/writer.h>



namespace Xeth{



template<class Data>
class DataSerializer
{
    public:
        Data operator()(const char *, const char *) const;
        bool operator()(const char *, const char *, Data &) const;
        std::string operator ()(const Data &) const;
};



template<>
class DataSerializer<Json::Value>
{

    public:

        QJsonObject operator()(const char *, const char *) const;
        bool operator()(const char *, const char *, Json::Value &) const;
        std::string operator ()(const Json::Value &) const;
};




template<>
class DataSerializer<std::string>
{
    public:
        std::string operator()(const char *, const char *) const;
        bool operator()(const char *, const char *, std::string &) const;
        std::string operator ()(const std::string &) const;
};


}

#include "DataSerializer.ipp"
