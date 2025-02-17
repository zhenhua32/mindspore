# Copyright 2023 Huawei Technologies Co., Ltd
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ==============================================================================
"""
utils for dataset
"""

from mindspore._c_expression import MSContext
from functools import wraps

def ascend910b(f):
    @wraps(f)
    def decorated(*args, **kwargs):
        soc_name = MSContext.get_instance().get_ascend_soc_version()
        if not "ascend910b" in soc_name:
            return "Function will not run."
        return f(*args, **kwargs)
    return decorated
