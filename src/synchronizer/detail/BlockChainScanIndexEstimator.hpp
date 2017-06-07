#pragma once


#include "ethrpc/Provider.hpp"
#include "ethrpc/BlockChain.hpp"


namespace Xeth{


class BlockChainScanIndexEstimator
{
    public:
        BlockChainScanIndexEstimator(Ethereum::Connector::Provider &provider);
        size_t estimateIndex(time_t);
        size_t getLastIndex();


    private:
        Ethereum::Connector::BlockChain _blockchain;
};



}
