#pragma once

#include <boost/iterator/iterator_adaptor.hpp>
#include "../ScanCriterion.hpp"


namespace Xeth{


template<class Container>
class ScanCriteriaIterator : public boost::iterator_adaptor<
      ScanCriteriaIterator<Container>,
      typename Container::const_iterator,
      const ScanCriterion &,
      boost::forward_traversal_tag,
      const ScanCriterion & >
{
    public:
        typedef boost::iterator_adaptor<
          ScanCriteriaIterator<Container>,
          typename Container::const_iterator,
          const ScanCriterion &,
          boost::forward_traversal_tag,
          const ScanCriterion & > Base;

    public:
        ScanCriteriaIterator();
        explicit ScanCriteriaIterator(const typename Container::const_iterator &);
        size_t getIndex() const;

    private:
        friend class boost::iterator_core_access;
        const ScanCriterion & dereference() const;
};



}

#include "ScanCriteriaIterator.ipp"
