
// TestDlg.h : ���� ���������
//

#pragma once


// ���������� ���� CTestDlg
class CTestDlg : public CDialogEx
{
// ��������
public:
	CTestDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_TestEdit;
	BOOL m_EnableCheck;
	BOOL m_VisibleCheck;
	afx_msg void OnClickedExitButton();
	afx_msg void OnClickedTestButton();
	afx_msg void OnClickedClearButton();
	afx_msg void OnClickedVisibleCheck();
	afx_msg void OnClickedEnabledCheck();
	afx_msg void OnChangeTestEdit();
};
