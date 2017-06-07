#pragma once


#include "../ScanResult.hpp"


namespace Xeth{


template<class ScanIndexStore, class ScanCriteria>
class ScanIndexUpdater
{
    public:
        ScanIndexUpdater(ScanIndexStore &, ScanCriteria &);
        void operator()(const ScanResult &);

    private:
        ScanIndexStore &_store;
        ScanCriteria &_criteria;
};


}


#include "ScanIndexUpdater.ipp"
