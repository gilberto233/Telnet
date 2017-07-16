
// Communicate_proDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include"ServerSocket.h"
#include"ClientSocket.h"
#include"ListenSocket.h"


// CCommunicate_proDlg �Ի���
class CCommunicate_proDlg : public CDialogEx
{
// ����
public:
	CCommunicate_proDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMMUNICATE_PRO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit input_ed;
	CListBox h_list;
	CEdit port_ed;

	char buff[200];
	CString IP_Address;
	CTime _time;
	int c_or_l;

	ServerSocket *s_socket;
	ListenSocket *l_socket;
	ClientSocket *c_socket;

	afx_msg void OnBnClickedConnect();
	afx_msg void OnBnClickedDisconnect();
	afx_msg void OnBnClickedSend();

	UINT us_port;
	UINT ur_port;
};
