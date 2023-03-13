
// MFCApplication18.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCApplication18App:
// See MFCApplication18.cpp for the implementation of this class
//

class CMFCApplication18App : public CWinApp
{
public:
	CMFCApplication18App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication18App theApp;
