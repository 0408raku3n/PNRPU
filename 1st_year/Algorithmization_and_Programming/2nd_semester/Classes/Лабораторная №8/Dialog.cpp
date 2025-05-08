#include "Dialog.h"

Dialog::Dialog() :Tree()
{
	EndState = 0;
}

Dialog::~Dialog()
{
}

void Dialog::GetEvent(TEvent& event)
{
	string OpInt = "m+-szq";
	string s;
	string param;

	char code;
	cout << ">";
	cin >> s;
	code = s[0];

	if (OpInt.find(code) >= 0)
	{
		event.what = evMessage;
		switch (code)
		{
		case 'm':event.command = cmMake;
		case '+':event.command = cmAdd;
		case '-':event.command = cmDelete;
		case 's':event.command = cmShow;
		case 'z':event.command = cmMidAge;
		case 'q':event.command = cmQuit;
		case '/':event.command = cmGet; break;
		}

		if (s.length() > 1)
		{
			param = s.substr(1, s.length() - 1);
			int k = 0;
			if (param.find(' ')) { k ++ ; }
			if (k == 1)
			{
				string n = param.substr(0, ' ');
				param = param.substr(n.length() + 1, param.length() - 1);
				int a = atoi(param.c_str());
				Person* A = new Person(n, a);
				event.obj = A;
			}
			else 
			{
				string n = param.substr(0, ' ');
				param = param.substr(n.length() + 1, param.length() - 1);
				string as = param.substr(0, ' ');
				int a = atoi(as.c_str());
				param = param.substr(as.length() + 1, param.length() - 1);
				string scores = param.substr(0, ' ');
				int score = atoi(scores.c_str());
				param = param.substr(scores.length() + 1, param.length() - 1);
				string spec = param.substr(0, param.length() - 1);
				Abiturient* B = new Abiturient(n, a, score, spec);
				event.obj = B;
			}
		}
	}
	else event.what = evNothing;
}

int Dialog::Execute()
{
	TEvent event;
	do {
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
	} while (!Valid());
	return EndState;
}

int Dialog::Valid()
{
	if (EndState == 0) return 0;
	else return 1;
}

void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;
}

void Dialog::EndExecute()
{
	EndState = 1;
}

void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake:
			left = right = NULL;
			element = event.obj;
			ClearEvent(event);
			break;
		case cmAdd:
			addElem(event.obj);
			ClearEvent(event);
			break;
		case cmDelete:
			deleteElem();
			
		case cmShow:
			showTree();
			ClearEvent(event);
			break;
		case cmMidAge:
			midAge();
			ClearEvent(event);
			break;
		case cmQuit:
			EndExecute();
			ClearEvent(event);
			break;
		default: Tree::HandleEvent(event);
		}
	}
}