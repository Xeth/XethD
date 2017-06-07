#pragma once


#include "ethrpc/Provider.hpp"
#include "types/StealthKey.hpp"
#include "database/DataBase.hpp"


namespace Xeth{


class BlockChainScanIndexStoreAdapter
{
    public:
        BlockChainScanIndexStoreAdapter(DataBase &);


        size_t get(const char *);
        size_t get(const StealthKey &key);

        template<class Address>
        size_t get(const Address &);


        bool save(const char *, size_t);

        template<class Address>
        bool save(const Address &);

    private:
        ScanIndexStore &_store;
};


}


#include "BlockChainScanIndexStoreAdapter.ipp"
