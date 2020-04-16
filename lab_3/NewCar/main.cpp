#include <iostream>
#include <string>
#include "CAutoPilot.h"
#include "CCar.h"

using namespace std;

int main()
{
	cout << "Выберите тип автомобиля: 0 - Обычный авто, 1 - Автопилот" << endl;
	string number;
	getline(cin, number);
	if (number == "0" || number == "1")
	{
		CCar car;
		if(number == "1")
		{
			CAutoPilot(*car);
			return 0;
		}

		return 0;
	}
	return 1;

}
