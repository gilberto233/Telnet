
// Communicate_proDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include"ServerSocket.h"
#include"ClientSocket.h"
#include"ListenSocket.h"


// CCommunicate_proDlg 对话框
class CCommunicate_proDlg : public CDialogEx
{
// 构造
public:
	CCommunicate_proDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMMUNICATE_PRO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
