// ClientSocket.cpp : 实现文件
//

#include "stdafx.h"
#include "Communicate_pro.h"
#include"Communicate_proDlg.h"
#include "ClientSocket.h"


// ClientSocket

ClientSocket::ClientSocket()
{
}

ClientSocket::~ClientSocket()
{
}


// ClientSocket 成员函数
BOOL c_strcmp(char *str_1, char *str_2) {
	for (int i = 0; i < 8; i++) {
		if (str_1[i] != str_2[i]) return FALSE;
	}
	return TRUE;
}
void ClientSocket::OnReceive(int nErrorCode) {
	CCommunicate_proDlg *dlg = (CCommunicate_proDlg *)AfxGetApp()->GetMainWnd();
	CString put_string;
	dlg->_time=CTime::GetCurrentTime();
	put_string = dlg->_time.Format("%X:");
	Receive(dlg->buff, 200, 0);
	char checkcode[9] = "10001111";
	
	if (c_strcmp(dlg->buff,checkcode)) {
		//dlg->s_socket->Close();
		dlg->l_socket->Close();
		dlg->c_socket->Close();
		//delete dlg->s_socket;
		delete dlg->l_socket;
		delete dlg->c_socket;
		put_string += "断开连接.";
		dlg->h_list.AddString(put_string);
		dlg->h_list.UpdateData(FALSE);

		dlg->GetDlgItem(IDC_CONNECT)->EnableWindow(TRUE);
		dlg->GetDlgItem(IDC_PORT_S)->EnableWindow(TRUE);
		dlg->GetDlgItem(IDC_PORT_R)->EnableWindow(TRUE);
		dlg->GetDlgItem(IDC_IPADDRESS)->EnableWindow(TRUE);
		dlg->GetDlgItem(IDC_INPUT)->EnableWindow(FALSE);
		dlg->GetDlgItem(IDC_DISCONNECT)->EnableWindow(FALSE);
		dlg->GetDlgItem(IDC_SEND)->EnableWindow(FALSE);
		return;
	}

	CString Recv = dlg->buff;
	Recv = "To:" + Recv;
	Recv = put_string + Recv;
	dlg->h_list.AddString(Recv);
	dlg->h_list.UpdateData(FALSE);
	CAsyncSocket::OnReceive(nErrorCode);
}