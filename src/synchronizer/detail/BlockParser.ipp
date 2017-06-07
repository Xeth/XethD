

namespace Xeth{


template<class BlockChain, class CriteriaIterator>
void BlockParser::operator()(BlockChain &chain, size_t blockIndex, const CriteriaIterator &begin, const CriteriaIterator &end, ScanResult &result)
{
    static BigInt blockReward("5000000000000000000");
    Ethereum::Connector::Block block = chain.getBlock(blockIndex);

    std::string miner = block.getMiner();
    std::string blockHash = block.getHash();
    time_t blockTime = block.getTimestamp();

    for(CriteriaIterator it=begin; it!=end; ++it)
    {
        it->second->processHeader(blockIndex, blockHash, miner, blockReward, blockTime, result);
    }

    Ethereum::Connector::Collection<std::string> hashes = block.getTransactionsHashes();


    for(Ethereum::Connector::Collection<std::string>::Iterator tIt=hashes.begin(), tEnd=hashes.end(); tIt!=tEnd; ++tIt)
    {
        std::string hash = *tIt;
        Ethereum::Connector::Transaction transaction = chain.getTransaction(hash.c_str());
        std::string sender = transaction.getSender();
        std::string receiver = transaction.getReceiver();
        std::string txid = transaction.getHash();
        BigInt amount = transaction.getAmount();
        std::string data = transaction.getInput();

        for(CriteriaIterator it=begin; it!=end; ++it)
        {
            it->second->processTransaction(txid, sender, receiver, amount, data, blockTime, result);
        }
    }
}


}
