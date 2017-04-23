#include "StealthPaymentStore.hpp"


namespace Xeth{


StealthPaymentStore::StealthPaymentStore()
{}


StealthPaymentStore::StealthPaymentStore(const std::string &path) : 
    Base(path)
{}


StealthPaymentStore::StealthPaymentStore(const boost::filesystem::path &path) : 
    Base(path)
{}


std::string StealthPaymentStore::normalizedAddress(const std::string &address) const
{
    HexAddressNormalizer normalizer;
    return normalizer(address);
}


StealthPaymentStore::Iterator StealthPaymentStore::find(const std::string &address) const
{
    return Base::find(normalizedAddress(address).c_str());
}

Json::Value StealthPaymentStore::get(const std::string &address) const
{
    return Base::get(normalizedAddress(address).c_str());
}


bool StealthPaymentStore::insert(const char *address, const char *stealth, const char *secret, const char *txid)
{
    Json::Value object;

    object["address"] = address;
    object["stealth"] = stealth;
    object["secret"] = secret;
    object["txid"] = txid;

    return Base::insert(normalizedAddress(address).c_str(), object);
}


bool StealthPaymentStore::insert(const Json::Value &obj)
{
    return Base::insert(normalizedAddress(obj["address"].asString()).c_str(), obj);
}

bool StealthPaymentStore::replace(const Json::Value &obj)
{
    return Base::replace(normalizedAddress(obj["address"].asString()).c_str(), obj); //ToDo: optimize it !!!
}



}
