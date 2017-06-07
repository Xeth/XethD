#pragma once

#include "ethrpc/Provider.hpp"
#include "ethrpc/BlockChain.hpp"

#include "AccountScanCriterion.hpp"
#include "StealthScanCriterion.hpp"
#include "BlockChainScanCriteria.hpp"


#include "detail/GenericScanner.hpp"
#include "detail/BlockChainScanIndexStoreAdapter.hpp"
#include "detail/BlockChainScanIndexEstimator.hpp"


namespace Xeth{



class BlockChainScanner : 
    public GenericScanner
    <
        BlockChainScanCriteria,
        Ethereum::Connector::BlockChain,
        BlockChainScanIndexStoreAdapter,
        BlockChainScanIndexEstimator
    >
{
    public:
        typedef GenericScanner
        <
            BlockChainScanCriteria,
            Ethereum::Connector::BlockChain,
            BlockChainScanIndexStoreAdapter,
            BlockChainScanIndexEstimator
        > Base;


    public:
        BlockChainScanner(Ethereum::Connector::Provider &, DataBase &, size_t scanChunk=100, size_t scanInterval=500);

        void addAddress(const std::string &);
        void addAddress(const std::string &, time_t);
        void addAddress(const Ethereum::Address &);
        void addStealthAddress(const StealthKey &);
        void addAddress(const Ethereum::Address &, time_t);
        void addStealthAddress(const StealthKey &, time_t);

};


}
