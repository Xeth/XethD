namespace Xeth{


template<class ScanCriteria>
ScanAction<ScanCriteria>::ScanAction()
{}


template<class ScanCriteria>
template<class Data>
void ScanAction<ScanCriteria>::start(Data &data, ScanCriteria &criteria, ScanProgress &progress)
{
    stop();
    resetResult();
    _thread.reset(ScanWork<ScanCriteria, Data, ScanProgress>(criteria, data, _result, progress));
}


template<class ScanCriteria>
template<class Data>
void ScanAction<ScanCriteria>::loop(Data &data, ScanCriteria &criteria, ScanProgress &progress, unsigned sleepTime)
{
    stop();
    resetResult();
    _thread.reset(ScanWorkLoop<ScanCriteria, Data, ScanProgress>(criteria, data, _result, progress, sleepTime));
}


template<class ScanCriteria>
void ScanAction<ScanCriteria>::resetResult()
{
    _result = ScanResult();
}





template<class ScanCriteria>
void ScanAction<ScanCriteria>::stop()
{
    if(isActive())
    {
        _thread->interrupt();
        _thread->join();
    }
}

template<class ScanCriteria>
void ScanAction<ScanCriteria>::waitToComplete()
{
    if(isActive())
    {
        _thread->join();
    }
}

template<class ScanCriteria>
bool ScanAction<ScanCriteria>::isActive() const
{
    if(!_thread)
    {
        return false;
    }
    return !_thread->timed_join(0);
}


template<class ScanCriteria>
const ScanResult & ScanAction<ScanCriteria>::getResult() const
{
    return _result;
}




}
