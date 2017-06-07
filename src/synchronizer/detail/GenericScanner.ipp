namespace Xeth{


template<class ScanCriteria, class Input, class ScanIndexStore, class ScanIndexEstimator>
GenericScanner<ScanCriteria, Input, ScanIndexStore, ScanIndexEstimator>::GenericScanner(Ethereum::Connector::Provider &provider, DataBase &database, size_t scanChunk, size_t scanInterval) :
    _provider(provider),
    _database(database),
    _input(_provider),
    _indexStore(_provider, _database),
    _indexEstimator(_provider),
    _scanCriteria(scanChunk),
    _scanInterval(scanInterval)
{
    _scanCriteria.registerPartialResultObserver(ScanResultSaver(_database));
    _scanCriteria.registerResultObserver(ScanIndexUpdater<ScanIndexStore, ScanCriteria>(_indexStore, _scanCriteria));
}


template<class ScanCriteria, class Input, class ScanIndexStore, class ScanIndexEstimator>
GenericScanner<ScanCriteria, Input, ScanIndexStore, ScanIndexEstimator>::~GenericScanner()
{
    _action.stop();
}



template<class ScanCriteria, class Input, class ScanIndexStore, class ScanIndexEstimator>
void GenericScanner<ScanCriteria, Input, ScanIndexStore, ScanIndexEstimator>::setScanChunkSize(size_t size)
{
    _scanCriteria.setLimit(size);
}



template<class ScanCriteria, class Input, class ScanIndexStore, class ScanIndexEstimator>
void GenericScanner<ScanCriteria, Input, ScanIndexStore, ScanIndexEstimator>::setScanInterval(size_t interval)
{
    _scanInterval = interval;
}



template<class ScanCriteria, class Input, class ScanIndexStore, class ScanIndexEstimator>
const ScanProgress & GenericScanner<ScanCriteria, Input, ScanIndexStore, ScanIndexEstimator>::getProgress() const
{
    return _scanProgress;
}



template<class ScanCriteria, class Input, class ScanIndexStore, class ScanIndexEstimator>
bool GenericScanner<ScanCriteria, Input, ScanIndexStore, ScanIndexEstimator>::isActive() const
{
    return _action.isActive();
}



template<class ScanCriteria, class Input, class ScanIndexStore, class ScanIndexEstimator>
template<class Criterion, class Arguments>
void GenericScanner<ScanCriteria, Input, ScanIndexStore, ScanIndexEstimator>::addScanCriterion(const Arguments &args, time_t creationTime)
{

    ScopedScanPause(this);
    size_t index = _indexStore.get(args);
    if(!index)
    {
        index = _indexEstimator.estimateIndex(creationTime);
    }
    _scanCriteria.addCriterion<Criterion>(args, index);
}


template<class ScanCriteria, class Input, class ScanIndexStore, class ScanIndexEstimator>
template<class Criterion, class Arguments>
void GenericScanner<ScanCriteria, Input, ScanIndexStore, ScanIndexEstimator>::addScanCriterion(const Arguments &args)
{

    ScopedScanPause(this);
    size_t index = _indexStore.get(args);
    if(!index)
    {
        index = _indexEstimator.getLastIndex();
    }
    _scanCriteria.addCriterion<Criterion>(args, index);
}




template<class ScanCriteria, class Input, class ScanIndexStore, class ScanIndexEstimator>
void GenericScanner<ScanCriteria, Input, ScanIndexStore, ScanIndexEstimator>::stop()
{
    _scanAction.stop();
}


template<class ScanCriteria, class Input, class ScanIndexStore, class ScanIndexEstimator>
void GenericScanner<ScanCriteria, Input, ScanIndexStore, ScanIndexEstimator>::scan()
{
    _scanAction.loop(_scanCriteria, _input, _scanProgress, _scanInterval);
}


template<class ScanCriteria, class Input, class ScanIndexStore, class ScanIndexEstimator>
void GenericScanner<ScanCriteria, Input, ScanIndexStore, ScanIndexEstimator>::syncScan()
{
    _scanAction.start(_scanCriteria, _input, _scanProgress);
    _scanAction.waitToComplete();
}







}


