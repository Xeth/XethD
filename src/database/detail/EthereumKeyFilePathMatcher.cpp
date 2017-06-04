#include "EthereumKeyFilePathMatcher.hpp"


namespace Xeth{


EthereumKeyFilePathMatcher::EthereumKeyFilePathMatcher(const char *address) :
    _pattern(makePattern(address)),
    _regex(_pattern, boost::regex::icase)
{}



std::string EthereumKeyFilePathMatcher::makePattern(const char *address) const
{
    std::string pattern = "--";
    if(address[0]=='0'&&address[1]=='x')
    {
        address += 2;
    }

    std::string addr = address;
    std::transform(addr.begin(), addr.end(), addr.begin(), ::tolower);

    pattern += addr;
    pattern += '$';
    return pattern;
}



bool EthereumKeyFilePathMatcher::operator()(const boost::filesystem::path &path) const
{
    boost::smatch match;
    return boost::regex_search(path.filename().string(), match, _regex);
}


}
