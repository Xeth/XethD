#include "ScanResult.hpp"



namespace Xeth{


PartialScanResult MakePartialScanResult
(
    Json::Value::const_iterator tBegin,
    Json::Value::const_iterator tEnd,
    Json::Value::const_iterator sBegin,
    Json::Value::const_iterator sEnd,
    size_t lastBlock
)
{
    PartialScanResult result;
    result.transactions = std::make_pair(tBegin, tEnd);
    result.stealthPayments = std::make_pair(sBegin, sEnd);
    result.lastBlock = lastBlock;
    return result;
}


PartialScanResult MakePartialScanResult(const ScanResult &result, size_t txCount, size_t stCount, size_t blockIndex)
{
    Json::Value::const_iterator txEnd = result.transactions.end();
    Json::Value::const_iterator stEnd = result.stealthPayments.end();
    PartialScanResult partial;

    partial.transactions = std::make_pair(moveBack(txEnd, txCount), txEnd);
    partial.stealthPayments = std::make_pair(moveBack(stEnd, stCount), stEnd);
    partial.lastBlock = blockIndex;
    return partial;
}




}


