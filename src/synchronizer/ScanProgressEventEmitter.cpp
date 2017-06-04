#include "ScanProgressEventEmitter.hpp"


namespace Xeth{


void ScanProgressEventEmitter::emitProgress(double progress)
{
    _observers(progress);
}






}
