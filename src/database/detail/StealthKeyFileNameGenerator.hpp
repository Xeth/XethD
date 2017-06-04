#pragma once

#include <string>
#include "types/StealthKey.hpp"


namespace Xeth{


class StealthKeyFileNameGenerator
{
    public:
        std::string operator ()(const StealthKey &) const;
        const std::string & operator ()(const std::string &) const;
};


}


