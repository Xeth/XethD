#include "AddressBookStore.hpp"

namespace Xeth{

Json::Value AddressBookDataSerializer::operator ()(const char *key, const char *value) const
{
    Json::Value result;
    operator()(key, value, result);
    return result;
}

bool AddressBookDataSerializer::operator ()(const char *key, const char *value, Json::Value &result) const
{
    Base::operator()(key, value, result);
    result["alias"] = key;
    return true;
}


std::string AddressBookDataSerializer::operator ()(const Json::Value &object) const
{
    return Base::operator()(object);
}


AddressBookStore::AddressBookStore()
{}


AddressBookStore::AddressBookStore(const std::string &path) : Base(path)
{}


AddressBookStore::AddressBookStore(const boost::filesystem::path &path) : Base(path)
{}


bool AddressBookStore::insert(const char *alias, const char *address)
{
    Json::Value object;
    object["address"] = address;
    return Base::insert(alias, object);
}


bool AddressBookStore::replace(const char *alias, const char *address)
{
    Json::Value object;
    object["address"] = address;
    return Base::replace(alias, object);
}




}
