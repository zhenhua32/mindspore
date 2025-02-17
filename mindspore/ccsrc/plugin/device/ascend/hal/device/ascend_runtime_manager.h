/**
 * Copyright 2023 Huawei Technologies Co., Ltd
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

#ifndef MINDSPORE_CCSRC_RUNTIME_DEVICE_ASCEND_ASCEND_RUNTIME_MANAGER_H_
#define MINDSPORE_CCSRC_RUNTIME_DEVICE_ASCEND_ASCEND_RUNTIME_MANAGER_H_

#include <map>
#include <memory>
#include <string>
#include <functional>
#include <utility>
#include <mutex>
#include <unordered_set>
#include <vector>
#include "utils/ms_utils.h"
#include "utils/ms_context.h"
#include "plugin/device/ascend/hal/device/ascend_kernel_runtime.h"

namespace mindspore::device::ascend {
using AscendRuntimeCreator = std::function<std::shared_ptr<AscendKernelRuntime>()>;

class AscendRuntimeManager {
 public:
  static AscendRuntimeManager &Instance();
  void Register(const std::string &device_name, AscendRuntimeCreator &&runtime_creator) const;
  AscendKernelRuntime *GetAscendRuntime(const std::string &device_name, uint32_t device_id);

 private:
  AscendRuntimeManager() = default;
  ~AscendRuntimeManager() = default;
  inline static std::map<std::string, std::shared_ptr<AscendKernelRuntime> > runtime_map_;
  inline static std::map<std::string, AscendRuntimeCreator> runtime_creators_;
  std::mutex lock_;
};

class AscendRuntimeRegistrar {
 public:
  AscendRuntimeRegistrar(const std::string &device_name, AscendRuntimeCreator &&runtime_creator) {
    AscendRuntimeManager::Instance().Register(device_name, std::move(runtime_creator));
  }
  ~AscendRuntimeRegistrar() = default;
};

#define REG_ASCEND_RUNTIME(DEVICE_NAME, RUNTIME_CLASS)                      \
  static const AscendRuntimeRegistrar g_ascend_runtime_##DEVICE_NAME##_reg( \
    DEVICE_NAME, []() { return std::make_shared<RUNTIME_CLASS>(); });
}  // namespace mindspore::device::ascend

#endif  // MINDSPORE_CCSRC_RUNTIME_DEVICE_ASCEND_ASCEND_RUNTIME_MANAGER_H_
