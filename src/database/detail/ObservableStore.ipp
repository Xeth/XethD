namespace Xeth{


template<class Value, class Key, class Store>
ObservableStore<Value, Key, Store>::ObservableStore()
{}


template<class Value, class Key, class Store>
template<class Arguments>
ObservableStore<Value, Key, Store>::ObservableStore(const Arguments &args) :
    Store(args)
{}


template<class Value, class Key, class Store>
ObservableStore<Value, Key, Store>::~ObservableStore()
{}


template<class Value, class Key, class Store>
template<class Callback>
void ObservableStore<Value, Key, Store>::onInsert(const Callback &callback)
{
    _emitter.registerInsertObserver(callback);
}


template<class Value, class Key, class Store>
template<class Callback>
void ObservableStore<Value, Key, Store>::onMove(const Callback &callback)
{
    _emitter.registerMoveObserver(callback);
}


template<class Value, class Key, class Store>
template<class Callback>
void ObservableStore<Value, Key, Store>::onReplace(const Callback &callback)
{
    _emitter.registerReplacObserver(callback);
}


template<class Value, class Key, class Store>
template<class Callback>
void ObservableStore<Value, Key, Store>::onRemove(const Callback &callback)
{
    _emitter.registerRemoveObserver(callback);
}



template<class Value, class Key, class Store>
bool ObservableStore<Value, Key, Store>::insert(const Key &key, const Value &value)
{
    if(Store::insert(key, value))
    {
        _emitter.emitInsertEvent(key, value);
        return true;
    }
    return false;
}


template<class Value, class Key, class Store>
bool ObservableStore<Value, Key, Store>::remove(const Key &key)
{
    if(Store::remove(key))
    {
        _emitter.emitRemoveEvent(key);
        return true;
    }
    return false;
}


template<class Value, class Key, class Store>
bool ObservableStore<Value, Key, Store>::move(const Key &oldKey, const Key &newKey)
{
    if(Store::move(oldKey, newKey))
    {
        _emitter.emitMoveEvent(oldKey, newKey);
        return true;
    }
    return false;
}


template<class Value, class Key, class Store>
bool ObservableStore<Value, Key, Store>::replace(const Key &key, const Value &value)
{
    if(Store::replace(key, value))
    {
        _emitter.emitReplaceEvent(key, value);
        return true;
    }
    return false;
}



}
