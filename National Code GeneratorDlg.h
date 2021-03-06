
// National Code GeneratorDlg.h : header file
//

#pragma once


// CNationalCodeGeneratorDlg dialog
class CNationalCodeGeneratorDlg : public CDialogEx
{
// Construction
public:
	CNationalCodeGeneratorDlg(CWnd* pParent = NULL);	// standard constructor

	void GenerateNationalCode();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NATIONALCODEGENERATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeCityCodeEdit();
	afx_msg void OnEnChangeUniqueCodeEdit();
};
