namespace Xeth{


template<class ScanCriteria, class Data, class ScanProgress>
ScanWorkLoop<ScanCriteria, Data, ScanProgress>::ScanWorkLoop(ScanCriteria &criteria, Data &data, ScanResult &result, ScanProgress &progress, unsigned sleepTime) :
    Base(criteria, data, result, progress),
    _sleepTime(sleepTime)
{}




template<class ScanCriteria, class Data, class ScanProgress>
void ScanWorkLoop<ScanCriteria, Data, ScanProgress>::operator()()
{
    Base::assign();
    while(true)
    {
        Base::execute();
        sleep(_sleepTime);
    }
}





}
