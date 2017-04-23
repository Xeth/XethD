#include "TransactionStore.hpp"

namespace Xeth{


Json::Value TransactionDataSerializer::operator()(const char *key, const char *value) const
{
    Json::Value result;
    operator()(key, value, result);
    return result;
}

bool TransactionDataSerializer::operator()(int key, const char *value, Json::Value &result) const
{
    DataSerializer<Json::Value>::operator()(NULL, value, result);
    result["index"] = key;
    return true;
}


TransactionStore::TransactionStore()
{}


TransactionStore::TransactionStore(const std::string &path )
{
    open(path);
}


TransactionStore::TransactionStore(const boost::filesystem::path &path)
{
    open(path.string());
}


bool TransactionStore::openNoThrow(const std::string &path)
{
    if(!_dataStore.openNoThrow(path) || !_indexStore.openNoThrow(path+".index"))
    {
        return false;
    }


    ReverseIterator it = _dataStore.rbegin();
    if(it != _dataStore.rend())
    {
        _lastIndex = it.base().key();
    }
    else
    {
        _lastIndex = 0;
    }

    return true;
}


void TransactionStore::open(const std::string &path)
{
    if(!openNoThrow(path))
    {
        std::stringstream stream;
        stream<<"failed to open transactions DB : "<<path;
        throw std::runtime_error(stream.str());
    }
}


bool TransactionStore::openNoThrow(const boost::filesystem::path &path)
{
    return openNoThrow(path.string());
}


void TransactionStore::open(const boost::filesystem::path &path)
{
    return open(path.string());
}


TransactionStore::Iterator TransactionStore::begin() const
{
    return _dataStore.begin();
}


TransactionStore::Iterator TransactionStore::end() const
{
    return _dataStore.end();
}


size_t TransactionStore::size() const
{
    return _lastIndex;
}

TransactionStore::Iterator TransactionStore::at(int index) const
{
    return _dataStore.find(index + 1);
}


TransactionStore::ReverseIterator TransactionStore::rbegin() const
{
    return _dataStore.rbegin();
}


TransactionStore::ReverseIterator TransactionStore::rend() const
{
    return _dataStore.rend();
}


bool TransactionStore::insert
(
    const TransactionCategory &category,
    const std::string &hash,
    const std::string &from,
    const std::string &to,
    const BigInt &amount,
    time_t timestamp
)
{
    Json::Value obj;
    obj["category"] = category.toString();
    obj["hash"] = hash;
    if(from.size())
    {
        obj["from"] = from;
    }
    obj["to"] = to;
    obj["amount"] = boost::lexical_cast<std::string>(amount);
    obj["timestamp"] = (int)timestamp;
    return insert(makeID(category, hash), obj);
}

bool TransactionStore::insert
(
    const TransactionCategory &category,
    const std::string &hash,
    const std::string &from,
    const std::string &to,
    const Ethereum::Stealth::Address &stealth,
    const BigInt &amount,
    time_t timestamp
)
{
    Json::Value obj;
    obj["category"]  = category.toString();
    obj["hash"] = hash;
    if(from.size())
    {
        obj["from"] = from;
    }
    obj["to"] = to;
    obj["amount"] = boost::lexical_cast<std::string>(amount);
    obj["timestamp"] = (int)timestamp;
    obj["stealth"] = stealth.toString();
    return insert(makeID(category, hash), obj);
}

bool TransactionStore::insert(const Json::Value &obj)
{
    return insert(makeID(obj), obj);
}

bool TransactionStore::insert(const std::string &id, const Json::Value &obj)
{
    int index = _indexStore.get(id.c_str());
    if(!index)
    {
        index = getNextIndex();

        if(!_indexStore.insert(id.c_str(), index))
        {
            return false;
        }

        if(!_dataStore.insert(index, obj))
        {
            return false;
        }
    }
    else
    {
        if(!_dataStore.insert(index, obj))
        {
            return false;
        }
    }
    _emitter.emitInsertEvent(index, obj);
    return true;
}

std::string TransactionStore::makeID(const TransactionCategory &category, const std::string &hash)
{
    return hash + category.toString();
}


std::string TransactionStore::makeID(const Json::Value &obj)
{
    return obj["hash"].asString()+obj["category"].asString();
}

int TransactionStore::getNextIndex()
{
    return ++_lastIndex;
}


}
