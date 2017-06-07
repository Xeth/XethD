#pragma once

#include <utility>
#include <stdint.h>

#include "../ScanCriterion.hpp"


namespace Xeth{


class ScanCriterionCompare
{
    public:
        bool operator()(const std::pair<size_t, ScanCriterion *> &, size_t);
};


}
