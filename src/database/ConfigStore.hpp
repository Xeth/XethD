#pragma once 

#include <string>

#include "detail/LevelDbStore.hpp"
#include "detail/ObservableStore.hpp"
#include "conf/SettingSource.hpp"


namespace Xeth {


class ConfigStore : 
    public SettingSource,
    public ObservableStore<std::string>
{
    public:
        typedef ObservableStore<std::string> Base;

    public:
        ConfigStore();
        ConfigStore(const char *path);
        ConfigStore(const std::string &);
        ConfigStore(const boost::filesystem::path &path);
};

}
