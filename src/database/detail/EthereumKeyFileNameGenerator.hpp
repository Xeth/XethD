#pragma once


#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/conversion.hpp>

#include "types/EthereumKey.hpp"


namespace Xeth{


class EthereumKeyFileNameGenerator
{
    public:
        std::string operator()(const EthereumKey &) const;
        std::string operator()(const EthereumKey &, time_t time) const;
        std::string operator()(const EthereumKey &, const boost::posix_time::ptime &time) const;
};


}
