/**
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd.  All rights reserved.
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

#include "inc/adjust_contrastv2_op.h"
#include "register/op_impl_registry.h"
#include "utils/util.h"
#include "utils/common_shape_fns.h"

namespace ge {
CUST_IMPLEMT_INFERFUNC(AdjustContrast, AdjustContrastInfer) {
  auto op_desc = OpDescUtils::GetOpDescFromOperator(op);

  GeShape shape;
  std::string err_msg;
  auto contrast_factor_desc = op_desc->MutableInputDesc(1);
  if (WithRank(contrast_factor_desc, 0, shape, op) != GRAPH_SUCCESS) {
    err_msg = GetShapeErrMsg(1, DebugString(contrast_factor_desc->GetShape().GetDims()), "scalar");
    err_msg = string("failed to call WithRank function, ") + err_msg;
    AICPU_INFER_SHAPE_CALL_ERR_REPORT(TbeGetName(op), err_msg);
    return GRAPH_FAILED;
  }
  auto images_desc = op_desc->MutableInputDesc(0);
  if (WithRankAtLeast(images_desc, 3, shape, op) != GRAPH_SUCCESS) {
    err_msg = GetShapeErrMsg(0, DebugString(images_desc->GetShape().GetDims()), "at least 3D");
    err_msg = string("failed to call WithRankAtLeast function, ") + err_msg;
    AICPU_INFER_SHAPE_CALL_ERR_REPORT(TbeGetName(op), err_msg);
    return GRAPH_PARAM_INVALID;
  }

  auto y_desc = op_desc->MutableOutputDesc(0);
  y_desc->SetShape(shape);
  y_desc->SetDataType(images_desc->GetDataType());

  return GRAPH_SUCCESS;
}

CUST_INFER_FUNC_REG(AdjustContrast, AdjustContrastInfer);
}  // namespace ge