
namespace Xeth{


template<class Container>
ScanCriteriaIterator<Container>::ScanCriteriaIterator() : Base() {}


template<class Container>
ScanCriteriaIterator<Container>::ScanCriteriaIterator(const typename Container::const_iterator & p) :
    Base(p)
{}


template<class Container>
size_t ScanCriteriaIterator<Container>::getIndex() const
{
    return this->base()->first;
}


template<class Container>
const ScanCriterion & ScanCriteriaIterator<Container>::dereference() const
{
    return *this->base()->second;
}


}
