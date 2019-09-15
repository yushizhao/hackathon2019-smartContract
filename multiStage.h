#include <stdlib.h>
#include <platon/platon.hpp>

namespace physicalDeviceInterface {
    class multiStage:public platon::Contract
    {
        public:

            std::string id;
            bool proof;
            bool oracle;

        public:

            void init() {
                platon::println("init success...");
            }

            void loadId(const int i) {
                id = i;
                proof = platon::getState(id+"proof");
                oracle = platon::getState(id+"oracle");
            }
            void setStage(const int i, const bool p, const bool o) {
                id = i;
                proof = p;
                oracle = o;
                platon::setState(id+"proof",p);
                platon::setState(id+"oracle",o);
            }

            void updateProof(const int i, const bool p) {
                id = i;
                proof = p;
                platon::setState(id+"proof",p);
            }

            void updateOracle(const int i, const bool p) {
                id = i;
                proof = p;
                platon::setState(id+"oracle",o);
            }

            bool verify(const int i) {
                loadId(i);
                if (proof == true && oracle == true) {
                    return true
                }
            }
    }

    