#include <iostream>
#include "CShapeProcessor.h"

using namespace std;

int main()
{
    string inputString;
	CShapeProcessor processor;
	while (getline(cin, inputString))
	{
		if (!processor.HandleCommand(inputString))
        {
		    cout << "Неправильный ввод!" << endl;
        }
	}
	return 0;
}
