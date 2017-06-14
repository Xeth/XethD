#pragma once

#include "ethrpc/Provider.hpp"
#include "database/DataBase.hpp"


#include "../ScanAction.hpp"
#include "../ScanProgress.hpp"
#include "../SynchronizerContext.hpp"


#include "ScanIndexUpdater.hpp"
#include "ScanResultSaver.hpp"
#include "ScopedScanPause.hpp"

namespace Xeth{


template<class ScanCriteria, class Input, class ScanIndexStore, class ScanIndexEstimator>
class GenericScanner
{

    public:
        GenericScanner(SynchronizerContext &, size_t scanChunk=100, size_t scanInterval=100);
        ~GenericScanner();


        void setScanChunkSize(size_t limit);
        void setScanInterval(size_t seconds);

        const ScanProgress & getProgress() const;
        bool isActive() const;

        template<class Criterion, class Arguments>
        void addScanCriterion(const Arguments &, time_t creationTime);


        template<class Criterion, class Arguments>
        void addScanCriterion(const Arguments &);


        void syncScan();
        void stop();
        void scan();

    private:
        GenericScanner(const GenericScanner &);

    private:
        typedef Xeth::ScopedScanPause<GenericScanner<ScanCriteria, Input, ScanIndexStore, ScanIndexEstimator> > ScopedScanPause;

    private:
        SynchronizerContext &_context;

        Input _input;
        ScanIndexStore _indexStore;
        ScanIndexEstimator _indexEstimator;

        ScanProgress _scanProgress;
        ScanCriteria _scanCriteria;
        ScanAction<ScanCriteria> _scanAction;


        size_t _scanInterval;
};


}
