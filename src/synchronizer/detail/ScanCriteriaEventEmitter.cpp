#include "ScanCriteriaEventEmitter.hpp"


namespace Xeth{


void ScanCriteriaEventEmitter::emitPartialScanResultEvent(const PartialScanResult &data)
{
    _partialScanResultObservers(data);
}


void ScanCriteriaEventEmitter::emitScanResultEvent(const ScanResult &data)
{
    _scanResultObservers(data);
}




}
