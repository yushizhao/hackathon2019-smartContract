#include <stdlib.h>
#include <platon/platon.hpp>

namespace physicalDeviceInterface {
    class oracle
    {
        public:
            std::string id;
            std::string addr;
            platon::DeployedContract orcaleContract;

        public:

            void loadId(const std::string i) {
                id = i;
                addr = platon::getState(id+"oracleAddr");
                orcaleContract(oracleAddr);
            }

            void set(const std::string i, const std::string a) {
                id = i;
                addr = a;
                orcaleContract(a);
                oracle.callSting(id);
                platon.setState(id+"oracleAddr", addr)
            }
    };
}

