#pragma once

#include <stdlib.h>
#include "detail/ScanProgressEventEmitter.hpp"

namespace Xeth{


class ScanProgress 
{
    public:

        ScanProgress();

        void setSignalStep(double);

        void setRange(size_t min, size_t max);
        void next();

        double getValue() const;
        void setValue(double);

        template<class Callback>
        void registerObserver(const Callback &);

    private:
        double _step;
        double _value;
        double _signalStep;
        double _nextSignal;
        ScanProgressEventEmitter _eventEmitter;
};



class DummyScanProgress
{
    public:
        inline void setRange(size_t, size_t){}
        inline void next() {}
        inline double getValue() {return 0;}
        inline void setValue(double){}
};


}


#include "ScanProgress.ipp"
