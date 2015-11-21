#ifndef OFFICE_HPP
#define OFFICE_HPP

#include <map>
#include <string>
#include <memory>
#include <queue>

#include "ICentralizer.hpp"

class Office : public ICentralizer
{
        Office(const Office&) = delete ;
        Office& operator=(const Office&) = delete ;
    public:
        Office();

        virtual void post(std::shared_ptr<ITransmitable> newMessageIn);
        void registerAccount(const std::string& newAccount);
        virtual bool newMessages(const std::string& accountIn);
        virtual std::shared_ptr<ITransmitable> withdraw(const std::string& accountIn);
    private:
        std::map<std::string, std::queue<std::shared_ptr<ITransmitable>>> accounts;
        std::queue<std::shared_ptr<ITransmitable>> waitingMessages;
};

#endif // OFFICE_HPP
