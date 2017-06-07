#pragma once

#include <unistd.h>
#include "../ScanResult.hpp"


namespace Xeth{



template<class ScanCriteria, class Data, class ScanProgress>
class ScanWorkLoop
{
    public:
        ScanWorkLoop(ScanCriteria &, Data &, ScanResult &, ScanProgress &, unsigned sleepTime = 5);

        void operator()();

    private:
        ScanCriteria &_criteria;
        Data &_data;
        ScanResult &_result;
        ScanProgress &_progress;
        unsigned _sleepTime;
};




}


#include "ScanWorkLoop.ipp"
