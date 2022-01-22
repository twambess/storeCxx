// CFileNew.cpp: файл реализации
//

#include "pch.h"
#include "Store.h"
#include "CFileNew.h"
#include "afxdialogex.h"


// Диалоговое окно CFileNew

IMPLEMENT_DYNAMIC(CFileNew, CDialog)

CFileNew::CFileNew(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
	, NewFile(_T(""))
{

}

CFileNew::~CFileNew()
{
}

void CFileNew::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FILENAME, NewFile);
}


BEGIN_MESSAGE_MAP(CFileNew, CDialog)
END_MESSAGE_MAP()


// Обработчики сообщений CFileNew
