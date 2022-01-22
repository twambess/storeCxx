#pragma once


// Диалоговое окно CFileNew

class CFileNew : public CDialog
{
	DECLARE_DYNAMIC(CFileNew)

public:
	CFileNew(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CFileNew();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString NewFile;
};
