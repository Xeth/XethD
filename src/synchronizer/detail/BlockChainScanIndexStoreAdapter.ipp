namespace Xeth{


template<class Address>
size_t BlockChainScanIndexStoreAdapter::get(const Address &address)
{
    return get(address.toString().c_str());
}


template<class Address>
bool BlockChainScanIndexStoreAdapter::save(const Address &address)
{
    return save(address.toString().c_str());
}


}
