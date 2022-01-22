
// StoreDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Store.h"
#include "StoreDlg.h"
#include "afxdialogex.h"
#include "CDlgEdit.h"
#include "CFileNew.h"
#include "direct.h"


#include <iostream>
#include <clocale>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int flag = 0;
CString path = L"";


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CStoreDlg



CStoreDlg::CStoreDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STORE_DIALOG, pParent)
	, _File(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ListInfo, m_ctrlList);
	DDX_Control(pDX, IDC_FILE, FileDisplay);
}

BEGIN_MESSAGE_MAP(CStoreDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Download, &CStoreDlg::OnBnClickedDownload)
	ON_BN_CLICKED(IDC_Pricelist, &CStoreDlg::OnBnClickedPricelist)
	ON_BN_CLICKED(IDC_Seller, &CStoreDlg::OnBnClickedSeller)
	ON_BN_CLICKED(IDC_StoreInfo, &CStoreDlg::OnBnClickedStoreinfo)
	ON_BN_CLICKED(IDD_BUTTON_ADD, &CStoreDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_EDIT, &CStoreDlg::OnBnClickedButtonEdit)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CStoreDlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDABORT, &CStoreDlg::OnBnClickedAbort)
	ON_BN_CLICKED(IDC_SAVE, &CStoreDlg::OnBnClickedSave)
	ON_EN_CHANGE(IDC_FILE, &CStoreDlg::OnEnChangeFile)
	ON_BN_CLICKED(IDC_BUTTON_NEW, &CStoreDlg::OnBnClickedButtonNew)
END_MESSAGE_MAP()


// Обработчики сообщений CStoreDlg

BOOL CStoreDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок



	/*for (int i = 0; i < 30; i++) {
		CString sProduct; 
		sProduct.Format(L"Товар №%d", i + 1);
		
		Product stProd;
		stProd.SetName(sProduct);

		stProd.SetPrice(rand() % 100 + 1);

		stProd.SetAmount(rand() % 100 + 1);

		m_listProduct.PushBack(&stProd);
	}
	

	for (int i = 0; i < 10; i++) {
		CString sManager;
		sManager.Format(L"Продавец №%d", i + 1);

		Manager stMan;
		stMan.SetName(sManager);


		sManager.Format(L"Позиция №%d", i + 1);
		stMan.SetPosition(sManager);

		m_listManager.PushBack(&stMan);
	}
	*/
	_mkdir("C:\\StoreDatabase");
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CStoreDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CStoreDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CStoreDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CStoreDlg::OnBnClickedDownload()
{
	setlocale(LC_ALL, "Russian");
	CFileDialog filedlg(TRUE, L"dat");
	if (IDOK == filedlg.DoModal())
	{
		path = filedlg.GetPathName();
		FileDisplay.SetWindowTextW(filedlg.GetFileName());
		CStdioFile myFile;
		CString bufProd;
		CString bufMan;
		CString buf;
		int i,last_i = 0;
		float bufPrice;
		int bufAmount;
		Product stProd;
		Manager stMan;
		if (myFile.Open(path, CFile::modeRead))
		{
			myFile.ReadString(bufProd);
			myFile.ReadString(bufMan);

		}
		m_listProduct.Clear();
		m_listManager.Clear();
		last_i = 0;
		i = 0;
		while (i != bufProd.ReverseFind('|'))
		{
			i = bufProd.Find('|', last_i);
			if (i == -1 && i == last_i)
			{
				MessageBox(L"Файл поврежден");
				return;
			}
			stProd.SetName(bufProd.Mid(last_i, i - last_i));
			last_i = i + 1;
			i = bufProd.Find('|', last_i);
			if (i == -1 && i == last_i)
			{
				MessageBox(L"Файл поврежден");
				return;
			}
			buf = bufProd.Mid(last_i, i - last_i);
			bufPrice = _ttof(buf);
			stProd.SetPrice(bufPrice);
			last_i = i + 1;
			i = bufProd.Find('|', last_i);
			if (i == -1 && i == last_i)
			{
				MessageBox(L"Файл поврежден");
				return;
			}
			buf = bufProd.Mid(last_i, i - last_i);
			bufAmount = _ttof(buf);
			stProd.SetAmount(bufAmount);

			m_listProduct.PushBack(&stProd);
			last_i = i + 1;

		}
		last_i = 0;

		
		while (i != bufMan.ReverseFind('|'))
		{
			i = bufMan.Find('|', last_i);

			if (i == -1 && i == last_i)
			{
				MessageBox(L"Файл поврежден");
				return;
			}
			stMan.SetName(bufMan.Mid(last_i, i - last_i));
			last_i = i + 1;
			i = bufMan.Find('|', last_i);
			if (i == -1 && i == last_i)
			{
				MessageBox(L"Файл поврежден");
				return;
			}
			stMan.SetPosition(bufMan.Mid(last_i, i - last_i));
			m_listManager.PushBack(&stMan);
			last_i = i + 1;

		}
		flag = 1;
		FillListProduct();



	}
	
}


