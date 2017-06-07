#include "ScanResultSaver.hpp"

namespace Xeth{


ScanResultSaver::ScanResultSaver(DataBase &database) :
    _database(database)
{}



void ScanResultSaver::operator()(const PartialScanResult &result)
{
    TransactionStore & transactionStore = _database.getTransactions();
    StealthPaymentStore & stealthPaymentStore = _database.getStealthPayments();

    for(Json::Value::const_iterator it = result.transactions.first; it!=result.transactions.second; ++it)
    {
        transactionStore.insert(*it);
    }

    for(Json::Value::const_iterator it = result.stealthPayments.first; it!=result.stealthPayments.second; ++it)
    {
        stealthPaymentStore.replace(*it);
    }
}


}
