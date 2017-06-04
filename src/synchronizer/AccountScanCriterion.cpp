#include "AccountScanCriterion.hpp"


namespace Xeth{


AccountScanCriterion::AccountScanCriterion(const char *address) :
    ScanCriterion(address)
{
    HexAddressNormalizer normalizer;
    normalizer(_address, _address);
    _address.insert(0, "0x"); //add prefix
}

void AccountScanCriterion::processHeader
(
    size_t,
    const std::string &hash,
    const std::string &miner,
    const BigInt &amount,
    time_t timestamp,
    ScanResult &result
)
{
    if(miner == _address && _address.size())
    {
        saveTransaction(TransactionCategory::Mined, hash, "", miner, amount, timestamp, result);
    }
}

void AccountScanCriterion::processTransaction
(
    const std::string &hash,
    const std::string &from,
    const std::string &to,
    const BigInt &amount,
    const std::string &,
    time_t timestamp,
    ScanResult &result
)
{
    if(_address.size())
    {
        if(from == _address)
        {
            saveTransaction(TransactionCategory::Sent, hash, from, to, amount, timestamp, result);
        }
        else if(to == _address)
        {
            saveTransaction(TransactionCategory::Received, hash, from, to, amount, timestamp, result);
        }
    }
}

void AccountScanCriterion::saveTransaction
(
    const TransactionCategory &category,
    const std::string &hash,
    const std::string &from,
    const std::string &to,
    const BigInt &amount,
    time_t timestamp,
    ScanResult &result
)
{
    Json::Value obj;
    obj["category"] = category.toString();
    obj["hash"] = hash;
    if(from.size())
    {
        obj["from"] = from;
    }
    obj["to"] = to;
    obj["amount"] = boost::lexical_cast<std::string>(amount);
    obj["timestamp"]  = timestamp;

    result.transactions.append(obj);
}





}
