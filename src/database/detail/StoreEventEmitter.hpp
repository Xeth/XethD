#pragma once


#include <boost/signals2.hpp>


namespace Xeth{


template<class Key, class Data>
class StoreEventEmitter
{
    public:
        template<class Callback>
        void registerInsertObserver(const Callback &);

        template<class Callback>
        void registerDeleteObserver(const Callback &);

        template<class Callback>
        void registerReplaceObserver(const Callback &);

        template<class Callback>
        void registerMoveObserver(const Callback &);

        void emitInsertEvent(const Key &, const Data &);
        void emitMoveEvent(const Key &, const Key &);
        void emitReplaceEvent(const Key &, const Data &);
        void emitDeleteEvent(const Key &);

    private:
        boost::signals2::signal<void (const Key &, const Data &)> _insertObservers;
        boost::signals2::signal<void (const Key &, const Data &)> _replaceObservers;
        boost::signals2::signal<void (const Key &, const Key &)>  _moveObservers;
        boost::signals2::signal<void (const Key &)> _deleteObservers;


};


}

#include "StoreEventEmitter.ipp"
