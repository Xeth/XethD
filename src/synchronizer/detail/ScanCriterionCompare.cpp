#include "ScanCriterionCompare.hpp"


namespace Xeth{


bool ScanCriterionCompare::operator ()(const std::pair<size_t, ScanCriterion *> &criterion, size_t index)
{
    return criterion.first < index;
}



}
