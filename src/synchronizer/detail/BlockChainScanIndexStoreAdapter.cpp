#include "BlockChainScanIndexStoreAdapter.hpp"


namespace Xeth{


BlockChainScanIndexStoreAdapter::BlockChainScanIndexStoreAdapter(DataBase &database) :
    _store(database.getScanIndex())
{}



size_t BlockChainScanIndexStoreAdapter::get(const char *address)
{
    return _store.get(address);
}



bool BlockChainScanIndexStoreAdapter::save(const char *address, size_t index)
{
    return _store.insert(address, index);
}


size_t BlockChainScanIndexStoreAdapter::get(const StealthKey &key)
{
    StealthAddress address(key);
    return get(address.toString().c_str());
}


}
