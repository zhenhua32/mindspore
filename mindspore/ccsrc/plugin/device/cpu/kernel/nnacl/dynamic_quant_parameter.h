/**
 * Copyright 2022 Huawei Technologies Co., Ltd
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

#ifndef NNACL_DYNAMIC_QUANT_PARAMETER_H_
#define NNACL_DYNAMIC_QUANT_PARAMETER_H_
#include "nnacl/op_base.h"

typedef struct DynamicQuantParameter {
  OpParameter op_parameter_;
  bool symmetric_;
  int64_t dst_type_;
  bool activation_perchannel_;
  int64_t prefer_axis_;
  bool transpose_;
} DynamicQuantParameter;

#endif  // NNACL_DYNAMIC_QUANT_PARAMETER_H_
