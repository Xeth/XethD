namespace Xeth{


template<class Callback>
void TransactionStore::onInsert(const Callback &callback)
{
    _emitter.registerInsertObserver(callback);
}


}
