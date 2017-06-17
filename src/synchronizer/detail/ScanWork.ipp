namespace Xeth{


template<class ScanCriteria, class Data, class ScanProgress>
ScanWork<ScanCriteria, Data, ScanProgress>::ScanWork(ScanCriteria &criteria, Data &data, ScanResult &result, ScanProgress &progress) :
    _criteria(criteria),
    _data(_data),
    _result(result),
    _progress(progress),
    _thread(NULL)
{}




template<class ScanCriteria, class Data, class ScanProgress>
void ScanWork<ScanCriteria, Data, ScanProgress>::operator()()
{
    assign();
    execute();
}



template<class ScanCriteria, class Data, class ScanProgress>
void ScanWork<ScanCriteria, Data, ScanProgress>::assign()
{
    assign(boost::this_thread::get_id());
}


template<class ScanCriteria, class Data, class ScanProgress>
void ScanWork<ScanCriteria, Data, ScanProgress>::assign(const boost::thread::id &id)
{
    _thread = &id;
}


template<class ScanCriteria, class Data, class ScanProgress>
bool ScanWork<ScanCriteria, Data, ScanProgress>::isAssigned() const
{
    return _thread != NULL;
}


template<class ScanCriteria, class Data, class ScanProgress>
boost::thread::id * const ScanWork<ScanCriteria, Data, ScanProgress>::getAssignedThread() const
{
    return _thread;
}


template<class ScanCriteria, class Data, class ScanProgress>
void ScanWork<ScanCriteria, Data, ScanProgress>::execute()
{
    _criteria.parse(_data, _result, _progress);
}




}
