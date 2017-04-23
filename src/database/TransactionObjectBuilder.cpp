#include "TransactionObjectBuilder.hpp"


namespace Xeth{


void TransactionObjectBuilder::setDetails(const std::string &hash, const TransactionCategory &category, const std::string &from, const std::string &to, const BigInt &amount, time_t timestamp)
{
    _data["category"] = category.toString();
    _data["hash"] =  hash;
    _data["from"] = from;
    _data["to"] = to;
    _data["amount"] = boost::lexical_cast<std::string>(amount);
    _data["timestamp"] = (int)timestamp;
}


void TransactionObjectBuilder::setStealth(const Ethereum::Stealth::Address &address)
{
    _data["stealth"] = address.toString();
}


void TransactionObjectBuilder::setExtraData(const std::map<std::string, std::string> &data)
{
    for(std::map<std::string, std::string>::const_iterator it = data.begin(), end = data.end(); it!=end; ++it)
    {
        _data[it->first] = it->second;
    }
}


const Json::Value & TransactionObjectBuilder::build()
{
    return _data;
}


}
