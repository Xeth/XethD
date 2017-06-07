#include "BlockChainScanIndexEstimator.hpp"


namespace Xeth{


BlockChainScanIndexEstimator::BlockChainScanIndexEstimator(Ethereum::Connector::Provider &provider) :
    _blockchain(provider)
{}



size_t BlockChainScanIndexEstimator::estimateIndex(time_t creationTime)
{
    return (creationTime > 1438266388) ? (creationTime - 1438266388)/20 : 0;
}


size_t BlockChainScanIndexEstimator::getLastIndex()
{
    return _blockchain.getHeight();
}


}
