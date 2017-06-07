#pragma once

#include <map>
#include <list>

#include <boost/thread.hpp>

#include "../ScanCriterion.hpp"
#include "../ScanProgress.hpp"
#include "../ScanResult.hpp"

#include "ScanCriteriaIterator.hpp"
#include "ScanCriterionCompare.hpp"
#include "ScanCriteriaEventEmitter.hpp"


namespace Xeth{



template<class Parser>
class GenericScanCriteria
{
    public:
        typedef std::list<std::pair<size_t, ScanCriterion *> > Container;
        typedef ScanCriterionCompare CriterionCompare;
        typedef ScanCriteriaIterator<Container> Iterator;


    public:

        GenericScanCriteria(size_t limit);
        GenericScanCriteria();
        ~GenericScanCriteria();

        void setLimit(size_t);

        template<class Criterion, class Arg>
        void addCriterion(size_t lastIndex, const Arg &);

        template<class Criterion, class Arg1, class Arg2>
        void addCriterion(size_t lastIndex, const Arg1&, const Arg2&);

        template<class Criterion, class Arg1, class Arg2, class Arg3>
        void addCriterion(size_t lastIndex, const Arg1 &, const Arg2 &, const Arg3&);


        template<class CallBack>
        void registerResultObserver(const CallBack &);

        template<class CallBack>
        void registerPartialResultObserver(const CallBack &);


        void clear();

        Iterator begin() const;
        Iterator end() const;
        size_t size() const;

        template<class Input>
        size_t parse(Input &, ScanResult &);

        template<class Input, class Progress>
        size_t parse(Input &, ScanResult &, Progress &);


    private:
        GenericScanCriteria(const GenericScanCriteria &);

        template<class Input>
        void processItem(Input &, size_t, Container::iterator, ScanResult &);
        void addCriterion(size_t lastIndex, ScanCriterion *);


    private:
        bool _interrupted;
        size_t _limit;

        Container _criteria;
        ScanCriteriaEventEmitter _eventEmitter;
        Parser _parser;
};





}

#include "GenericScanCriteria.ipp"
