#pragma once 

#include "types/StealthKey.hpp"
#include "detail/FileStore.hpp"
#include "detail/GenericKeyStore.hpp"


namespace Xeth{




class StealthKeyStore : 
    protected GenericKeyStore<StealthKey, StealthAddress, StealthKeySerializer>
{

    public:
        typedef GenericKeyStore<StealthKey, StealthAddress, StealthKeySerializer> Base;
        typedef Base::Iterator Iterator;
        typedef Base::Data Data;
        typedef Base::DataSerializer DataSerializer;

    public:
        StealthKeyStore(const std::string &path);
        StealthKeyStore(const boost::filesystem::path &path);
};



}
