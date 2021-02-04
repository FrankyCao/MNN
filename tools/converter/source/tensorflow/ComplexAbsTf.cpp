//
//  ComplexAbsTf.cpp
//  MNNConverterTF
//
//  Created by Franky on 2021/2/4.
//

#include "TfUtils.hpp"
#include "graph.pb.h"
#include "tfOpConverter.hpp"

DECLARE_OP_CONVERTER(ComplexAbsTf);

MNN::OpType ComplexAbsTf::opType() {
    return MNN::OpType_ComplexAbs;
}
MNN::OpParameter ComplexAbsTf::type() {
    return MNN::OpParameter_ComplexAbs;
}

void ComplexAbsTf::run(MNN::OpT *dstOp, TmpNode *srcNode) {
    dstOp->main.value = nullptr;
}

REGISTER_CONVERTER(ComplexAbsTf, ComplexAbs);
