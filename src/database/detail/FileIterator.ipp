namespace Xeth{



template<class Value, class Parser>
FileIterator<Value, Parser>::FileIterator(const fs::directory_iterator &it, const std::string &ext) :
    _ext(ext),
    _handle(findValid(it))
{}


template<class Value, class Parser>
FileIterator<Value, Parser>::FileIterator(const std::string &path, const std::string &ext) :
    _ext(ext),
    _handle(findValid(fs::directory_iterator(path)))
{}

template<class Value, class Parser>
FileIterator<Value, Parser>::FileIterator()
{}


template<class Value, class Parser>
fs::directory_iterator FileIterator<Value, Parser>::findValid(const fs::directory_iterator &begin)
{
    fs::directory_iterator it = begin, end = fs::directory_iterator();
    if(begin==end)
    {
        return begin;
    }

    while(it!=end)
    {
        if(fs::is_regular_file(it->status()) &&  (!_ext.size() || it->path().extension().string() == _ext))
        {
            break;
        }
        ++it;
    }
    return it;
}


template<class Value, class Parser>
void FileIterator<Value, Parser>::increment()
{
    _handle = findValid(++_handle);
}



template<class Value, class Parser>
bool FileIterator<Value, Parser>::equal(const FileIterator &it) const
{
    return _handle == it._handle;
}


template<class Value, class Parser>
Value FileIterator<Value, Parser>::dereference() const
{
    return _parser(_handle->path());
}


template<class Value, class Parser>
const fs::path & FileIterator<Value, Parser>::path() const
{
    return _handle->path();
}



}
