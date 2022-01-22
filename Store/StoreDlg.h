
// StoreDlg.h: файл заголовка
//

#pragma once

#include "ListProduct.h"
#include "ListManagers.h"


// Диалоговое окно CStoreDlg
class CStoreDlg : public CDialogEx
{
// Создание
public:
	CStoreDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STORE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV



// Реализация
protected:
	HICON m_hIcon;

	ListProduct m_listProduct;
	ListManager m_listManager;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedDownload();
	afx_msg void OnBnClickedPricelist();
	afx_msg void OnBnClickedSeller();
	afx_msg void OnBnClickedStoreinfo();
	CListCtrl m_ctrlList;
	void FillListProduct();
	void FillListManager();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonEdit();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedAbort();
	afx_msg void OnBnClickedSave();
	CString _File;
	CEdit FileDisplay;
	afx_msg void OnEnChangeFile();
	afx_msg void OnBnClickedButtonNew();
};
