namespace Xeth{


template<class ChainScanner>
ScopedScanPause<ChainScanner>::ScopedScanPause(ChainScanner *scanner) :
    _scanner(scanner),
    _active(scanner->isActive())
{
    if(_active)
    {
        _scanner->stop();
    }
}


template<class ChainScanner>
ScopedScanPause<ChainScanner>::~ScopedScanPause()
{
    if(_active)
    {
        _scanner->scan();
    }
}

}
