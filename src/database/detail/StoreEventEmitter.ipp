namespace Xeth{


template<class Key, class Data>
template<class Callback>
void StoreEventEmitter<Key, Data>::registerInsertObserver(const Callback &observer)
{
    _insertObservers.connect(observer);
}


template<class Key, class Data>
template<class Callback>
void StoreEventEmitter<Key, Data>::registerDeleteObserver(const Callback &observer)
{
    _deleteObservers.connect(observer);
}


template<class Key, class Data>
template<class Callback>
void StoreEventEmitter<Key, Data>::registerReplaceObserver(const Callback &observer)
{
    _replaceObservers.connect(observer);
}

template<class Key, class Data>
template<class Callback>
void StoreEventEmitter<Key, Data>::registerMoveObserver(const Callback &observer)
{
    _moveObservers.connect(observer);
}


template<class Key, class Data>
void StoreEventEmitter<Key, Data>::emitInsertEvent(const Key &key, const Data &data)
{
    _insertObservers(key, data);
}

template<class Key, class Data>
void StoreEventEmitter<Key, Data>::emitReplaceEvent(const Key &key, const Data &data)
{
    _replaceObservers(key, data);
}


template<class Key, class Data>
void StoreEventEmitter<Key, Data>::emitMoveEvent(const Key &key, const Key &key2)
{
    _moveObservers(key, key2);
}


template<class Key, class Data>
void StoreEventEmitter<Key, Data>::emitDeleteEvent(const Key &key)
{
    _deleteObservers(key);
}


}
