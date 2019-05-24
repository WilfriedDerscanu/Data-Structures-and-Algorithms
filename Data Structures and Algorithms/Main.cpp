#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#include <iostream>
#include "LList.hpp"

int main()
{
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	//////////////////////////Test Scope////////////////////////////////
	{
		LList<int> lst;
		lst.PushFirst(5);
		lst.PushFirst(10);
		lst.PushLast(5);
		while (!lst.isEmpty())
		{
			std::cout << lst.PopLast() << " ";
		}
	}
	//////////////////////////////////////////////////////////////////
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}