void CStoreDlg::OnBnClickedPricelist()
{
	flag = 1;
	FillListProduct();
}


void CStoreDlg::OnBnClickedSeller()
{
	flag = 2;
	FillListManager();
}


void CStoreDlg::OnBnClickedStoreinfo()
{
	flag = 3;
	FillListProduct();
}


void CStoreDlg::FillListProduct()
{


		m_ctrlList.DeleteAllItems();

		
		if (flag == 1)
		{
			Product* stProd = m_listProduct.GetFirst();
			m_ctrlList.DeleteColumn(0);
			m_ctrlList.DeleteColumn(0);
			m_ctrlList.InsertColumn(0, L"Товар", LVCFMT_LEFT, 200);
			m_ctrlList.InsertColumn(1, L"Цена", LVCFMT_LEFT, 50);
			while (stProd != NULL) {
				int nItem = m_ctrlList.InsertItem(m_ctrlList.GetItemCount(), stProd->GetName(), -1);

				CString sPrice;
				sPrice.Format(L"%g", stProd->GetPrice());

				m_ctrlList.SetItemText(nItem, 1, sPrice);

				m_ctrlList.SetItemData(nItem, (DWORD_PTR)stProd);

				stProd = m_listProduct.GetNext();
			}
		}
		if (flag == 3)
		{
			Product* stProd = m_listProduct.GetFirst();
			m_ctrlList.DeleteColumn(0);
			m_ctrlList.DeleteColumn(0);
			m_ctrlList.InsertColumn(0, L"Товар", LVCFMT_LEFT, 200);
			m_ctrlList.InsertColumn(1, L"Кол-во", LVCFMT_LEFT, 50);
			while (stProd != NULL) {
				int nItem = m_ctrlList.InsertItem(m_ctrlList.GetItemCount(), stProd->GetName(), -1);

				CString sCount;
				sCount.Format(L"%d", stProd->GetAmount());

				m_ctrlList.SetItemText(nItem, 1, sCount);

				m_ctrlList.SetItemData(nItem, (DWORD_PTR)stProd);

				stProd = m_listProduct.GetNext();
			}

		}
		
	
}

void CStoreDlg::FillListManager()
{
	m_ctrlList.DeleteColumn(0);
	m_ctrlList.DeleteColumn(0);
	m_ctrlList.InsertColumn(0, L"Менеджер", LVCFMT_LEFT, 200);
	m_ctrlList.InsertColumn(1, L"Позиция", LVCFMT_LEFT, 200);
	m_ctrlList.DeleteAllItems();

	Manager* stMan = m_listManager.GetFirst();

	while (stMan != NULL) {
		int nItem = m_ctrlList.InsertItem(m_ctrlList.GetItemCount(), stMan->GetName(), -1);

		CString sPosition;

		m_ctrlList.SetItemText(nItem, 1, stMan->GetPosition());

		m_ctrlList.SetItemData(nItem, (DWORD_PTR)stMan);

		stMan = m_listManager.GetNext();
	}
}


