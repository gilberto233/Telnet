#pragma once

// ListenSocket ����Ŀ��

class ListenSocket : public CAsyncSocket
{
public:
	ListenSocket();
	virtual ~ListenSocket();

	virtual void OnAccept(int nErrorCode);
};


