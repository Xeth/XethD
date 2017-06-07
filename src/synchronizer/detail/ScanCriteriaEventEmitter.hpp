#pragma once


#include <boost/signals2.hpp>
#include "../ScanResult.hpp"


namespace Xeth{


class ScanCriteriaEventEmitter
{
    public:
        template<class Callback>
        void registerPartialScanResultObserver(const Callback &);

        template<class Callback>
        void registerScanResultObserver(const Callback &);


        void emitPartialScanResultEvent(const PartialScanResult &);
        void emitScanResultEvent(const ScanResult &);

    private:
        boost::signals2::signal<void (const PartialScanResult &)> _partialScanResultObservers;
        boost::signals2::signal<void (const ScanResult &)> _scanResultObservers;


};


}

#include "ScanCriteriaEventEmitter.ipp"
