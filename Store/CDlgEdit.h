#pragma once


// Диалоговое окно CDlgEdit

class CDlgEdit : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgEdit)

public:
	CDlgEdit(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CDlgEdit();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_EDIT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString m_Value1;
	CString m_Value2;
	afx_msg void OnEnChangeEdit1();
	CButton TextValue1;
	afx_msg void OnBnClickedOk();
};
