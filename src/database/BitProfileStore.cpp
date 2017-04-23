#include "BitProfileStore.hpp"


namespace Xeth{


BitProfileStore::BitProfileStore(BitProfile::Network net) :
    _store(net)
{}


BitProfileStore::Iterator BitProfileStore::find(const std::string &uri) const
{
    return _store.find(uri);
}

BitProfileStore::Iterator BitProfileStore::find(const char *uri) const
{
    return _store.find(uri);
}

BitProfileStore::Iterator BitProfileStore::begin() const
{
    return _store.begin();
}


BitProfileStore::Iterator BitProfileStore::end() const
{
    return _store.end();
}

bool BitProfileStore::rename(const BitProfile::Profile::URI &old, const BitProfile::Profile::URI &uri)
{
    if(_store.changeProfileURI(old, uri))
    {
        _emitter.emitMoveEvent(old.toString(), uri.toString());
        return true;
    }
    return false;
}


bool BitProfileStore::insert(const BitProfile::ProfileDescriptor &descriptor)
{
    if(_store.insert(descriptor))
    {
        _emitter.emitInsertEvent(descriptor.getURI(), descriptor);
        return true;
    }

    return false;
}


bool BitProfileStore::remove(const BitProfile::Profile::URI &uri)
{
    if(_store.remove(uri))
    {
        _emitter.emitDeleteEvent(uri.toString());
        return true;
    }
    return false;
}


bool BitProfileStore::remove(const std::string &uri)
{
    if(_store.remove(uri))
    {
        _emitter.emitDeleteEvent(uri);
        return true;
    }
    return false;
}


}
