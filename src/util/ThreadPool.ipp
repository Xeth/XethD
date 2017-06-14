namespace Xeth{


template<class Task>
void ThreadPool::execute(const Task &task)
{
    _io.post(task);
}



template<class Task, class Arguments>
void ThreadPool::execute(const Arguments &args)
{
    execute(Task(args));
}


template<class Task>
void ThreadPool::execute()
{
    execute(Task());
}


}
