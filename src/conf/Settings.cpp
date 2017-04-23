
#include <boost/filesystem.hpp>

#include "Settings.hpp"
#include "io/Directory.hpp"


namespace Xeth{


void Settings::addSource(const SourcePtr &source)
{
    _sources.push_back(source);
}

bool Settings::has(const char *name) const
{

    for(SourceMap::const_iterator it = _sources.begin(), end = _sources.end(); it != end; ++it)
    {
        const SourcePtr & source = *it;
        if(source->has(name))
        {
            return true;
        }
    }

    DataMap::const_iterator it= _data.find(name);
    return it!=_data.end();
}


const char * Settings::get(const char *name) const
{

    for(SourceMap::const_iterator it = _sources.begin(), end = _sources.end(); it != end; ++it)
    {
        const SourcePtr & source = *it;
        if(source->has(name))
        {
            return source->get(name);
        }
    }

    DataMap::const_iterator it= _data.find(name);
    if(it==_data.end())
    {
        std::stringstream err;
        err<<"settings ["<<name<<"] not found";
        throw std::runtime_error(err.str());
    }
    return it->second.c_str();
}




const char * Settings::get(const char *name, const char *defaultVal) const
{
    for(SourceMap::const_iterator it = _sources.begin(), end = _sources.end(); it != end; ++it)
    {
        const SourcePtr & source = *it;
        if(source->has(name))
        {
            return source->get(name);
        }
    }

    DataMap::const_iterator it= _data.find(name);
    if(it==_data.end())
    {
        return defaultVal;
    }
    return it->second.c_str();
}




void Settings::set(const char *name, const char *value)
{
    _data[name] = value;
}



void Settings::readConfigFile()
{
    boost::filesystem::path path = Directory::GetDefaultPath();
    path /= "xeth.conf";
    if(boost::filesystem::exists(path))
    {
        readFile(path.string().c_str());
    }
}


void Settings::readFile(const char *path)
{
    std::ifstream file(path);
    boost::program_options::options_description desc;
    set(boost::program_options::parse_config_file(file, desc, true));
}


void Settings::set(const boost::program_options::parsed_options &parsed)
{
    BOOST_FOREACH(const option &opt, parsed.options)
    {
        _data[opt.string_key.c_str()] = opt.value.size() ? opt.value.begin()->c_str() : "1";
    }
}


void Settings::readCommandLineArgs(int argc, char **argv)
{
    boost::program_options::options_description desc;
    set(boost::program_options::command_line_parser(argc, argv).options(desc).allow_unregistered().run());
}

std::vector<std::string> Settings::getVector(const char *name) const
{
    std::vector<std::string> result;
    getVector(name, result);
    return result;
}

}