void CStoreDlg::OnBnClickedButtonAdd()
{
	CDlgEdit dlg;
	
	if (flag == 0)
	{ 
		MessageBox(L"Выберите раздел для редактирования", L"Предупреждение", MB_OK | MB_ICONINFORMATION);
		return;
	}

	if (IDOK == dlg.DoModal())
	{
		if (flag == 1) {


			Product stProd;
			stProd.SetName(dlg.m_Value1);
			stProd.SetPrice(_ttof(dlg.m_Value2));

			m_listProduct.PushBack(&stProd);

			FillListProduct();
		}
		if (flag == 2)
		{
			Manager stMan;
			stMan.SetName(dlg.m_Value1);
			stMan.SetPosition(dlg.m_Value2);

			m_listManager.PushBack(&stMan);

			FillListManager();
		}
		if (flag == 3)
		{
			Product stProd;
			stProd.SetName(dlg.m_Value1);
			stProd.SetAmount(_ttof(dlg.m_Value2));

			m_listProduct.PushBack(&stProd);

			FillListProduct();
		}
	}

}


void CStoreDlg::OnBnClickedButtonEdit()
{

	if (flag == 0)
	{
		MessageBox(L"Выберите раздел для редактирования", L"Предупреждение", MB_OK | MB_ICONINFORMATION);
		return;
	}
	if (m_ctrlList.GetSelectedCount() == 0)
	{
		MessageBox(L"Выберите элемент для редактирования", L"Предупреждение", MB_OK | MB_ICONINFORMATION);
		return;
	}

	POSITION pos = m_ctrlList.GetFirstSelectedItemPosition();

	if (pos != NULL)
	{
		int nINdex = m_ctrlList.GetNextSelectedItem(pos);
		if (flag == 1)
		{
			Product* stProd = (Product*)m_ctrlList.GetItemData(nINdex);

			if (stProd == NULL)
			{
				return;
			}

			CDlgEdit dlg;
			dlg.m_Value1 = stProd->GetName();
			CString form;
			form.Format(_T("%.2g"), stProd->GetPrice());
			dlg.m_Value2 = form;

			if (IDOK == dlg.DoModal())
			{
				stProd->SetName(dlg.m_Value1);
				stProd->SetPrice(_ttof(dlg.m_Value2));

				FillListProduct();
			}
		}
		if (flag == 2)
		{
			Manager* stMan = (Manager*)m_ctrlList.GetItemData(nINdex);

			if (stMan == NULL)
			{
				return;
			}

			CDlgEdit dlg;
			dlg.m_Value1 = stMan->GetName();
			dlg.m_Value2 = stMan->GetPosition();

			if (IDOK == dlg.DoModal())
			{
				stMan->SetName(dlg.m_Value1);
				stMan->SetPosition(dlg.m_Value2);

				FillListManager();
			}
		}
		if (flag == 3)
		{
			Product* stProd = (Product*)m_ctrlList.GetItemData(nINdex);

			if (stProd == NULL)
			{
				return;
			}

			CDlgEdit dlg;
			dlg.m_Value1 = stProd->GetName();
			CString form;
			form.Format(_T("%d"), stProd->GetAmount());
			dlg.m_Value2 = form;

			if (IDOK == dlg.DoModal())
			{
				stProd->SetName(dlg.m_Value1);
				stProd->SetAmount(_ttof(dlg.m_Value2));

				FillListProduct();
			}
		}
		 
	}

}


