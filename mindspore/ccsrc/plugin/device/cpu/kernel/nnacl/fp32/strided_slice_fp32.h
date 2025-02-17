/**
 * Copyright 2020 Huawei Technologies Co., Ltd
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
#ifndef NNACL_FP32_STRIDED_SLICE_FP32_H_
#define NNACL_FP32_STRIDED_SLICE_FP32_H_

#include "nnacl/op_base.h"
#include "nnacl/strided_slice_parameter.h"
#include "nnacl/kernel/strided_slice.h"
#ifdef __cplusplus
extern "C" {
#endif

int PadStridedSliceParameterTo8D(StridedSliceStruct *strided_slice);
int DoStridedSliceIn8D(const void *input, void *output, StridedSliceStruct *strided_slice);

void FastStride(const uint8_t *input, uint8_t *output, int split_len, int stride, size_t outer, size_t inner_size,
                size_t in_offset);

#ifdef __cplusplus
}
#endif
#endif  // MINDSPORE_NNACL_FP32_STRIDED_SLICE_FP32_H_
