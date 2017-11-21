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
	
	// ��ʼ��������
	base::CommandLine::Init(argc, argv);
	//base::AtExitManager at_exit;

	logging::LoggingSettings settings;
	
	settings.logging_dest = logging::LOG_TO_ALL;
	// log���ļ���
	settings.log_file = L"test_base.log";

	logging::InitLogging(settings);

	//log�Ƿ��¼����id,�߳�id,ʱ�������ȷʱ��
	logging::SetLogItems(true, true, false, false);

	LOG(INFO) << "����";
	LOG(INFO) << L"Test";		// ������ʾ
	LOG(INFO) << L"�й�";		// �����룬��Ϊ���ַ�����������أ�ʹ��UTF8ת�������Բ�֧�ֿ��ַ����������

	// �������
	LOG_IF(WARNING, true) << "LOG_IF true";
	LOG_IF(WARNING, false) << "LOG_IF false";

	// ���ϵ���־��DEBUGģʽ�´���־��ǰ׺D
	/*
	DLOG(INFO) << "INFO";
	DLOG(WARNING) << "WARNING";
	DLOG(ERROR) << "ERROR";
	*/

	// CHECK����debug��relesseģʽ�¶���ʹ
	//CHECK(false);	// CHECK��condition���=false�������LOG(FATAL)��LOG(FATAL)����~LogMessageʱ�������̣�������dump
	CHECK(true);  // CHECK��condition���=True ����ִ��

	// ͬCHECK����DLOG_ASSERT
	LOG_ASSERT(true); // LOG_IF(FATAL, !(condition))

	// VLOG������LOG(INFO)����INFO֮���ַּ�
	VLOG(1) << "I'm printed when you run the program with --v=1 or more";

	//VLOG
	system("pause");
    return 0;
}
