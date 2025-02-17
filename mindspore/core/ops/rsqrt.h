/**
 * Copyright 2020-2021 Huawei Technologies Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MINDSPORE_CORE_OPS_RSQRT_H_
#define MINDSPORE_CORE_OPS_RSQRT_H_
#include <memory>
#include <set>
#include <vector>
#include "mindapi/base/types.h"
#include "ops/base_operator.h"

namespace mindspore {
namespace ops {
constexpr auto kNameRsqrt = "Rsqrt";
/// \brief Computes reciprocal of square root of input tensor element-wise.
/// Refer to Python API @ref mindspore.ops.Rsqrt for more details.
class MIND_API Rsqrt : public BaseOperator {
 public:
  MIND_API_BASE_MEMBER(Rsqrt);
  /// \brief Constructor.
  Rsqrt() : BaseOperator(kNameRsqrt) { InitIOName({"x"}, {"output"}); }
  /// \brief Init.
  void Init() const {}
};
MIND_API abstract::AbstractBasePtr RsqrtInfer(const abstract::AnalysisEnginePtr &, const PrimitivePtr &primitive,
                                              const std::vector<abstract::AbstractBasePtr> &input_args);
using kPrimRsqrtPtr = std::shared_ptr<Rsqrt>;
}  // namespace ops
}  // namespace mindspore

#endif  // MINDSPORE_CORE_OPS_RSQRT_H_
