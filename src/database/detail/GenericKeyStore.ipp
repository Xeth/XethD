namespace Xeth{

template<class Key, class Address, class KeySerializer, class FileNameFactory, class FileMatcher>
GenericKeyStore<Key, Address, KeySerializer, FileNameFactory, FileMatcher>::GenericKeyStore(const std::string &path) : 
    Base(path)
{}


template<class Key, class Address, class KeySerializer, class FileNameFactory, class FileMatcher>
GenericKeyStore<Key, Address, KeySerializer, FileNameFactory, FileMatcher>::GenericKeyStore(const boost::filesystem::path &path) : 
    Base(path)
{}


template<class Key, class Address, class KeySerializer, class FileNameFactory, class FileMatcher>
template<class Callback>
void GenericKeyStore<Key, Address, KeySerializer, FileNameFactory, FileMatcher>::onInsert(const Callback &callback)
{
    _emitter.registerInsertObserver(callback);
}

template<class Key, class Address, class KeySerializer, class FileNameFactory, class FileMatcher>
template<class Callback>
void GenericKeyStore<Key, Address, KeySerializer, FileNameFactory, FileMatcher>::onReplace(const Callback &callback)
{
    _emitter.registerRelpaceObserver(callback);
}





template<class Key, class Address, class KeySerializer, class FileNameFactory, class FileMatcher>
bool GenericKeyStore<Key, Address, KeySerializer, FileNameFactory, FileMatcher>::replace(const Key &key)
{
    return replace(makeAddress(key), key);
}


template<class Key, class Address, class KeySerializer, class FileNameFactory, class FileMatcher>
bool GenericKeyStore<Key, Address, KeySerializer, FileNameFactory, FileMatcher>::replace(const char *address, const Key &key)
{

    Iterator it = find(address);

    if(it != end())
    {
        if(Base::replace(it, key))
        {
            _emitter.emitReplaceEvent(address, key);
            return true;
        }
    }
    else
    {
        return insert(address, key);
    }
    return false;
}

template<class Key, class Address, class KeySerializer, class FileNameFactory, class FileMatcher>
std::string GenericKeyStore<Key, Address, KeySerializer, FileNameFactory, FileMatcher>::makeAddress(const Key &key) const
{
    Address address(key);
    return address.toString();
}

template<class Key, class Address, class KeySerializer, class FileNameFactory, class FileMatcher>
bool GenericKeyStore<Key, Address, KeySerializer, FileNameFactory, FileMatcher>::insert(const Key &key) 
{
    return insert(makeAddress(key), key);
}


template<class Key, class Address, class KeySerializer, class FileNameFactory, class FileMatcher>
bool GenericKeyStore<Key, Address, KeySerializer, FileNameFactory, FileMatcher>::insert(const char *address, const Key &key) 
{
    if(Base::insert(_nameFactory(address), key))
    {
        _emitter.emitInsertEvent(address, key);
        return true;
    }
    return false;
}


template<class Key, class Address, class KeySerializer, class FileNameFactory, class FileMatcher>
Key GenericKeyStore<Key, Address, KeySerializer, FileNameFactory, FileMatcher>::get(const char *address) const
{
    Iterator it = find(address);
    if(it == end())
    {
        throw std::runtime_error("key not found");
    }
    return *it;
}


template<class Key, class Address, class KeySerializer, class FileNameFactory, class FileMatcher>
typename GenericKeyStore<Key, Address, KeySerializer, FileNameFactory, FileMatcher>::Iterator GenericKeyStore<Key, Address, KeySerializer, FileNameFactory, FileMatcher>::find(const char *address) const
{

    FileMatcher matcher(address);
    Iterator it = find(matcher), e = end();
    if(it != e)
    {
        //extra check
        if(it->getAddress().toString() != address)
        {
            return e;
        }
    }
    return it;
}


template<class Key, class Address, class KeySerializer, class FileNameFactory, class FileMatcher>
typename GenericKeyStore<Key, Address, KeySerializer, FileNameFactory, FileMatcher>::Iterator GenericKeyStore<Key, Address, KeySerializer, FileNameFactory, FileMatcher>::find(const Address &address) const
{
    return Base::find(address.toString().c_str());
}









}