void CStoreDlg::OnBnClickedButtonDelete()
{

	if (flag == 0)
	{
		MessageBox(L"Выберите раздел для редактирования", L"Предупреждение", MB_OK | MB_ICONINFORMATION);
		return;
	}
	POSITION pos = m_ctrlList.GetFirstSelectedItemPosition();

	if (pos == NULL)
	{
		MessageBox(L"Выберите элемент для удаления", L"Предупреждение", MB_OK | MB_ICONINFORMATION);
		return;
	}

	int nIndex = m_ctrlList.GetNextSelectedItem(pos);
	if (flag == 1 | flag == 3)
	{
		Product* stProd = (Product*)m_ctrlList.GetItemData(nIndex);

		if (IDYES != MessageBox(L"Удалить строку?", L"Предупреждение", MB_YESNO | MB_ICONQUESTION))
		{
			return;
		}

		for (Product* cur = m_listProduct.GetFirst(); cur != NULL; cur = m_listProduct.GetNext())
		{
			if (cur == stProd)
			{
				m_listProduct.RemoveCurrent();
				break;
			}


		}

		FillListProduct();
	}
	if (flag == 2)
	{
		Manager* stProd = (Manager*)m_ctrlList.GetItemData(nIndex);

		if (IDYES != MessageBox(L"Удалить строку?", L"Предупреждение", MB_YESNO | MB_ICONQUESTION))
		{
			return;
		}

		for (Manager* cur = m_listManager.GetFirst(); cur != NULL; cur = m_listManager.GetNext())
		{
			if (cur == stProd)
			{
				m_listManager.RemoveCurrent();
				break;
			}
		}
		FillListManager();
	}
}


void CStoreDlg::OnBnClickedAbort()
{
	CAboutDlg dlg;
	dlg.DoModal();
}


void CStoreDlg::OnBnClickedSave()
{
	
	if (path == L"")
	{
		CStoreDlg::OnBnClickedButtonNew();
	}

	setlocale(LC_ALL, "Russian");
	CStdioFile myFile;
	CString bufProd = L"";
	CString bufMan = L"";
	Product* stProd = m_listProduct.GetFirst();
	Manager* stMan = m_listManager.GetFirst();
	while (stProd != NULL) {
		CString sPrice;
		sPrice.Format(L"%g", stProd->GetPrice());

		CString sAmount;
		sAmount.Format(L"%d", stProd->GetAmount());

		bufProd = bufProd + + stProd->GetName() + L"|" + sPrice + L"|" + sAmount + L"|";
		stProd = m_listProduct.GetNext();
	}

	while (stMan != NULL) {


		bufMan = bufMan + stMan->GetName() + L"|" + stMan->GetPosition() + L"|";
		stMan = m_listManager.GetNext();
	}
	
	try
	{
	if (myFile.Open(path, CStdioFile::modeCreate | CStdioFile::modeWrite))
	{
		myFile.SeekToBegin();
		myFile.WriteString(bufProd);
		myFile.WriteString(L"\n");	
		myFile.WriteString(bufMan);
		myFile.Close();
		MessageBox(L"Файл сохранен", L"Информация", MB_ICONINFORMATION);
	}
	}
	catch (const std::exception&)
	{
		MessageBox(L"Не удалось сохранить файл ", L"Ошибка", MB_ICONERROR);
	}

}


void CStoreDlg::OnEnChangeFile()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CStoreDlg::OnBnClickedButtonNew()
{
	CFileNew dlg;
	CFile myFile;
	if (IDOK == dlg.DoModal())
	{
		CString NewPath = L"C:\\StoreDatabase\\" + dlg.NewFile + L".dat";

		if (GetFileAttributes(NewPath) != INVALID_FILE_ATTRIBUTES)
		{
			if (IDYES == MessageBox(L"Введенный файл уже существует, заменить?", L"Предупреждение", MB_YESNO | MB_ICONQUESTION))
			{
				path = NewPath;
				m_listProduct.Clear();
				m_listManager.Clear();
				FillListProduct();
				if (myFile.Open(path, CStdioFile::modeCreate))
				{
					myFile.Close();
				}
				FileDisplay.SetWindowTextW(dlg.NewFile);
			}
			else return;
		}
		path = NewPath;
		m_listProduct.Clear();
		m_listManager.Clear();
		FillListProduct();
		if (myFile.Open(path, CStdioFile::modeCreate))
		{
			myFile.Close();
		}
		FileDisplay.SetWindowTextW(dlg.NewFile);
	}
}
