#pragma once


#include <boost/signals2.hpp>


namespace Xeth{


class ScanProgressEventEmitter
{
    public:
        template<class Callback>
        void registerObserver(const Callback &);


        void emitProgress(double);

    private:
        boost::signals2::signal<void (double)> _observers;


};


}

#include "ScanProgressEventEmitter.ipp"
