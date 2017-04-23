#include "ApplicationPath.hpp"

#ifdef __WINDOWS_OS__
#include <shlobj.h>
#endif

namespace  Xeth{


std::string ApplicationPath::Vendors()
{
    boost::filesystem::path current = boost::filesystem::current_path();
    std::string path = current.string();

#if defined(__WINDOWS_OS__)
    path.append("\\vendor\\bin");
#else
    path.append("/vendor/bin");
#endif
    return path;
}


std::string ApplicationPath::XethData()
{
    std::string path;
#if  defined(__APPLE_OS__)
    path = getenv("HOME");
    path += "/Library/Xeth";
#elif defined(__LINUX_OS__)
    path = getenv("HOME");
    path += "/.xeth";
#elif defined(__WINDOWS_OS__)
    char appdata[1024] = "";
    if (SHGetSpecialFolderPathA(NULL, appdata, CSIDL_APPDATA, true))
    {
        path = appdata;
    }
    else
    {
        path = getenv("HOMEPATH");
    }
    path += "\\Xeth";
#endif

    return path;
}


std::string ApplicationPath::LocalVendors()
{
    std::string path = XethData();
#if defined(__WINDOWS_OS__)
    path += "\\vendor\\bin";
#else
    path += "/vendor/bin";
#endif
    return path;
}


std::string ApplicationPath::EthereumData()
{
    std::string path;
#if  defined(__APPLE_OS__)
    path = getenv("HOME");
    path += "/Library/Ethereum";
#elif defined(__LINUX_OS__)
    path = getenv("HOME");
    path += "/.ethereum";
#elif defined(__WINDOWS_OS__)
    char appdata[1024] = "";
    if (SHGetSpecialFolderPathA(NULL, appdata, CSIDL_APPDATA, true))
    {
        path = appdata;
    }
    else
    {
        path = getenv("HOMEPATH");
    }
    path += "\\Ethereum";
#endif
    return path;
}


std::string ApplicationPath::Keys()
{
    std::string path = EthereumData();
#if defined(__WINDOWS_OS__)
    path += "\\keystore\\ethereum";
#else
    path += "/keystore/ethereum";
#endif
    return path;
}


std::string ApplicationPath::TestnetKeys()
{
    std::string path = EthereumData();
#if defined(__WINDOWS_OS__)
    path += "\\keystore\\testnet";
#else
    path += "/keystore/testnet";
#endif
    return path;
}


std::string ApplicationPath::StealthKeys()
{
    std::string path = XethData();
#if defined(__WINDOWS_OS__)
    path+="\\keystore";
#else
    path+="/keystore";
#endif
    return path;
}


std::string ApplicationPath::TestnetStealthKeys()
{
    std::string path = XethData();
#if defined(__WINDOWS_OS__)
    path+="\\testnet\\keystore";
#else
    path+="/testnet/keystore";
#endif
    return path;
}


}
