// CDlgEdit.cpp: файл реализации
//

#include "pch.h"
#include "Store.h"
#include "CDlgEdit.h"
#include "afxdialogex.h"


// Диалоговое окно CDlgEdit

IMPLEMENT_DYNAMIC(CDlgEdit, CDialogEx)

CDlgEdit::CDlgEdit(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_EDIT, pParent)
	, m_Value1(_T(""))
	, m_Value2(_T(""))
{

}

CDlgEdit::~CDlgEdit()
{
}

void CDlgEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Value1);
	DDX_Text(pDX, IDC_EDIT2, m_Value2);
	DDX_Control(pDX, IDCANCEL, TextValue1);
}


BEGIN_MESSAGE_MAP(CDlgEdit, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CDlgEdit::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &CDlgEdit::OnBnClickedOk)
END_MESSAGE_MAP()


// Обработчики сообщений CDlgEdit


void CDlgEdit::OnEnChangeEdit1()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CDlgEdit::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}
