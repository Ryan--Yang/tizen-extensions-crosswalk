// Copyright (c) 2013 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SYSTEM_INFO_SYSTEM_INFO_INSTANCE_H_
#define SYSTEM_INFO_SYSTEM_INFO_INSTANCE_H_

#include <string>
#include <map>

#include "common/extension.h"
#include "common/picojson.h"

namespace picojson {
class value;
}

class SystemInfoInstance : public common::Instance {
 public:
  explicit SystemInfoInstance();
  virtual ~SystemInfoInstance();

 private:
  // common::Instance implementation.
  virtual void HandleMessage(const char* msg);
  virtual void HandleSyncMessage(const char* msg);

  void HandleGetPropertyValue(const picojson::value& input,
                              picojson::value& output);
  void HandleStartListening(const picojson::value& input);
  void HandleStopListening(const picojson::value& input);
  void HandleGetCapabilities();
  inline void SetStringPropertyValue(picojson::object& o,
                                     const char* prop,
                                     const char* val) {
    if (val)
      o[prop] = picojson::value(val);
  }
};

#endif  // SYSTEM_INFO_SYSTEM_INFO_INSTANCE_H_

