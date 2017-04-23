#pragma once

#include <string>
#include <ctime>
#include <map>
#include <json/value.h>


#include "types/BigInt.hpp"
#include "types/StealthKey.hpp"
#include "types/TransactionCategory.hpp"


namespace Xeth{


class TransactionObjectBuilder
{
    public:

        void setDetails(const std::string &txid, const TransactionCategory &, const std::string &from, const std::string &to, const BigInt &amount, time_t timestamp = time(NULL));
        void setExtraData(const std::map<std::string, std::string> &);
        void setStealth(const Ethereum::Stealth::Address &);

        const Json::Value & build();

    private:
        Json::Value _data;
};


}
