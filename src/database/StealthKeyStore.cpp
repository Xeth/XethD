#include "StealthKeyStore.hpp"

namespace Xeth{

StealthKeyStore::StealthKeyStore(const std::string &path) : 
    Base(path, "skey")
{}

StealthKeyStore::StealthKeyStore(const boost::filesystem::path &path) : 
    Base(path, "skey")
{}





}
