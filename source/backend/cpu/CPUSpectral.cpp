//
//  CPUSpectral.cpp
//  MNNCPU
//
//  Created by Franky on 2021/2/4.
//

#include "backend/cpu/CPUSpectral.hpp"

namespace MNN {

CPUSpectral::CPUSpectral(Backend *b) : MNN::Execution(b) {
    // nothing to do
}

ErrorCode CPUSpectral::onResize(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs) {
    
    return NO_ERROR;
}

ErrorCode CPUSpectral::onExecute(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs) {
    
    return NO_ERROR;
}

class CPUSpectralCreator : public CPUBackend::Creator {
public:
    virtual Execution *onCreate(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs,
                                const MNN::Op *op, Backend *backend) const override {
        return new CPUSpectral(backend);
    }
};

REGISTER_CPU_OP_CREATOR(CPUSpectralCreator, OpType_SpectralRFFT);
REGISTER_CPU_OP_CREATOR(CPUSpectralCreator, OpType_SpectralIRFFT);

} // namespace MNN
