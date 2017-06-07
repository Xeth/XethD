namespace Xeth{


template<class ScanCriteria, class Data, class ScanProgress>
ScanWorkLoop<ScanCriteria, Data, ScanProgress>::ScanWorkLoop(ScanCriteria &criteria, Data &data, ScanResult &result, ScanProgress &progress, unsigned sleepTime) :
    _criteria(criteria),
    _data(_data),
    _result(result),
    _progress(progress),
    _sleepTime(sleepTime)
{}




template<class ScanCriteria, class Data, class ScanProgress>
void ScanWorkLoop<ScanCriteria, Data, ScanProgress>::operator()()
{
    while(true)
    {
        _criteria.parse(_data, _result, _progress);
        sleep(_sleepTime);
    }
}





}
