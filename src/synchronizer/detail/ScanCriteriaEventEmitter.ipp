namespace Xeth{



template<class Callback>
void ScanCriteriaEventEmitter::registerPartialScanResultObserver(const Callback &observer)
{
    _partialScanResultObservers.connect(observer);
}



template<class Callback>
void ScanCriteriaEventEmitter::registerScanResultObserver(const Callback &observer)
{
    _scanResultObservers.connect(observer);
}







}
