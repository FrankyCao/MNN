//
//  PlaceholderWithDefaultTf.cpp
//  MNNConverterTF
//
//  Created by Franky on 2021/2/4.
//

#include "TfUtils.hpp"
#include "graph.pb.h"
#include "tfOpConverter.hpp"

DECLARE_OP_CONVERTER(PlaceholderWithDefaultTf);

MNN::OpType PlaceholderWithDefaultTf::opType() {
    return MNN::OpType_PlaceholderWithDefault;
}
MNN::OpParameter PlaceholderWithDefaultTf::type() {
    return MNN::OpParameter_PlaceholderWithDefault;
}

void PlaceholderWithDefaultTf::run(MNN::OpT *dstOp, TmpNode *srcNode) {
    auto placeholder = new MNN::PlaceholderWithDefaultT;
    tensorflow::AttrValue value;

    if (find_attr_value(srcNode->tfNode, "dtype", value)) {
        placeholder->T = (MNN::DataType)value.type();
    }
    if (find_attr_value(srcNode->tfNode, "shape", value)) {
        if (value.shape().dim_size() > 0) {
            placeholder->shape.resize(value.shape().dim_size());
            for (int i = 0; i < value.shape().dim_size(); i++) {
                placeholder->shape[i] = value.shape().dim(i).size();
            }
        }
    }
    dstOp->main.value = placeholder;
}

REGISTER_CONVERTER(PlaceholderWithDefaultTf, PlaceholderWithDefault);
