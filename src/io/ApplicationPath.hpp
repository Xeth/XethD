#pragma once

#include <string>
#include <boost/filesystem.hpp>

namespace Xeth{


class ApplicationPath
{
    public:
        static std::string EthereumData();
        static std::string XethData();
        static std::string Vendors();
        static std::string LocalVendors();
        static std::string Keys();
        static std::string TestnetKeys();
        static std::string StealthKeys();
        static std::string TestnetStealthKeys();
};


}
