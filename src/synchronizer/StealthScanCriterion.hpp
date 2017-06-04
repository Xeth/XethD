#pragma once 

#include <json/value.h>

#include "ethcrypto/key/PublicKey.hpp"
#include "ethcrypto/serialization/PublicKeySerializer.hpp"
#include "ethcrypto/encoding/HexEncoder.hpp"

#include "ethstealth/Literal.hpp"

#include "ScanCriterion.hpp"
#include "ScanResult.hpp"

#include "types/StealthKey.hpp"
#include "types/EthereumKey.hpp"


namespace Xeth{


class StealthScanCriterion : public ScanCriterion
{

    public:

        StealthScanCriterion
        (
            const StealthKey &
        );

        StealthScanCriterion
        (
            const StealthKey &,
            const Ethereum::Stealth::Address &
        );

        void processTransaction
        (
            const std::string &hash,
            const std::string &from,
            const std::string &to,
            const BigInt &amount,
            const std::string &data,
            time_t timestamp,
            ScanResult &result
        );

    private:
        std::string makeAddress(const StealthKey &) const;

        void uncoverStealthPayment
        (
            const std::string &hash,
            const std::string &from,
            const std::string &to,
            const BigInt &amount,
            const char *data,
            size_t dataSize,
            time_t timestamp,
            ScanResult &result
        );

    private:
        StealthKey _key;
};


}
