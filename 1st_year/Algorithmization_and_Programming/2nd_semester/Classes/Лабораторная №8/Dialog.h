#pragma once
#include "./Tree.h"
#include "./Event.h"
class Dialog:
	public Tree
{
public:
	Dialog();
	virtual ~Dialog();

	virtual void GetEvent(TEvent& event);
	virtual int Execute();
	virtual void HandleEvent(TEvent& event);
	virtual void ClearEvent(TEvent& event);

	int Valid();
	void EndExecute();
protected:
	int EndState;

};

