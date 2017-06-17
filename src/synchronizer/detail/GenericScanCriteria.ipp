namespace Xeth{


template<class Parser>
GenericScanCriteria<Parser>::GenericScanCriteria() : 
    _interrupted(false),
    _limit(0)
{}


template<class Parser>
GenericScanCriteria<Parser>::GenericScanCriteria(size_t limit) : 
    _interrupted(false),
    _limit(limit)
{}


template<class Parser>
GenericScanCriteria<Parser>::GenericScanCriteria(const GenericScanCriteria &)
{}


template<class Parser>
GenericScanCriteria<Parser>::~GenericScanCriteria()
{
    clear();
}


template<class Parser>
void GenericScanCriteria<Parser>::setLimit(size_t limit)
{
    _limit = limit;
}


template<class Parser>
size_t GenericScanCriteria<Parser>::size() const
{
    return _criteria.size();
}


template<class Parser>
void GenericScanCriteria<Parser>::clear()
{

    boost::mutex::scoped_lock lock(_mutex);

    for(Container::iterator it=_criteria.begin(), end=_criteria.end(); it!=end; ++it)
    {
        delete it->second;
    }
    _criteria.clear();
}


template<class Parser>
typename GenericScanCriteria<Parser>::Iterator GenericScanCriteria<Parser>::begin() const
{
    return Iterator(_criteria.begin());
}


template<class Parser>
typename GenericScanCriteria<Parser>::Iterator GenericScanCriteria<Parser>::end() const
{
    return Iterator(_criteria.end());
}


template<class Parser>
void GenericScanCriteria<Parser>::addCriterion(size_t scanOffset, ScanCriterion *criterion)
{

    boost::mutex::scoped_lock lock(_mutex);
    Container::iterator it = std::lower_bound(_criteria.begin(), _criteria.end(), scanOffset, CriterionCompare());
    if(it==_criteria.end())
    {
        _criteria.push_back(std::make_pair(scanOffset, criterion));
    }
    else
    {
        _criteria.insert(it, std::make_pair(scanOffset, criterion));
    }
}


template<class Parser>
template<class Input>
size_t GenericScanCriteria<Parser>::parse(Input &input, ScanResult &result)
{
    DummyScanProgress progress;
    return parse(input, result, progress);
}



template<class Parser>
template<class Criterion, class Arg1>
void GenericScanCriteria<Parser>::addCriterion(size_t scanOffset, const Arg1 &arg1)
{
    addCriterion(scanOffset, new Criterion(arg1));
}


template<class Parser>
template<class Criterion, class Arg1, class Arg2>
void GenericScanCriteria<Parser>::addCriterion(size_t scanOffset, const Arg1 &arg1, const Arg2 &arg2)
{
    addCriterion(scanOffset, new Criterion(arg1, arg2));
}


template<class Parser>
template<class Criterion, class Arg1, class Arg2, class Arg3>
void GenericScanCriteria<Parser>::addCriterion(size_t scanOffset, const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3)
{
   addCriterion(scanOffset, new Criterion(arg1, arg2, arg3));
}


template<class Parser>
template<class Input, class Progress>
size_t GenericScanCriteria<Parser>::parse(Input &input, ScanResult &result, Progress &progress)
{

    boost::mutex::scoped_lock lock(_mutex);
    if(!_criteria.size())
    {
        progress.setValue(100);
        _eventEmitter.emitScanResultEvent(result);
        return 0;
    }


    try
    {
/*        blockchain.retrieveBlockDetails(false);*/
        size_t height = input.size();
        size_t scanOffset = _criteria.begin()->first;

        if(height < scanOffset)
        {
            progress.setValue(100);
            _eventEmitter.emitScanResultEvent(result);
            return height;
        }

        std::map<size_t, Container::iterator> mappedCriteria;

        size_t minIndex = scanOffset;

        for(Container::iterator it=_criteria.begin(), end=_criteria.end(); it!=end; ++it)
        {
            if(minIndex < it->first)
            {
                mappedCriteria.insert(std::make_pair(minIndex, it));
                minIndex = it->first;
            }
        }


        mappedCriteria.insert(std::make_pair(height, _criteria.end()));

        progress.setRange(scanOffset, height);

        result.scanIndex = scanOffset;

        size_t processed = 0;


        for(std::map<size_t, Container::iterator>::iterator it=mappedCriteria.begin(), end=mappedCriteria.end(); it!=end; ++it)
        {

            for(; result.scanIndex <= it->first; result.scanIndex++)
            {
                processItem(input, result.scanIndex, it->second, result);
                progress.next();

                boost::this_thread::interruption_point();

                if(_limit && (++processed > _limit))
                {
                    goto SAVE_CRITERIA_RESULT;
                }
            }

        }
    }
    catch(...){}

SAVE_CRITERIA_RESULT:

    for(Container::iterator it=_criteria.begin(), end=_criteria.end(); it!=end; ++it)
    {
        if(it->first < result.scanIndex)
        {
            it->first = result.scanIndex;
        }
        else
        {
            break;
        }
    }

    _eventEmitter.emitScanResultEvent(result);

    return result.scanIndex;

}


template<class Parser>
template<class Input>
void GenericScanCriteria<Parser>::processItem(Input &input, size_t index, Container::iterator end, ScanResult &result)
{
    size_t prevTxSize = result.transactions.size();
    size_t prevStSize = result.stealthPayments.size();

    _parser(input, index, _criteria.begin(), end, result);

    size_t txSize = result.transactions.size();
    size_t stSize = result.stealthPayments.size();

    if(prevTxSize != txSize || stSize != prevStSize)
    {
        PartialScanResult event = MakePartialScanResult(result, txSize - prevTxSize, stSize - prevStSize, index);
        _eventEmitter.emitPartialScanResultEvent(event);
    }
}


}
