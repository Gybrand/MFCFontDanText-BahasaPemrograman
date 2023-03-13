
// MFCApplication18Dlg.cpp : implementation file
//

#include "pch.h"
#include "string.h"
#include "framework.h"
#include "MFCApplication18.h"
#include "MFCApplication18Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int CALLBACK EnumFontFamProc(LPENUMLOGFONT lpelf, LPNEWTEXTMETRIC lpntm, DWORD nFontType, long lParam)
{
	CMFCApplication18Dlg* pWnd = (CMFCApplication18Dlg*)lParam;
	pWnd->m_ctlFontList.AddString(lpelf->elfLogFont.lfFaceName);
	return 1;
}
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


// CMFCApplication18Dlg dialog



CMFCApplication18Dlg::CMFCApplication18Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION18_DIALOG, pParent)
	, m_strDisplayText(_T(""))
	, m_strFontName(_T(""))
	, m_strSampText(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication18Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DISPLAYTEXT, m_ctlDisplayText);
	DDX_Text(pDX, IDC_DISPLAYTEXT, m_strDisplayText);
	DDX_Control(pDX, IDC_LFONTS, m_ctlFontList);
	DDX_LBString(pDX, IDC_LFONTS, m_strFontName);
	DDX_Text(pDX, IDC_ESAMPTEXT, m_strSampText);
}

BEGIN_MESSAGE_MAP(CMFCApplication18Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(IDC_DISPLAYTEXT, &CMFCApplication18Dlg::OnStnClickedDisplaytext)
	ON_EN_CHANGE(IDC_ESAMPTEXT, &CMFCApplication18Dlg::OnEnChangeEsamptext)
END_MESSAGE_MAP()


// CMFCApplication18Dlg message handlers

BOOL CMFCApplication18Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	FillFontList();
	m_strSampText = "Testing";
	// Copy the text to the font sample area
	m_strDisplayText = m_strSampText;
	// Update the dialog
	UpdateData(FALSE);

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication18Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication18Dlg::OnPaint()
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
HCURSOR CMFCApplication18Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication18Dlg::OnStnClickedDisplaytext()
{
	// TODO: Add your control notification handler code here
}


void CMFCApplication18Dlg::OnEnChangeEsamptext()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData(TRUE);
	m_strDisplayText = m_strSampText;
	UpdateData(FALSE);
	// TODO:  Add your control notification handler code here
}


void CMFCApplication18Dlg::FillFontList()
{
	int iCount;		// The number of fonts
	int iCurCount;	// The current font
	CString strCurFont;	// The current font name
	CString strPrevFont = "";	// The previous font name
	LOGFONT lf;
	
	// Initialize the LOGFONT structure
	lf.lfCharSet = DEFAULT_CHARSET;
	strcpy_s(lf.lfFaceName, ""); // Clear the list box
	m_ctlFontList.ResetContent();
	// Create a device context variable
	CClientDC dc (this);
	// Enumerate the font families
	::EnumFontFamiliesEx((HDC)dc, &lf,(FONTENUMPROC)EnumFontFamProc, (LPARAM)this, 0);
	// Get the number of fonts in the list box
	iCount = m_ctlFontList.GetCount();
	// Loop from the last entry in the list box to the first,
	// searching for and deleting the duplicate entries
	for (iCurCount = iCount; iCurCount > 0; iCurCount--)
	{
		// Get the current font name
		m_ctlFontList.GetText((iCurCount - 1), strCurFont);
		// Is it the same as the previous font name?
		if (strCurFont == strPrevFont)
		{
			// If yes, then delete it
			m_ctlFontList.DeleteString((iCurCount - 1));
		}
		// Set the previous font name to the current font name
		strPrevFont = strCurFont;
	}
}


void CMFCApplication18Dlg::SetMyFont()
{
	// TODO: Add your implementation code here.
	CRect rRect;
	int iHeight;	
	if (m_strFontName != "")
	{
		m_ctlDisplayText.GetWindowRect(&rRect);
		iHeight = rRect.top - rRect.bottom;
		if (iHeight < 0)
			iHeight = 0 - iHeight;
		
		m_strSampText.Detach();
		m_strSampText.CreateFont((iHeight - 5), 0, 0, 0, FW_NORMAL,0, 0, 0, DEFAULT_CHARSET,
			OUT_CHARACTER_PRECIS,CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH |FF_DONTCARE, m_strFontName);
		m_ctlDisplayText.SetFont(&m_strSampText);
	}

}
