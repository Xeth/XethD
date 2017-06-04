#pragma once


#include <string>
#include <boost/filesystem.hpp>


namespace Xeth{


class StealthKeyFileMatcher
{
    public:
        StealthKeyFileMatcher(const char *);
        bool operator()(const boost::filesystem::path &path) const;

    private:
        std::string _address;
};


}

