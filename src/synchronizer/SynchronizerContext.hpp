#pragma once


#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include "ethrpc/Provider.hpp"
#include "database/DataBase.hpp"
#include "conf/Settings.hpp"
#include "util/ThreadPool.hpp"



namespace Xeth{


class SynchronizerContext
{
    public:
        SynchronizerContext(const Settings &, Ethereum::Connector::Provider &, DataBase &);

        boost::asio::io_service & getIO();
        const Settings & getSettings() const;
        Ethereum::Connector::Provider & getConnector();
        DataBase & getDataBase();
        ThreadPool & getThreadPool();


    private:
        boost::asio::io_service _io;
        ThreadPool _threads;
        const Settings &_settings;
        Ethereum::Connector::Provider &_connector;
        DataBase &_database;
};


}
