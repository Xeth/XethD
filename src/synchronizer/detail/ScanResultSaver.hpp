#pragma once


#include "database/DataBase.hpp"
#include "../ScanResult.hpp"


namespace Xeth{



class ScanResultSaver
{
    public:
        ScanResultSaver(DataBase &);
        void operator()(const PartialScanResult &);


    private:
        DataBase &_database;
};




}

