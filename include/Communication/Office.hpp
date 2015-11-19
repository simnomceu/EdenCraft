#ifndef OFFICE_HPP
#define OFFICE_HPP

#include <map>
#include <string>
#include <memory>
#include <queue>

#include "ICentralizer.hpp"
#include "ICommunicable.hpp"

class Office : public ICentralizer
{
        Office(const Office&) = delete ;
        Office& operator=(const Office&) = delete ;
    public:
        Office();

        virtual void post(std::shared_ptr<ITransmitable> newMessageIn);
        void registerAccount(std::pair<std::string, std::weak_ptr<ICommunicable>> newAccount);
        void distribute();
    private:
        std::map<std::string, std::weak_ptr<ICommunicable>> accounts;
        std::queue<std::shared_ptr<ITransmitable>> waitingMessages;
};

#endif // OFFICE_HPP
