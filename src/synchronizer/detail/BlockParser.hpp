#pragma once

#include "ethrpc/Collection.hpp"
#include "ethrpc/Block.hpp"
#include "ethrpc/Transaction.hpp"

#include "../ScanResult.hpp"


namespace Xeth{


class BlockParser
{
    public:

        template<class BlockChain, class CriteriaIterator>
        void operator()(BlockChain &chain, size_t index, const CriteriaIterator &begin, const CriteriaIterator &end, ScanResult &);

};


}

#include "BlockParser.ipp"
