//
//  CPUPlaceholderWithDefault.hpp
//  MNNCPU
//
//  Created by Franky on 2021/2/6.
//

#ifndef CPUPlaceholderWithDefault_hpp
#define CPUPlaceholderWithDefault_hpp

#include "backend/cpu/CPUBackend.hpp"

namespace MNN {
class CPUPlaceholderWithDefault : public Execution {
public:
    CPUPlaceholderWithDefault(Backend *b);
    virtual ~CPUPlaceholderWithDefault() = default;
    virtual ErrorCode onResize(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs) override;
    virtual ErrorCode onExecute(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs) override;
};

} // namespace MNN

#endif /* CPUPlaceholderWithDefault_hpp */
