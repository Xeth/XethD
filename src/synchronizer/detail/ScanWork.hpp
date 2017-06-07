#pragma once

#include "../ScanResult.hpp"


namespace Xeth{



template<class ScanCriteria, class Data, class ScanProgress>
class ScanWork
{
    public:
        ScanWork(ScanCriteria &, Data &, ScanResult &, ScanProgress &);

        void operator()();

    private:
        ScanCriteria &_criteria;
        Data &_data;
        ScanResult &_result;
        ScanProgress &_progress;
};




}


#include "ScanWork.ipp"
