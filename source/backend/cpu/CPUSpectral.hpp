//
//  CPUSpectral.hpp
//  MNNCPU
//
//  Created by Franky on 2021/2/4.
//

#ifndef CPUSpectral_hpp
#define CPUSpectral_hpp

#include "backend/cpu/CPUBackend.hpp"

namespace MNN {
class CPUSpectral : public Execution {
public:
    CPUSpectral(Backend *b);
    virtual ~CPUSpectral() = default;
    virtual ErrorCode onResize(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs) override;
    virtual ErrorCode onExecute(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs) override;
};

} // namespace MNN

#endif /* CPUSpectral_hpp */
