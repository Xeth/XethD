namespace Xeth{


template<class ScanIndexStore, class ScanCriteria>
ScanIndexUpdater<ScanIndexStore, ScanCriteria>::ScanIndexUpdater(ScanIndexStore &store, ScanCriteria &criteria) :
    _store(store),
    _criteria(criteria)
{}


template<class ScanIndexStore, class ScanCriteria>
void ScanIndexUpdater<ScanIndexStore, ScanCriteria>::operator()(const ScanResult &result)
{
    for(typename ScanCriteria::Iterator it = _criteria.begin(), end = _criteria.end(); it!=end; ++it)
    {
        _store.saveIndex(it->getAddress(), result.scanIndex);
    }
}



}
