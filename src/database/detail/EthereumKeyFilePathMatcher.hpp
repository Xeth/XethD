#pragma once 

#include <string>
#include <boost/regex.hpp> 
#include <boost/filesystem.hpp>


namespace Xeth{



class EthereumKeyFilePathMatcher
{
    public:
        EthereumKeyFilePathMatcher(const char *);
        bool operator ()(const boost::filesystem::path &) const;

    private:
        std::string makePattern(const char *) const;

    private:
        std::string _pattern;
        boost::regex _regex;
};




}
