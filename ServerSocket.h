#pragma once

// ServerSocket ÃüÁîÄ¿±ê

class ServerSocket : public CAsyncSocket
{
public:
	ServerSocket();
	virtual ~ServerSocket();

	//virtual void OnAccept(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	//int vaild;
};


