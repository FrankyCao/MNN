//
//  CPUComplexAbs.hpp
//  MNNCPU
//
//  Created by Franky on 2021/2/6.
//

#ifndef CPUComplexAbs_hpp
#define CPUComplexAbs_hpp

#include "backend/cpu/CPUBackend.hpp"

namespace MNN {
class CPUComplexAbs : public Execution {
public:
    CPUComplexAbs(Backend *b);
    virtual ~CPUComplexAbs() = default;
    virtual ErrorCode onResize(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs) override;
    virtual ErrorCode onExecute(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs) override;
};

} // namespace MNN

#endif /* CPUComplexAbs_hpp */
