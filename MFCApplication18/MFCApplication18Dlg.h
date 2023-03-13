
// MFCApplication18Dlg.h : header file
//

#pragma once
int CALLBACK EnumFontFamProc(LPENUMLOGFONT lpelf, LPNEWTEXTMETRIC lpntm, DWORD nFontType, long lParam);

// CMFCApplication18Dlg dialog
class CMFCApplication18Dlg : public CDialogEx
{
// Construction
public:
	CMFCApplication18Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION18_DIALOG };
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
	CStatic m_ctlDisplayText;
	afx_msg void OnStnClickedDisplaytext();
	CString m_strDisplayText;
	CListBox m_ctlFontList;
	CString m_strFontName;
	CString m_strSampText;
	afx_msg void OnEnChangeEsamptext();
private:
	void FillFontList();
	void SetMyFont();
};
