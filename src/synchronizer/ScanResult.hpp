#pragma once 

#include <json/value.h>

#include "util/JsonUtils.hpp"
#include "util/JsonArrayRange.hpp"


namespace Xeth{


struct ScanResult
{
    Json::Value transactions;
    Json::Value stealthPayments;
    size_t lastBlock;
};


struct PartialScanResult
{
    JsonArrayRange transactions;
    JsonArrayRange stealthPayments;

    size_t lastBlock;
};


PartialScanResult MakePartialScanResult
(
    Json::Value::const_iterator tBegin,
    Json::Value::const_iterator tEnd,
    Json::Value::const_iterator sBegin,
    Json::Value::const_iterator sEnd,
    size_t
);

PartialScanResult MakePartialScanResult(const ScanResult &, size_t txCount, size_t stCount, size_t blockIndex);


}

