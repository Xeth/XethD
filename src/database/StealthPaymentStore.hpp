#pragma once 

#include <json/value.h>

#include "detail/LevelDbStore.hpp"
#include "detail/ObservableStore.hpp"
#include "detail/HexAddressNormalizer.hpp"

namespace Xeth{


class StealthPaymentStore : 
    public ObservableStore<Json::Value>
{
    public:
        typedef ObservableStore<Json::Value> Base;
        typedef Base::Iterator Iterator;
        typedef Base::ReverseIterator ReverseIterator;
        typedef Base::DataType DataType;

    public:
        StealthPaymentStore();
        StealthPaymentStore(const std::string &);
        StealthPaymentStore(const boost::filesystem::path &);

        Iterator find(const std::string &) const;
        Json::Value get(const std::string &) const;

        bool insert(const char *address, const char *stealth, const char *secret, const char *txid);
        bool insert(const Json::Value &);
        bool replace(const Json::Value &);

    private:
        std::string normalizedAddress(const std::string &) const;
        using Base::find;
        using Base::get;
        using Base::replace;

};



}
