#pragma once 

#include "FileStore.hpp"
#include "StoreEventEmitter.hpp"


namespace Xeth{


template<class Key, class Address, class KeySerializer>
class GenericKeyStore : 
    protected FileStore<Key, KeySerializer>
{

    public:
        typedef FileStore<Key, KeySerializer> Base;
        typedef typename Base::Iterator Iterator;
        typedef typename Base::Data Data;
        typedef typename Base::DataSerializer DataSerializer;

    public:
        GenericKeyStore(const std::string &path, const char *extension);
        GenericKeyStore(const boost::filesystem::path &path, const char *extension);

        bool replace(const Key &);
        bool replace(const Key &, time_t);

        bool insert(const Key &);
        bool insert(const Key &, time_t);

        Iterator find(const char *address) const;
        Iterator find(const Address &) const;

        Key get(const char *address) const;

        using Base::begin;
        using Base::end;

        template<class Callback>
        void onInsert(const Callback &);

        template<class Callback>
        void onReplace(const Callback &);

    private:
        std::string makeAddress(const Key &) const;

    private:
        StoreEventEmitter<std::string, Key> _emitter;

};



}


#include "GenericKeyStore.ipp"
