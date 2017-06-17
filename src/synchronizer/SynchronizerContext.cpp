#include "SynchronizerContext.hpp"


namespace Xeth{


SynchronizerContext::SynchronizerContext(const Settings &settings, Ethereum::Connector::Provider &connector, DataBase &database) :
    _threads(3),
    _settings(settings),
    _connector(connector),
    _database(database)
{
    _threads.execute(boost::bind(&boost::asio::io_service::run, &_io));
}


boost::asio::io_service & SynchronizerContext::getIO()
{
    return _io;
}


const Settings & SynchronizerContext::getSettings() const
{
    return _settings;
}


Ethereum::Connector::Provider & SynchronizerContext::getConnector()
{
    return _connector;
}


DataBase & SynchronizerContext::getDataBase()
{
    return _database;
}


ThreadPool & SynchronizerContext::getThreadPool()
{
    return _threads;
}


}
