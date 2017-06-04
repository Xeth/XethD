#include "ConfigStore.hpp"


namespace Xeth{


ConfigStore::ConfigStore()
{}

ConfigStore::ConfigStore(const char *path) :
    Base(path)
{}

ConfigStore::ConfigStore(const std::string &path) :
    Base(path)
{}

ConfigStore::ConfigStore(const boost::filesystem::path &path) :
    Base(path)
{}


bool ConfigStore::has(const char *key) const
{
    return Base::has(key);
}


std::string ConfigStore::get(const char *key) const
{
    return Base::get(key);
}





}
