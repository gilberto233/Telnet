// ListenSocket.cpp : 实现文件
//

#include "stdafx.h"
#include "Communicate_pro.h"
#include "ListenSocket.h"
#include"Communicate_proDlg.h"


// ListenSocket

ListenSocket::ListenSocket()
{
}

ListenSocket::~ListenSocket()
{
}


// ListenSocket 成员函数
void ListenSocket::OnAccept(int nErrorCode) {
	CCommunicate_proDlg *dlg = (CCommunicate_proDlg *)AfxGetApp()->GetMainWnd();
	dlg->c_socket = new ClientSocket;
	Accept(*(dlg->c_socket));
	dlg->c_or_l = 0;

	CString put_time;
	dlg->_time = CTime::GetCurrentTime();
	put_time = dlg->_time.Format("%X:");
	put_time += "接收请求成功，开始通信.";

	dlg->h_list.AddString(put_time);
	dlg->h_list.UpdateData(FALSE);
	dlg->GetDlgItem(IDC_SEND)->EnableWindow(TRUE);
	dlg->GetDlgItem(IDC_INPUT)->EnableWindow(TRUE);
	CAsyncSocket::OnAccept(nErrorCode);
}