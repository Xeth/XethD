namespace Xeth{

template<class Callback>
void ScanProgress::registerObserver(const Callback &callback)
{
    _eventEmitter.registerObserver(callback);
}

}
