#include "ThreadPool.hpp"


namespace Xeth{


ThreadPool::ThreadPool(size_t size) :
    _work(_io)
{
    for(size_t i=0; i<size; i++)
    {
        _threads.create_thread(boost::bind(&boost::asio::io_service::run, &_io));
    }
}


ThreadPool::~ThreadPool()
{
    _io.stop();
    _threads.join_all();
}



}
