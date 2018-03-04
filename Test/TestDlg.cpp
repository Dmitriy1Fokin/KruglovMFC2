
// TestDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "Test.h"
#include "TestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
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


// ���������� ���� CTestDlg



CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST_DIALOG, pParent)
	, m_TestEdit(_T(""))
	, m_EnableCheck(FALSE)
	, m_VisibleCheck(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TEST_EDIT, m_TestEdit);
	DDX_Check(pDX, IDC_ENABLED_CHECK, m_EnableCheck);
	DDX_Check(pDX, IDC_VISIBLE_CHECK, m_VisibleCheck);
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT_BUTTON, &CTestDlg::OnClickedExitButton)
	ON_BN_CLICKED(IDC_TEST_BUTTON, &CTestDlg::OnClickedTestButton)
	ON_BN_CLICKED(IDC_CLEAR_BUTTON, &CTestDlg::OnClickedClearButton)
	ON_BN_CLICKED(IDC_VISIBLE_CHECK, &CTestDlg::OnClickedVisibleCheck)
	ON_BN_CLICKED(IDC_ENABLED_CHECK, &CTestDlg::OnClickedEnabledCheck)
	ON_EN_CHANGE(IDC_TEST_EDIT, &CTestDlg::OnChangeTestEdit)
END_MESSAGE_MAP()


// ����������� ��������� CTestDlg

BOOL CTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
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

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

	//��������� ���������� ������ VisibleCheck � EnabledCheck � ���������
	//TRUE
	m_VisibleCheck = TRUE;
	m_EnableCheck = TRUE;
	//�������� �����
	UpdateData(FALSE);
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestDlg::OnClickedExitButton()
{
	OnOK();
}


void CTestDlg::OnClickedTestButton()
{
	m_TestEdit = "This is a Test.";
	UpdateData(FALSE);
}


void CTestDlg::OnClickedClearButton()
{
	m_TestEdit = " ";
	UpdateData(FALSE);
}


void CTestDlg::OnClickedVisibleCheck()
{
	UpdateData(TRUE);
	
	if (m_VisibleCheck == TRUE)
		GetDlgItem(IDC_TEST_EDIT)->ShowWindow(SW_SHOW);
	else
		GetDlgItem(IDC_TEST_EDIT)->ShowWindow(SW_HIDE);
}


void CTestDlg::OnClickedEnabledCheck()
{
	UpdateData(TRUE);

	if (m_EnableCheck == TRUE)
		GetDlgItem(IDC_TEST_EDIT)->EnableWindow(SW_SHOW);
	else
		GetDlgItem(IDC_TEST_EDIT)->EnableWindow(SW_HIDE);
}


void CTestDlg::OnChangeTestEdit()
{
	UpdateData(TRUE);

	CString UpperValue;
	UpperValue = m_TestEdit;
	UpperValue.MakeUpper();

	if (UpperValue == "PAINT")
	{
		system("pbrush.exe");
		m_TestEdit = " ";
		UpdateData(FALSE);
	}

	if (UpperValue == "CALCULATOR")
	{
		system("calc.exe");
		m_TestEdit = " ";
		UpdateData(FALSE);
	}

	if (UpperValue == "BEEP")
	{
		MessageBeep((WORD)-2);
		m_TestEdit = " ";
		UpdateData(FALSE);
	}
}
