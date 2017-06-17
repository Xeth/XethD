#pragma once

#include <unistd.h>
#include "../ScanResult.hpp"
#include "ScanWork.hpp"


namespace Xeth{



template<class ScanCriteria, class Data, class ScanProgress>
class ScanWorkLoop : public ScanWork<ScanCriteria, Data, ScanProgress>
{
    public:
        typedef ScanWork<ScanCriteria, Data, ScanProgress> Base;

    public:
        ScanWorkLoop(ScanCriteria &, Data &, ScanResult &, ScanProgress &, unsigned sleepTime = 5);

        void operator()();

    private:
        unsigned _sleepTime;
};




}


#include "ScanWorkLoop.ipp"
