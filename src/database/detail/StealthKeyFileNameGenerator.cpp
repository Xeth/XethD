#include "StealthKeyFileNameGenerator.hpp"

namespace Xeth{


std::string StealthKeyFileNameGenerator::operator()(const StealthKey &key) const
{
    StealthAddress address(key);
    return address.toString();
}


inline const std::string & StealthKeyFileNameGenerator::operator()(const std::string &address) const
{
    return address;
}



}
