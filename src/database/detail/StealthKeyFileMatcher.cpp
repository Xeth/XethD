#include "StealthKeyFileMatcher.hpp"


namespace Xeth{



StealthKeyFileMatcher::StealthKeyFileMatcher(const char *address) : _address(address)
{}


bool StealthKeyFileMatcher::operator()(const boost::filesystem::path &path) const
{
    return path.filename().string() == _address;
}


}
