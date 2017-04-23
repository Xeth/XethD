namespace Xeth{

template<class Key, class Address, class KeySerializer>
GenericKeyStore<Key, Address, KeySerializer>::GenericKeyStore(const std::string &path, const char *extension) : 
    Base(path, extension)
{}


template<class Key, class Address, class KeySerializer>
GenericKeyStore<Key, Address, KeySerializer>::GenericKeyStore(const boost::filesystem::path &path, const char *extension) : 
    Base(path, extension)
{}


template<class Key, class Address, class KeySerializer>
template<class Callback>
void GenericKeyStore<Key, Address, KeySerializer>::onInsert(const Callback &callback)
{
    _emitter.registerInsertObserver(callback);
}


template<class Key, class Address, class KeySerializer>
bool GenericKeyStore<Key, Address, KeySerializer>::replace(const Key &key)
{
    std::string address = makeAddress(key);
    if(Base::replace(address.c_str(), key))
    {
        _emitter.emitInsertEvent(address, key);
        return true;
    }
    return false;
}


template<class Key, class Address, class KeySerializer>
bool GenericKeyStore<Key, Address, KeySerializer>::replace(const Key &key, time_t)
{
    return replace(key);
}


template<class Key, class Address, class KeySerializer>
bool GenericKeyStore<Key, Address, KeySerializer>::insert(const Key &key, time_t)
{
    return insert(key);
}



template<class Key, class Address, class KeySerializer>
bool GenericKeyStore<Key, Address, KeySerializer>::insert(const Key &key) 
{
    std::string address = makeAddress(key);
    if(Base::insert(address.c_str(), key))
    {
        _emitter.emitInsertEvent(address, key);
        return true;
    }
    return false;
}


template<class Key, class Address, class KeySerializer>
Key GenericKeyStore<Key, Address, KeySerializer>::get(const char *address) const
{
    return Base::get(address);
}


template<class Key, class Address, class KeySerializer>
typename GenericKeyStore<Key, Address, KeySerializer>::Iterator GenericKeyStore<Key, Address, KeySerializer>::find(const char *address) const
{
    return Base::find(address);
}


template<class Key, class Address, class KeySerializer>
typename GenericKeyStore<Key, Address, KeySerializer>::Iterator GenericKeyStore<Key, Address, KeySerializer>::find(const Address &address) const
{
    return Base::find(address.toString().c_str());
}


template<class Key, class Address, class KeySerializer>
std::string GenericKeyStore<Key, Address, KeySerializer>::makeAddress(const Key &key) const
{
    Address address(key);
    return address.toString();
}





}
