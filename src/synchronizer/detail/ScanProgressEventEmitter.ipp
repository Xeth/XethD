namespace Xeth{



template<class Callback>
void ScanProgressEventEmitter::registerObserver(const Callback &observer)
{
    _observers.connect(observer);
}










}
