
// Communicate_proDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Communicate_pro.h"
#include "Communicate_proDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CCommunicate_proDlg �Ի���



CCommunicate_proDlg::CCommunicate_proDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_COMMUNICATE_PRO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCommunicate_proDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_INPUT, input_ed);
	DDX_Control(pDX, IDC_HISTORY, h_list);
	DDX_Control(pDX, IDC_PORT, port_ed);
}

BEGIN_MESSAGE_MAP(CCommunicate_proDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, &CCommunicate_proDlg::OnBnClickedConnect)
	ON_BN_CLICKED(IDC_DISCONNECT, &CCommunicate_proDlg::OnBnClickedDisconnect)
	ON_BN_CLICKED(IDC_SEND, &CCommunicate_proDlg::OnBnClickedSend)
END_MESSAGE_MAP()


// CCommunicate_proDlg ��Ϣ�������

BOOL CCommunicate_proDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	GetDlgItem(IDC_DISCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_SEND)->EnableWindow(FALSE);
	GetDlgItem(IDC_INPUT)->EnableWindow(FALSE);
	GetDlgItem(IDC_PORT_S)->SetWindowText((LPCTSTR)"5000");
	GetDlgItem(IDC_PORT_R)->SetWindowText((LPCTSTR)"4999");
	GetDlgItem(IDC_IPADDRESS)->SetWindowText((LPCTSTR)"127.0.0.1");
	c_or_l = -1;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCommunicate_proDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCommunicate_proDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCommunicate_proDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCommunicate_proDlg::OnBnClickedConnect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//c_or_l = 1;
	GetDlgItem(IDC_CONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_PORT_S)->EnableWindow(FALSE);
	GetDlgItem(IDC_PORT_R)->EnableWindow(FALSE);
	GetDlgItem(IDC_IPADDRESS)->EnableWindow(FALSE);

	CString s_ip, s_port_s,s_port_r;
	GetDlgItem(IDC_IPADDRESS)->GetWindowText(IP_Address);
	s_ip = IP_Address.GetBuffer(IP_Address.GetLength());
	GetDlgItem(IDC_PORT_S)->GetWindowText(s_port_s);
	GetDlgItem(IDC_PORT_R)->GetWindowText(s_port_r);
	us_port = atoi(s_port_s.GetBuffer()),ur_port=atoi(s_port_r.GetBuffer());

	s_socket = new ServerSocket;
	//c_socket = new ClientSocket;
	//l_socket = new ListenSocket;
	if ((*s_socket).Create(us_port) == 0) {                          //s_socket��������ʵ����������
		static int code = (*s_socket).GetLastError();
		CString err;
		err.Format("%d", code);
		CString error = "Create Error Code=";
		error += err;
		MessageBox(error);
		return;
	}
	s_socket->Connect(s_ip, ur_port);

/*
	if ((*l_socket).Create(ur_port) == 0) {
		static int code = (*l_socket).GetLastError();
		CString err;
		err.Format("%d", code);
		CString error = "Create Error Code=";
		error += err;
		MessageBox(error);
		return;
	}
	if ((*l_socket).Listen() == 0) {					//l_socket��������ʵ�ֿ�ʼ����
		static int code = (*l_socket).GetLastError();
		CString err;
		err.Format("%d", code);
		CString error = "Create Error Code=";
		error += err;
		MessageBox(error);
		return;
	}
	
	//UpdateData(FALSE);
	GetDlgItem(IDC_DISCONNECT)->EnableWindow(TRUE);
*/
}


void CCommunicate_proDlg::OnBnClickedDisconnect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (c_or_l==1) {
		s_socket->Send("10001111", 200, 0);
		s_socket->Close();
		delete s_socket;
	}
	else if(c_or_l==0){
		c_socket->Send("10001111", 200, 0);
		c_socket->Close();
		l_socket->Close();
		delete c_socket;
		delete l_socket;
	}
	else if (c_or_l == -1) {
		l_socket->Close();
		delete l_socket;
	}
	
	CString put_string;
	_time=CTime::GetCurrentTime();
	put_string = _time.Format("%X:");
	put_string += "�Ͽ�����.";
	h_list.AddString(put_string);
	UpdateData(FALSE);
	GetDlgItem(IDC_CONNECT)->EnableWindow(TRUE);
	GetDlgItem(IDC_PORT_S)->EnableWindow(TRUE);
	GetDlgItem(IDC_PORT_R)->EnableWindow(TRUE);
	GetDlgItem(IDC_IPADDRESS)->EnableWindow(TRUE);
	GetDlgItem(IDC_INPUT)->EnableWindow(FALSE);
	GetDlgItem(IDC_DISCONNECT)->EnableWindow(FALSE);
	GetDlgItem( IDC_SEND)->EnableWindow(FALSE);
	return;
}


void CCommunicate_proDlg::OnBnClickedSend()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString res;
	input_ed.GetWindowText(buff, 200);
	if (c_or_l) {
		s_socket->Send(buff, 200, 0);
	}
	else c_socket->Send(buff, 200, 0);
	res = buff;
	res = "From:" + res;
	CString put_string;
	_time=CTime::GetCurrentTime();
	put_string = _time.Format("%X:");
	res = put_string + res;
	h_list.AddString(res);
	UpdateData(FALSE);
	input_ed.SetWindowText("");
	return;
}
