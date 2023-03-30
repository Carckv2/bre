//
//  Copyright 2015 Google, Inc.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at:
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#pragma once

#include <mutex>
#include <string>

namespace util {

// A simple atomic container class for std::string.
class AtomicString final {
 public:
  explicit AtomicString(const std::string& str);

  AtomicString(const AtomicString&) = delete;
  AtomicString& operator=(const AtomicString&) = delete;

  ~AtomicString() = default;

  std::string Get() const;
  void Set(const std::string& str);

 private:
  std::mutex lock_;
  std::string str_;
};

}  // namespace util
