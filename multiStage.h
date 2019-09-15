#include <stdlib.h>
#include <platon/platon.hpp>

namespace physicalDeviceInterface {
    class multiStage
    {
        public:

            std::string id;
            std::string sender;
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
                sender = platon::getState(id+"sender");
            }

            void setStage(const std::string i, const bool p, const bool o, const std::string s) {
                id = i;
                proof = p;
                oracle = o;
                sender = s;
                platon::setState(id+"proof",proof);
                platon::setState(id+"oracle",oracle);
                platon::setState(id+"sender",s);
            }

            void updateProof() {
                platon::setState(id+"proof",proof);
            }

            void updateOracle(const int i, const bool p) {
                platon::setState(id+"oracle",oracle);
            }

            bool verify(const int i) {
                loadId(i);
                if (proof == true && oracle == true) {
                    return true
                }
            }
    };
}
    