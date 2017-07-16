#pragma once

/* Definition of Socket for client used. */

class ClientSocket : public CAsyncSocket
{
public:
	ClientSocket();
	virtual ~ClientSocket();

	virtual void OnReceive(int nErrorCode);
};


