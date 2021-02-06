//
//  TFIfTransform.cpp
//  MNNConverterOpt
//
//  Created by Franky on 2021/2/6.
//

#include <string.h>

#include "../../common/Common.hpp"
#include "../../common/Global.hpp"
#include "../SubGraphComplete.hpp"
#include "MNN_generated.h"
#include "TFExtraManager.hpp"

namespace MNN {
namespace Express {

class TFIfTransform : public TFExtraManager::Transform {
public:
    EXPRP onExecute(EXPRP expr) const override;

private:
    const Attribute* FindAttributeByName(const std::string& name) const;

private:
    mutable std::vector<const Attribute*> attributes_;
};

EXPRP TFIfTransform::onExecute(EXPRP expr) const {
    // Clear stateful members.
    attributes_.clear();

    const Op* op = expr->get();
    for (const auto& attr : *(op->main_as_Extra()->attr())) {
        attributes_.push_back(attr);
    }
    auto* if_param = new MNN::TFIfT;
    std::string then_branch_name, else_branch_name;

    auto* then_branch_attr = FindAttributeByName("then_branch");
    then_branch_name       = then_branch_attr->func()->name()->str();
    auto* else_branch_attr = FindAttributeByName("else_branch");
    else_branch_name       = else_branch_attr->func()->name()->str();
    if_param->then_branch  = then_branch_name;
    if_param->else_branch  = else_branch_name;

    std::unique_ptr<MNN::OpT> if_op(new MNN::OpT);
    if_op->type       = OpType_TFIf;
    if_op->name       = op->name()->str();
    if_op->main.type  = OpParameter_TFIf;
    if_op->main.value = if_param;
    auto if_expr      = Expr::create(if_op.get(), expr->inputs(), expr->outputSize());
    if_expr->setName(expr->name());
    int outputSize = expr->outputSize();
    for (int i = 0; i < outputSize; ++i) {
        auto if_var = Variable::create(if_expr, i);
        if_var->setName(expr->outputName(i));
    }
    return std::move(if_expr);
}

const Attribute* TFIfTransform::FindAttributeByName(const std::string& name) const {
    for (const auto* attr : attributes_) {
        if (attr->key()->str() == name) {
            return attr;
        }
    }
    return nullptr;
}

static auto gRegister = []() {
    TFExtraManager::get()->insert("If",
                                  std::shared_ptr<TFExtraManager::Transform>(new TFIfTransform));
    return true;
}();

} // namespace Express
} // namespace MNN
