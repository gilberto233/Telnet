#pragma once

// ListenSocket ÃüÁîÄ¿±ê

class ListenSocket : public CAsyncSocket
{
public:
	ListenSocket();
	virtual ~ListenSocket();

	virtual void OnAccept(int nErrorCode);
};


