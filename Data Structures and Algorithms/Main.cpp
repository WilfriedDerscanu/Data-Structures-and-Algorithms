#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#include <iostream>
#include "List.h"

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
		List<int> lst;
		lst.push_back(2);
		lst.push_back(5);
		lst.push_back(6);
		{
			List<int> l2 = std::move(lst);
			
			std::cout << l2 << " ";
		}
		std::cout << lst << " " << std::endl;
	}
	//////////////////////////////////////////////////////////////////
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}