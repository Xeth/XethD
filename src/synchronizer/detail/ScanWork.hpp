#pragma once

#include <boost/thread.hpp>
#include "../ScanResult.hpp"


namespace Xeth{



template<class ScanCriteria, class Data, class ScanProgress>
class ScanWork
{
    public:
        ScanWork(ScanCriteria &, Data &, ScanResult &, ScanProgress &);

        void operator()();
        void assign(const boost::thread::id &);
        void assign();

        bool isAssigned() const;
        boost::thread::id * const getAssignedThread() const;

    protected:
        void execute();

    private:
        ScanCriteria &_criteria;
        Data &_data;
        ScanResult &_result;
        ScanProgress &_progress;
        boost::thread::id * const _thread;
};




}


#include "ScanWork.ipp"
