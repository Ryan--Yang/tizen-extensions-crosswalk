// Copyright (c) 2013 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <utility>
#include <string>

#include "system_info/system_info_extension.h"
#include "system_info/system_info_instance.h"
#include "system_info/system_info_utils.h"
#include "system_info/system_info_battery.h"
#include "system_info/system_info_build.h"
#include "system_info/system_info_cellular_network.h"
#include "system_info/system_info_cpu.h"
#include "system_info/system_info_device_orientation.h"
#include "system_info/system_info_display.h"
#include "system_info/system_info_locale.h"
#include "system_info/system_info_network.h"
#include "system_info/system_info_peripheral.h"
#include "system_info/system_info_sim.h"
#include "system_info/system_info_storage.h"
#include "system_info/system_info_wifi_network.h"

void InstancesMapInitialize() {
  sys_instances_map_.insert(std::pair<std::string, SysInfoObject&>(
      "BATTERY", SysInfoBattery::GetSysInfoBattery()));
  sys_instances_map_.insert(std::pair<std::string, SysInfoObject&>(
      "BUILD", SysInfoBuild::GetSysInfoBuild()));
  sys_instances_map_.insert(std::pair<std::string, SysInfoObject&>(
      "CELLULAR_NETWORK", SysInfoCellularNetwork::GetSysInfoCellularNetwork()));
  sys_instances_map_.insert(std::pair<std::string, SysInfoObject&>(
      "CPU", SysInfoCpu::GetSysInfoCpu()));
  sys_instances_map_.insert(std::pair<std::string, SysInfoObject&>(
      "DEVICE_ORIENTATION",
      SysInfoDeviceOrientation::GetSysInfoDeviceOrientation()));
  sys_instances_map_.insert(std::pair<std::string, SysInfoObject&>(
      "DISPLAY", SysInfoDisplay::GetSysInfoDisplay()));
  sys_instances_map_.insert(std::pair<std::string, SysInfoObject&>(
      "LOCALE", SysInfoLocale::GetSysInfoLocale()));
  sys_instances_map_.insert(std::pair<std::string, SysInfoObject&>(
      "SIM", SysInfoSim::GetSysInfoSim()));
  sys_instances_map_.insert(std::pair<std::string, SysInfoObject&>(
      "STORAGE", SysInfoStorage::GetSysInfoStorage()));
  sys_instances_map_.insert(std::pair<std::string, SysInfoObject&>(
      "NETWORK", SysInfoNetwork::GetSysInfoNetwork()));
  sys_instances_map_.insert(std::pair<std::string, SysInfoObject&>(
      "PERIPHERAL", SysInfoPeripheral::GetSysInfoPeripheral()));
  sys_instances_map_.insert(std::pair<std::string, SysInfoObject&>(
      "WIFI_NETWORK", SysInfoWifiNetwork::GetSysInfoWifiNetwork()));
}

common::Extension* CreateExtension() {
  return new SystemInfoExtension;
}

// This will be generated from system_info_api.js.
extern const char kSource_system_info_api[];

SystemInfoExtension::SystemInfoExtension() {
  SetExtensionName("tizen.systeminfo");
  SetJavaScriptAPI(kSource_system_info_api);
  InstancesMapInitialize();
}

SystemInfoExtension::~SystemInfoExtension() {}

common::Instance* SystemInfoExtension::CreateInstance() {
  return new SystemInfoInstance;
}


