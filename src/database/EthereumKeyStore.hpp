#pragma once 

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/conversion.hpp>
#include <boost/regex.hpp> 
#include <boost/filesystem.hpp>

#include "types/EthereumKey.hpp"

#include "detail/FileStore.hpp"
#include "detail/GenericKeyStore.hpp"
#include "detail/EthereumKeyFileNameGenerator.hpp"
#include "detail/EthereumKeyFilePathMatcher.hpp"


namespace Xeth{


typedef GenericKeyStore
        <
            EthereumKey,
            EthereumAddress,
            EthereumKeySerializer,
            EthereumKeyFileNameGenerator,
            EthereumKeyFilePathMatcher
        > EthereumKeyStore;





}
