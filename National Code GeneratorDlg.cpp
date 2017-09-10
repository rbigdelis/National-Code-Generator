
// National Code GeneratorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "National Code Generator.h"
#include "National Code GeneratorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CNationalCodeGeneratorDlg dialog



CNationalCodeGeneratorDlg::CNationalCodeGeneratorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_NATIONALCODEGENERATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNationalCodeGeneratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNationalCodeGeneratorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_CITY_CODE_EDIT, &CNationalCodeGeneratorDlg::OnEnChangeCityCodeEdit)
	ON_EN_CHANGE(IDC_UNIQUE_CODE_EDIT, &CNationalCodeGeneratorDlg::OnEnChangeUniqueCodeEdit)
END_MESSAGE_MAP()


// CNationalCodeGeneratorDlg message handlers

BOOL CNationalCodeGeneratorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	SendDlgItemMessage(IDC_CITY_CODE_EDIT, EM_SETLIMITTEXT, 3, 0);
	SendDlgItemMessage(IDC_UNIQUE_CODE_EDIT, EM_SETLIMITTEXT, 6, 0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNationalCodeGeneratorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNationalCodeGeneratorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CNationalCodeGeneratorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNationalCodeGeneratorDlg::OnEnChangeCityCodeEdit()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	GenerateNationalCode();
}


void CNationalCodeGeneratorDlg::OnEnChangeUniqueCodeEdit()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	GenerateNationalCode();
}

void CNationalCodeGeneratorDlg::GenerateNationalCode()
{
	CString cityCode;
	CString	uniqueCode;
	CString nationalCode;

	GetDlgItemText(IDC_CITY_CODE_EDIT, cityCode);
	GetDlgItemText(IDC_UNIQUE_CODE_EDIT, uniqueCode);

	cityCode = cityCode.Trim();
	uniqueCode = uniqueCode.Trim();
	
	while (cityCode.GetLength() < 3)
		cityCode = CString("0") + cityCode;

	while (uniqueCode.GetLength() < 6)
		uniqueCode = CString("0") + uniqueCode;

	nationalCode = cityCode + uniqueCode;
	int sum = 0;
	for (int i = 0; i < 9; i++)
		sum += (nationalCode.GetAt(i) - _T('0')) * (10 - i);

	CString temp;

	sum = sum % 11;
	if (sum < 2)
		temp.Format(_T("%d"), sum); 
	else
		temp.Format(_T("%d"), 11 - sum);
	nationalCode += temp;

	SetDlgItemText(IDC_NATIONAL_CODE_EDIT, nationalCode);
}
