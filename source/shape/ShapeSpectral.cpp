//
//  ShapeSpectral.cpp
//  MNN
//
//  Created by Franky on 2021/2/3.
//

#include "shape/SizeComputer.hpp"
#include "core/Macro.h"
#include "core/TensorUtils.hpp"

namespace MNN {

class SpectralComputer : public SizeComputer {
public:
    virtual bool onComputeSize(const MNN::Op* op, const std::vector<Tensor*>& inputs,
                               const std::vector<Tensor*>& outputs) const override {
        MNN_ASSERT(2 == inputs.size());
        MNN_ASSERT(1 == outputs.size());
        
        int rank = 1;
        auto input0 = inputs[0];
        auto input1 = inputs[1];
        MNN_ASSERT(input0->dimensions() >= rank);
        MNN_ASSERT(input1->dimensions() == 1);
        MNN_ASSERT(input1->length(0) == rank);
        
        auto output = outputs[0];
        output->buffer().type = input0->buffer().type;
        TensorUtils::copyShape(input0, output, true);
        auto fft_length_as_vec = input1->host<int32_t>();
        bool forward = (OpType_SpectralRFFT == op->type());
        for (int i = 0; i < rank; ++i) {
            auto dim = forward && i == rank - 1 && fft_length_as_vec[i] != 0
                       ? fft_length_as_vec[i] / 2 + 1
                       : fft_length_as_vec[i];
            int64_t dim_index = i - rank;
            if (dim_index < 0) {
                dim_index = input0->dimensions() + dim_index;
            }
            MNN_ASSERT(dim_index <= input0->dimensions());
            output->setLength(dim_index, dim);
        }
        return true;
    }
};

REGISTER_SHAPE(SpectralComputer, OpType_SpectralRFFT);
REGISTER_SHAPE(SpectralComputer, OpType_SpectralIRFFT);

} // namespace MNN
