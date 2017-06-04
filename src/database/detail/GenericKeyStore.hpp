#pragma once 

#include "FileStore.hpp"
#include "StoreEventEmitter.hpp"


namespace Xeth{




template<class Key, class Address, class KeySerializer, class FileNameFactory, class FileMatcher>
class GenericKeyStore : 
    protected FileStore<Key, KeySerializer>
{

    public:
        typedef FileStore<Key, KeySerializer> Base;
        typedef typename Base::Iterator Iterator;
        typedef typename Base::Data Data;
        typedef typename Base::DataSerializer DataSerializer;

    public:
        GenericKeyStore(const std::string &path);
        GenericKeyStore(const boost::filesystem::path &path);

        bool replace(const Key &);
        bool insert(const Key &);

        Iterator find(const char *address) const;
        Iterator find(const Address &) const;

        Key get(const char *address) const;
        Key get(const Address &) const;

        using Base::begin;
        using Base::end;

        template<class Callback>
        void onInsert(const Callback &);

        template<class Callback>
        void onReplace(const Callback &);

    private:
        std::string makeAddress(const Key &) const;
        bool insert(const char *, const Key &);
        bool replace(const char *, const Key &);

    private:
        StoreEventEmitter<std::string, Key> _emitter;
        FileNameFactory _nameFactory;

};



}


#include "GenericKeyStore.ipp"
