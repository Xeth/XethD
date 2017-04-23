namespace Xeth{


template<class Callback>
void BitProfileStore::onInsert(const Callback &callback)
{
    _emitter.registerInsertObserver(callback);
}


template<class Callback>
void BitProfileStore::onRemove(const Callback &callback)
{
    _emitter.registerDeleteObserver(callback);
}



template<class Callback>
void BitProfileStore::onReplace(const Callback &callback)
{
    _emitter.registerReplaceObserver(callback);
}



}
