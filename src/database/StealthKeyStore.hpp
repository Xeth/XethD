#pragma once 

#include "types/StealthKey.hpp"

#include "detail/GenericKeyStore.hpp"
#include "detail/StealthKeyFileMatcher.hpp"
#include "detail/StealthKeyFileNameGenerator.hpp"

namespace Xeth{


typedef GenericKeyStore
<
    StealthKey,
    StealthAddress,
    StealthKeySerializer,
    StealthKeyFileNameGenerator,
    StealthKeyFileMatcher
> StealthKeyStore;





}
