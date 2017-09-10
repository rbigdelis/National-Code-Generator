
// National Code Generator.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CNationalCodeGeneratorApp:
// See National Code Generator.cpp for the implementation of this class
//

class CNationalCodeGeneratorApp : public CWinApp
{
public:
	CNationalCodeGeneratorApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CNationalCodeGeneratorApp theApp;