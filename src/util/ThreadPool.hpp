#pragma once


#include <boost/asio/io_service.hpp>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>



namespace Xeth{


class ThreadPool
{
    public:
        ThreadPool(size_t size = 4);
        ~ThreadPool();

        template<class Task, class Arguments>
        void execute(const Arguments &);

        template<class Task>
        void execute();

        template<class Task>
        void execute(const Task &);

    private:
        boost::asio::io_service _io;
        boost::thread_group _threads;
        boost::asio::io_service::work _work;

};


}


#include "ThreadPool.ipp"
