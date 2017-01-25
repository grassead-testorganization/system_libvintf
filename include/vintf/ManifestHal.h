/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef ANDROID_VINTF_MANIFEST_HAL_H
#define ANDROID_VINTF_MANIFEST_HAL_H

#include <string>
#include <vector>

#include "HalFormat.h"
#include "ImplLevel.h"
#include "Transport.h"
#include "Version.h"

namespace android {
namespace vintf {

struct HalImplementation {
    ImplLevel implLevel = ImplLevel::EMPTY;
    std::string impl;
};

struct ManifestHal {

    // convenience constructors
    static ManifestHal hal(std::string &&name,
                           ImplLevel implLevel,
                           std::string &&impl,
                           Version version,
                           Transport transport);
    static ManifestHal hal(std::string &&name,
                           ImplLevel implLevel,
                           std::string &&impl,
                           std::vector<Version> &&versions,
                           Transport transport);
    static ManifestHal nonhal(std::string &&name,
                              std::vector<Version> &&versions);

    bool operator==(const ManifestHal &other) const;

    // Whether this hal is a valid one. Note that an empty ManifestHal
    // (constructed via ManifestHal()) is valid.
    bool isValid() const;

    HalFormat format = HalFormat::HIDL;
    std::string name;
    std::vector<Version> versions;
    HalImplementation impl;
    Transport transport = Transport::EMPTY;
};

} // namespace vintf
} // namespace android

#endif // ANDROID_VINTF_MANIFEST_HAL_H