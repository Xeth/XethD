#pragma once


#include "StoreEventEmitter.hpp"



namespace Xeth{



template<class Value, class Key = const char *, class Store = LevelDbStore<Value, Xeth::DataSerializer<Value>, Key> >
class ObservableStore : public Store
{
    public:
        ObservableStore();

        template<class Arguments>
        ObservableStore(const Arguments &);

        ~ObservableStore();

        bool insert(const Key &, const Value &);
        bool remove(const Key &);
        bool move(const Key &oldKey, const Key &newKey);
        bool replace(const Key &key, const Value &);



        template<class Callback>
        void onInsert(const Callback &);

        template<class Callback>
        void onMove(const Callback &);


        template<class Callback>
        void onRemove(const Callback &);


        template<class Callback>
        void onReplace(const Callback &);


    private:
        StoreEventEmitter<Key, Value> _emitter;
};



}


#include "ObservableStore.ipp"
