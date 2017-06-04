#include "StealthScanCriterion.hpp"


namespace Xeth{


using Ethereum::PublicKeySerializer;
using Ethereum::Data;
using Ethereum::Literal;
using Ethereum::HexEncoder;


StealthScanCriterion::StealthScanCriterion(const StealthKey &key) :
    ScanCriterion(makeAddress(key)),
    _key(key)
{}

StealthScanCriterion::StealthScanCriterion(const StealthKey &key, const Ethereum::Stealth::Address &address) :
    ScanCriterion(address.toString()),
    _key(key)
{}


std::string StealthScanCriterion::makeAddress(const StealthKey &key) const
{
    Ethereum::Stealth::Address address(key);
    std::string str =  address.toString();
    return str;
}


void StealthScanCriterion::uncoverStealthPayment
(
    const std::string &hash,
    const std::string &from,
    const std::string &to,
    const BigInt &amount,
    const char *data,
    size_t dataSize,
    time_t timestamp,
    ScanResult &result
)
{
    PublicKeySerializer serializer;
    try
    {
        Ethereum::PublicKey ephem = serializer.unserialize(data, dataSize);
        StealthResolver resolver(_key);
        Ethereum::Stealth::SharedSecret secret;
        if(resolver.uncover(Ethereum::Address(to), ephem, secret))
        {
            Json::Value tx;
            std::string stealth = getAddress();

            tx["category"] = TransactionCategory::ToString(TransactionCategory::Received);
            tx["hash"] = hash;
            tx["from"] = from;
            tx["to"] = to;
            tx["amount"] = boost::lexical_cast<std::string>(amount);
            tx["timestamp"] = (int)timestamp;
            tx["stealth"] = stealth;
            result.transactions.append(tx);

            HexEncoder encoder;
            Json::Value sp;
            sp["address"] = to;
            sp["secret"] = encoder.encode(secret.begin(), secret.end());
            sp["txid"] = hash;
            sp["stealth"] = stealth;
            tx["timestamp"] = (int)timestamp;
            result.stealthPayments.append(sp);
        }
    }
    catch(...)
    {}
}

void StealthScanCriterion::processTransaction
(
    const std::string &hash,
    const std::string &from,
    const std::string &to,
    const BigInt &amount,
    const std::string &data,
    time_t timestamp,
    ScanResult &result
)
{
    size_t dataSize = data.size();

    if(dataSize == 66 || dataSize == 130 || ((dataSize == 68 || dataSize == 132)&&data[0]=='0'&&(data[1]=='x'||data[1]=='X')))
    {
        uncoverStealthPayment(hash, from, to, amount, data.data(), dataSize, timestamp, result);
    }
}


}
