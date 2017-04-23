#pragma once 

#include <string>
#include <fstream>
#include <boost/filesystem.hpp>

#include "FileIterator.hpp"
#include "DataBaseDirectory.hpp"

#include "io/ObjectReader.hpp"
#include "io/ObjectWriter.hpp"


namespace Xeth{


template<class Value, class Serializer>
class FileStore
{
    public:
        typedef Value Data;
        typedef Serializer DataSerializer;
        typedef ObjectReader<Value, Serializer> Reader;
        typedef ObjectWriter<Value, Serializer> Writer;
        typedef FileIterator<Value, Reader> Iterator;

    public:

        FileStore(const std::string &path, const std::string &ext);
        FileStore(const boost::filesystem::path &, const std::string &ext);

        bool replace(const char *id, const Value &);
        bool insert(const char *id, const Value &);
        bool remove(const char *);

        Iterator find(const char *) const;
        Value get(const char *) const;

        Iterator begin() const;
        Iterator end() const;

        const std::string & getPath() const;

    private:
        bool write(const std::string &, const Value &);
        std::string makePath(const char *id) const;

    private:
        DataBaseDirectory _directory;
        std::string _ext;
        Serializer _serializer;
};



}

#include "FileStore.ipp"
