
// StrXML.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CStrXMLApp:
// �йش����ʵ�֣������ StrXML.cpp
//

class CStrXMLApp : public CWinApp
{
public:
	CStrXMLApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CStrXMLApp theApp;