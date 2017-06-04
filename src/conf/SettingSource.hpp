#pragma once


namespace Xeth{



class SettingSource
{
    public:
        virtual bool has(const char *) const = 0;
        virtual std::string get(const char *) const = 0;
};


}
