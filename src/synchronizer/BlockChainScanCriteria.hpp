#pragma once

#include "detail/BlockParser.hpp"
#include "detail/GenericScanCriteria.hpp"


namespace Xeth{

typedef GenericScanCriteria<BlockParser> BlockChainScanCriteria;


}
