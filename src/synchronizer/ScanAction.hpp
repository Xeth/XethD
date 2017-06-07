#pragma once

#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>

#include "ScanProgress.hpp"
#include "ScanResult.hpp"

#include "detail/ScanWork.hpp"
#include "detail/ScanWorkLoop.hpp"

namespace Xeth{


template<class ScanCriteria>
class ScanAction
{
    public:
        ScanAction();

        template<class Data>
        void start(Data &, ScanCriteria &, ScanProgress &);


        template<class Data>
        void loop(Data &, ScanCriteria &, ScanProgress &, unsigned sleepTime);

        void stop();
        void waitToComplete();
        bool isActive() const;

        const ScanResult & getResult() const;

    private:
        void resetResult();


    private:
        ScanResult _result;
        boost::shared_ptr<boost::thread> _thread;

};


}


#include "ScanAction.ipp"
