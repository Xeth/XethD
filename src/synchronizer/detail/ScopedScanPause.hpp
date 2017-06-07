#pragma once


namespace Xeth{


template<class ChainScanner>
class ScopedScanPause
{
    public:
        ScopedScanPause(ChainScanner *);
        ~ScopedScanPause();

    private:
        ChainScanner *_scanner;
        bool _active;
};



}


#include "ScopedScanPause.ipp"
