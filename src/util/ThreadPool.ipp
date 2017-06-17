namespace Xeth{


template<class Task>
boost::unique_future<void> ThreadPool::execute(const Task &task)
{
    boost::shared_ptr<boost::packaged_task<void> > wrap = boost::make_shared<boost::packaged_task<void> >(task);
    _io.post(boost::bind(&boost::packaged_task<void>::operator(), wrap));
    return wrap->get_future();
}



template<class Task, class Arguments>
boost::unique_future<void> ThreadPool::execute(const Arguments &args)
{
    return execute(Task(args));
}


template<class Task>
boost::unique_future<void> ThreadPool::execute()
{
    return execute(Task());
}


}
