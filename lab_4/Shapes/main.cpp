#include <iostream>
#include "CShapeProcessor.h"


using namespace std;

int main()
{

	cout << "Формат ввода: " << endl;

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
