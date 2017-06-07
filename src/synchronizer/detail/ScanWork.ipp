namespace Xeth{


template<class ScanCriteria, class Data, class ScanProgress>
ScanWork<ScanCriteria, Data, ScanProgress>::ScanWork(ScanCriteria &criteria, Data &data, ScanResult &result, ScanProgress &progress) :
    _criteria(criteria),
    _data(_data),
    _result(result),
    _progress(progress)
{}




template<class ScanCriteria, class Data, class ScanProgress>
void ScanWork<ScanCriteria, Data, ScanProgress>::operator()()
{
    _criteria.parse(_data, _result, _progress);
}





}
