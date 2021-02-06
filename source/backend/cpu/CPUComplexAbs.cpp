//
//  CPUComplexAbs.cpp
//  MNNCPU
//
//  Created by Franky on 2021/2/6.
//

#include "backend/cpu/CPUComplexAbs.hpp"

namespace MNN {

CPUComplexAbs::CPUComplexAbs(Backend *b) : MNN::Execution(b) {
    // nothing to do
}

ErrorCode CPUComplexAbs::onResize(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs) {
    
    return NO_ERROR;
}

ErrorCode CPUComplexAbs::onExecute(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs) {
    
    return NO_ERROR;
}

class CPUComplexAbsCreator : public CPUBackend::Creator {
public:
    virtual Execution *onCreate(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs,
                                const MNN::Op *op, Backend *backend) const override {
        return new CPUComplexAbs(backend);
    }
};

REGISTER_CPU_OP_CREATOR(CPUComplexAbsCreator, OpType_ComplexAbs);

} // namespace MNN
