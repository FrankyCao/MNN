//
//  SpectralTf.cpp
//  MNNConverterTF
//
//  Created by Franky on 2021/2/2.
//

#include "TfUtils.hpp"
#include "graph.pb.h"
#include "tfOpConverter.hpp"

// ============================ SpectralRFFT ============================
DECLARE_OP_CONVERTER(SpectralRFFTTf);

MNN::OpType SpectralRFFTTf::opType() {
    return MNN::OpType_SpectralRFFT;
}
MNN::OpParameter SpectralRFFTTf::type() {
    return MNN::OpType_SpectralRFFT;
}

void SpectralRFFTTf::run(MNN::OpT *dstOp, TmpNode *srcNode) {
    auto spectral = new MNN::SpectralT;
    

}

REGISTER_CONVERTER(SpectralRFFTTf, RFFT);

// ============================ SpectralIRFFT ============================
DECLARE_OP_CONVERTER(SpectralIRFFTTf);

MNN::OpType SpectralIRFFTTf::opType() {
    return MNN::OpType_SpectralIRFFT;
}
MNN::OpParameter SpectralIRFFTTf::type() {
    return MNN::OpType_SpectralIRFFT;
}

void SpectralIRFFTTf::run(MNN::OpT *dstOp, TmpNode *srcNode) {
    

}

REGISTER_CONVERTER(SpectralIRFFTTf, IRFFT);
