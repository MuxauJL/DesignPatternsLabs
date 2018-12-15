#pragma once

class ACommand 
{
public:
	ACommand();
	virtual ~ACommand();
	virtual void execute();
	virtual ACommand* clone() = 0;
protected:
	virtual void doExecute() = 0;
};

