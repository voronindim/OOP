#include <iostream>
#include <string>

using namespace std;

bool SafeMult(int a, int b, int& result)
{
	if (a == 0 || b == 0)
	{
		result = 0;
		return true;
	}
	if (a > 0)
	{
		if (b > 0)
		{
			if (a <= (INT_MAX / b))
			{
				result = a * b;
				return true;
			}
		}
		else
		{
			if (b >= (INT_MIN / a))
			{
				result = a * b;
				return true;
			}
		}
	}
	else
	{
		if (b > 0)
		{
			if (a >= (INT_MIN / b))
			{
				result = a * b;
				return true;
			}
		}
		else
		{
			if (b >= (INT_MAX / a))
			{
				result = a * b;
				return true;
			}
		}
	}
	cout << "Выход за границы INT!\n";
	return false;
}

bool SafeAdd(int a, int b, int& result)
{
	if (b > 0)
	{
		if (INT_MAX - b >= a)
		{
			result = a + b;
			return true;
		}
	}
	else
	{
		if (INT_MIN - b <= a)
		{
			result = a + b;
			return true;
		}
	}
	return false;
}

int CharToInt(char ch, int radix, bool& wasError)
{
	char maxValue;
	int number = 0;
	if (radix > 10)
	{
		maxValue = char(radix - 11 + 'A');
	}
	else
	{
		maxValue = char(radix - 1 + '0');
	}
	if (ch >= '0' && ch <= '9' && ch <= maxValue)
	{
		number = ch - '0';
	}
	else
	{
		char upperLetter = toupper(ch);
		if (upperLetter >= 'A' && upperLetter <= maxValue)
		{
			number = upperLetter - 'A' + 10;
		}
		else
		{
			wasError = true;
			cout << "Invalid symbol " << ch << '\n';
		}
	}
	return number;
}

int StringToInt(const string& str, int radix, bool& wasError)
{
	const int maxRadix = ('Z' - 'A') + 11;
	int i = 0;
	int number = 0;
	int n = 0;
	bool checkMinus = false;
	if (radix < 2 || radix > maxRadix)
	{
		wasError = true;
		cout << "Ошибка системы счисления!" << '\n';
	}
	else
	{
		if (str[0] == '-')
		{
			checkMinus = true;
			i = i + 1;
		}
		while (str[i] != '\0' && !wasError)
		{
			number = CharToInt(str[i], radix, wasError);
			if (checkMinus)
			{
				number = -number;
			}
            if (!SafeMult(n, radix, n) || !SafeAdd(n, number, n))
            {
                wasError = true;
                cout << "Ошибка переполнения!" << '\n';
            }
			i = i + 1;
		}
	}
	return n;
}

string IntToString(int n, int radix, bool& wasError)
{
	const int maxRadix = ('Z' - 'A') + 11;
	string str;
	if (radix < 2 || radix > maxRadix)
	{
		wasError = true;
		cout << "Ошибка системы счисления!" << '\n';
	}
	else
	{
		int x;
		bool checkMinus = false;
		if (n < 0)
		{
			checkMinus = true;
		}
		while (n != 0)
		{
			x = abs(n % radix);
			if (x >= 0 && x <= 9)
			{
				str += to_string(x);
			}
			else
			{
				str += char(x + 'A' - 10);
			}
			n = n / radix;
		}
		if (str.empty())
		{
			str = "0";
		}
		reverse(str.begin(), str.end());
		if (checkMinus)
		{
			str.insert(0, "-");
		}
	}
	return str;
}

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		cout << "Ошибка входных данных, нехватка аргументов!\n";
		return 1;
	}
	int state1 = atoi(argv[1]);
	int state2 = atoi(argv[2]);
	string str = argv[3];
	bool wasError = false;
	int number = StringToInt(str, state1, wasError);
	string str_number;
	if (!wasError)
	{
		str_number = IntToString(number, state2, wasError);
		if (!wasError)
		{
			cout << str_number << '\n';
		}
	}
	if (wasError)
	{
		return 1;
	}
	return 0;
}
