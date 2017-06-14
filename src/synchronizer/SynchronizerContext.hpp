#pragma once


#include <boost/asio.hpp>
#include "ethrpc/Provider.hpp"
#include "database/DataBase.hpp"
#include "conf/Settings.hpp"



namespace Xeth{


class SynchronizerContext
{
    public:
        SynchronizerContext(const Settings &, Ethereum::Connector::Provider &, DataBase &);

        boost::asio::io_service & getIO();
        const Settings & getSettings() const;
        Ethereum::Connector::Provider & getConnector();
        DataBase & getDataBase();


    private:
        boost::asio::io_service _io;
        const Settings &_settings;
        Ethereum::Connector::Provider &_connector;
        DataBase &_database;
};


}
