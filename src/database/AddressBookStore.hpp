#pragma once

#include <json/value.h>

#include "detail/LevelDbStore.hpp"
#include "detail/ObservableStore.hpp"

namespace Xeth{


class AddressBookDataSerializer : public DataSerializer<Json::Value>
{
    public:
        typedef DataSerializer<Json::Value> Base;

    public:
        Json::Value operator()(const char *, const char *) const;
        bool operator()(const char *, const char *, Json::Value &) const;
        std::string operator()(const Json::Value &) const;
};



class AddressBookStore : 
    public boost::noncopyable,
    public ObservableStore<Json::Value, const char *, LevelDbStore<Json::Value, AddressBookDataSerializer> >
{

    public:
        typedef LevelDbStore<Json::Value, AddressBookDataSerializer> Store;
        typedef ObservableStore<Json::Value, const char *, Store> Base;
        typedef Store::Iterator Iterator;
        typedef Store::ReverseIterator ReverseIterator;
        typedef Store::DataType DataType;

    public:
        AddressBookStore();
        AddressBookStore(const std::string &);
        AddressBookStore(const boost::filesystem::path &);

        bool insert(const char *, const char *);
        bool replace(const char *, const char *);

        using Base::insert;
        using Base::replace;

};





}
