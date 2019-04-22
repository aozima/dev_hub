#ifndef __PLC_PROXY_H__
#define __PLC_PROXY_H__

#include <string>


////////////////////////// Protocol /////////////////////////
class Protocol
{

};

class FinsProtocol : public Protocol
{

};

Protocol* GetProtocol(std::string name);

/////////////////////////// PclContex /////////////////////////

class MachineContex
{
public:
	MachineContex(){}
	virtual ~MachineContex(){}

	void SetConnectionContex(void *contex){m_connectionContex = contex;}
protected:
	void* m_connectionContex;

	std::string m_ip;
	unsigned int m_port;

	Protocol* m_protocol;
	std::string m_protocolType;
};


class PlcContex : public MachineContex
{
public:
	PlcContex(std::string ,std::string ,unsigned int);
	virtual ~PlcContex(){}


private:
	
};


//////////////////////////// PlcProxy //////////////////////////
class PlcProxy
{
public:
	~PlcProxy();
	int PlcConnect(MachineContex*);

	static PlcProxy& Instance();

	void PlcWriteWorlds(MachineContex*,char* data,unsigned int long);
	unsigned int PlcReadWorlds(MachineContex*,std::string plcAddr,char* recvBuf);

private:
	PlcProxy();
	
};





#endif