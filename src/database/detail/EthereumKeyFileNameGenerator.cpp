#include "EthereumKeyFileNameGenerator.hpp"


namespace Xeth{



std::string EthereumKeyFileNameGenerator::operator()(const EthereumKey &key) const
{
    return operator()(key, boost::posix_time::microsec_clock::universal_time());
}

std::string EthereumKeyFileNameGenerator::operator()(const EthereumKey &key, time_t time) const
{
    return operator()(key, boost::posix_time::ptime(boost::gregorian::date(1970,1,1)) + boost::posix_time::seconds(static_cast<long>(time)));
}

std::string EthereumKeyFileNameGenerator::operator()(const EthereumKey &key, const boost::posix_time::ptime &time) const
{
    std::string path = "UTC--";
    path += boost::posix_time::to_iso_extended_string(time);
    path += "--";
    path += key.getAddress().toString();
    std::replace(path.begin(), path.end(), ':','-');
    return path;
}


}
