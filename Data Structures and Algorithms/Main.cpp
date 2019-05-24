#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#include <iostream>
#include "Stack.hpp"

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
		Stack<int> q;
		q.Push(1);
		q.Push(2);
		q.Push(3);
		q.Push(5);
		while (!q.isEmpty())
			std::cout << q.Pop() << " ";

	}
	//////////////////////////////////////////////////////////////////
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}