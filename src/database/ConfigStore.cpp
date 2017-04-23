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






}
