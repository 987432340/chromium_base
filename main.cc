// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/bind.h"
#include "base/memory/scoped_ptr.h"
#include "base/threading/sequenced_worker_pool.h"
#include "base/threading/thread.h"
#include <iostream>
#include "base/logging.h"
#include "base/command_line.h"
#include "base/at_exit.h"


using namespace std;

int main(int argc, char* argv[]) {
	
	// 初始化命令行
	base::CommandLine::Init(argc, argv);
	//base::AtExitManager at_exit;

	logging::LoggingSettings settings;
	
	settings.logging_dest = logging::LOG_TO_ALL;
	// log的文件名
	settings.log_file = L"test_base.log";

	logging::InitLogging(settings);

	//log是否记录进程id,线程id,时间戳，精确时间
	logging::SetLogItems(true, true, false, false);

	LOG(INFO) << "测试";
	LOG(INFO) << L"Test";		// 正常显示
	LOG(INFO) << L"中国";		// 会乱码，因为宽字符输出流被重载，使用UTF8转换，所以不支持宽字符的中文输出
	// 条件输出
	LOG_IF(WARNING, true) << "LOG_IF true";
	LOG_IF(WARNING, false) << "LOG_IF false";
	
	// CHECK宏在debug、relesse模式下都好使。CHECK的condition如果=false，会调用LOG(FATAL)。LOG(FATAL)会结束进程，并生成dump
	// ~LogMessage
	CHECK(false);
	CHECK(true);

	/*DLOG(INFO) << "INFO";
	DLOG(WARNING) << "WARNING";
	DLOG(ERROR) << "ERROR";
	*/
	//LOG_IF(INFO, true) << "LOG_IF INFO";
	//LOG_IF(WARNING, false) << "LOG_IF WARNING";
	//LOG_IF(ERROR, true) << "LOG_IF ERROR";
	//logging::LOG_INFO
	system("pause");
    return 0;
}
