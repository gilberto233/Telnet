// ServerSocket.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Communicate_pro.h"
#include "ServerSocket.h"
#include"Communicate_proDlg.h"


// ServerSocket

ServerSocket::ServerSocket()
{
}

ServerSocket::~ServerSocket()
{
}


// ServerSocket ��Ա����
void ServerSocket::OnConnect(int nErrorCode) {
	CCommunicate_proDlg *dlg = (CCommunicate_proDlg *)AfxGetApp()->GetMainWnd();
	CString put_time;
	if (nErrorCode == 0) {
		dlg->_time=CTime::GetCurrentTime();
		put_time = dlg->_time.Format("%X:");
		put_time += "���ӳɹ�����ʼͨ��.";
		dlg->c_or_l = 1;

		dlg->h_list.AddString(put_time);
		dlg->h_list.UpdateData(FALSE);

		dlg->GetDlgItem(IDC_DISCONNECT)->EnableWindow(TRUE);
		dlg->GetDlgItem(IDC_SEND)->EnableWindow(TRUE);
		dlg->GetDlgItem(IDC_INPUT)->EnableWindow(TRUE);
	}
	else {
		dlg->_time=CTime::GetCurrentTime();
		put_time = dlg->_time.Format("%X:");
		put_time += "����ʧ�ܣ���ʼ����.";

		dlg->s_socket->Close();
		delete dlg->s_socket;

		dlg->l_socket = new ListenSocket;
		if ((*(dlg->l_socket)).Create(dlg->ur_port) == 0) {
			static int code = (*(dlg->l_socket)).GetLastError();
			CString err;
			err.Format("%d", code);
			CString error = "Create Error Code=";
			error += err;
			dlg->MessageBox(error);
			return;
		}
		if ((*(dlg->l_socket)).Listen() == 0) {					//l_socket��������ʵ�ֿ�ʼ����
			static int code = (*(dlg->l_socket)).GetLastError();
			CString err;
			err.Format("%d", code);
			CString error = "Create Error Code=";
			error += err;
			dlg->MessageBox(error);
			return;
		}
		dlg->GetDlgItem(IDC_DISCONNECT)->EnableWindow(TRUE);

		dlg->h_list.AddString(put_time);
		dlg->h_list.UpdateData(FALSE);
	}
	CAsyncSocket::OnConnect(nErrorCode);
}

BOOL s_strcmp(char *str_1, char *str_2) {
	for (int i = 0; i < 8; i++) {
		if (str_1[i] != str_2[i]) return FALSE;
	}
	return TRUE;
}
void ServerSocket::OnReceive(int nErrorCode) {
	CCommunicate_proDlg *dlg = (CCommunicate_proDlg *)AfxGetApp()->GetMainWnd();
	CString put_string;
	dlg->_time = CTime::GetCurrentTime();
	put_string = dlg->_time.Format("%X:");
	Receive(dlg->buff, 200, 0);
	char checkcode[9] = "10001111";

	if (s_strcmp(dlg->buff, checkcode)) {
		dlg->s_socket->Close();
		//dlg->l_socket->Close();
		//dlg->c_socket->Close();
		delete dlg->s_socket;
		//delete dlg->l_socket;
		//delete dlg->c_socket;
		put_string += "�Ͽ�����.";
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