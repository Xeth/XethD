#pragma once

#include "bitprofile/Network.hpp"
#include "bitprofile/ProfileDescriptor.hpp"
#include "bitprofile/ProfileStore.hpp"
#include "bitprofile/Registrar.hpp"


#include "detail/StoreEventEmitter.hpp"

namespace Xeth{


class BitProfileStore 
{
    public:
        typedef BitProfile::ProfileStore::Iterator Iterator;

    public:
        BitProfileStore(BitProfile::Network);

        bool insert(const BitProfile::ProfileDescriptor &);
        bool remove(const BitProfile::Profile::URI &);
        bool remove(const std::string &uri);

        bool rename(const BitProfile::Profile::URI &, const BitProfile::Profile::URI &);

        Iterator find(const std::string &) const;
        Iterator find(const char *) const;
        Iterator begin() const;
        Iterator end() const;

        template<class Callback>
        void onInsert(const Callback &);

        template<class Callback>
        void onRemove(const Callback &);

        template<class Callback>
        void onReplace(const Callback &);


    private:
        BitProfile::ProfileStore _store;
        StoreEventEmitter<std::string, BitProfile::ProfileDescriptor> _emitter;

};


}


#include "BitProfileStore.ipp"
