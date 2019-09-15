#include <stdlib.h>
#include <platon/platon.hpp>

#include "multiStage.h"

namespace physicalDeviceInterface {
    class PDI:public platon::Contract {
        public:
            platon::Address carAddr;
            multiStage Stage;
            oracle Oracle;

        public:
            void init() {
                platon::println("init success...");
            }
            
            void request(const std::string id, const std::string payload, const std::string oracleAddr) {
                platon::setState(id+"value", platon::getValue());
                PLATON_EMIT_EVENT(Notify, 0, payload);
                Oracle.Set(id, oracleAddr);
                Stage.setStage(id, false, false, platon::Caller());
            }

            void prove(const std::string id, const std::string p) {
                if (platon::Caller() != carAddr) {
                    return
                }

                PLATON_EMIT_EVENT(Notify, 0, p);

                Stage.loadId(id);
                Stage.proof = true;
                Stage.updateProof();

                if Stage.verify() {
                    value = platon::getState(id+"value")
                    platon::callTransfer(carAddr,value)
                }
            }

            void message(const std::string id, const std::string p) {
                Oracle.loadId(id)
                if (platon::Caller() != Oracle.addr) {
                    return
                }

                PLATON_EMIT_EVENT(Notify, 0, p);

                Stage.loadId(id);
                Stage.oracle = true;
                Stage.updateOracle();

                if Stage.verify() {
                    value = platon::getState(id+"value")
                    platon::callTransfer(carAddr,value)
                }
            }

            void cancel(const std::string id, const std::string p) {
                Stage.loadId(id);
                if (platon::Caller() != state.sender) {
                    return
                }
                if !Stage.verify() {
                    PLATON_EMIT_EVENT(Notify, 0, p);
                    value = platon::getState(id+"value")
                    platon::callTransfer(state.sender,value)
                }
            }
    };
}


PLATON_ABI(PDI::request, request);
PLATON_ABI(PDI::prove, prove);
PLATON_ABI(PDI::message, message);
PLATON_ABI(PDI::cancel, cancel);