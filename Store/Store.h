﻿
// Store.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CStoreApp:
// Сведения о реализации этого класса: Store.cpp
//

class CStoreApp : public CWinApp
{
public:
	CStoreApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CStoreApp theApp;
