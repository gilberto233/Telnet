
// Communicate_pro.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCommunicate_proApp: 
// �йش����ʵ�֣������ Communicate_pro.cpp
//

class CCommunicate_proApp : public CWinApp
{
public:
	CCommunicate_proApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCommunicate_proApp theApp;