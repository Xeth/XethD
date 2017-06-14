#include "BlockChainScanner.hpp"



namespace Xeth{




BlockChainScanner::BlockChainScanner(SynchronizerContext &context):
    Base(context)
{}


void BlockChainScanner::addAddress(const std::string &address)
{
    Base::addScanCriterion<AccountScanCriterion>(address);
}

void BlockChainScanner::addAddress(const std::string &address, time_t creationTime)
{
    Base::addScanCriterion<AccountScanCriterion>(address, creationTime);
}


void BlockChainScanner::addAddress(const Ethereum::Address &address)
{
    Base::addScanCriterion<AccountScanCriterion>(address);
}

void BlockChainScanner::addAddress(const Ethereum::Address &address, time_t creationTime)
{
    Base::addScanCriterion<AccountScanCriterion>(address, creationTime);
}


void BlockChainScanner::addStealthAddress(const StealthKey &key)
{
    Base::addScanCriterion<StealthScanCriterion>(key);
}


void BlockChainScanner::addStealthAddress(const StealthKey &key, time_t creationTime)
{
    Base::addScanCriterion<StealthScanCriterion>(key, creationTime);
}


}
