//
//  CPUPlaceholderWithDefault.cpp
//  MNNCPU
//
//  Created by Franky on 2021/2/6.
//

#include "backend/cpu/CPUPlaceholderWithDefault.hpp"

namespace MNN {

CPUPlaceholderWithDefault::CPUPlaceholderWithDefault(Backend *b) : MNN::Execution(b) {
    // nothing to do
}

ErrorCode CPUPlaceholderWithDefault::onResize(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs) {
    
    return NO_ERROR;
}

ErrorCode CPUPlaceholderWithDefault::onExecute(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs) {
    
    return NO_ERROR;
}

class CPUPlaceholderWithDefaultCreator : public CPUBackend::Creator {
public:
    virtual Execution *onCreate(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs,
                                const MNN::Op *op, Backend *backend) const override {
        return new CPUPlaceholderWithDefault(backend);
    }
};

REGISTER_CPU_OP_CREATOR(CPUPlaceholderWithDefaultCreator, OpType_PlaceholderWithDefault);

} // namespace MNN
