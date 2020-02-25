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
    cout << "Выход за рамки INT!\n";
    return false;
}

bool SafeAdd(int a, int b, int& result)
{
    if(b > 0)
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

int StringToInt(const string& str, int radix, bool& wasError)
{
    int i = 0;
    int number = 0;
    int n = 0;
    char maxValue;
    if (radix > 10)
    {
        maxValue = char(radix - 11 + 'A');

    }
    else
    {
        maxValue = char(radix - 1 + '0');
    }
    char maxNumber = radix - 11 + 'A';
    bool checkMinus = false;
    if (radix < 2 || radix > ('Z' - 'A') + 10)
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
        while(str[i] != '\0' && !wasError)
        {
            if(str[i] >= '0' && str[i] <= '9' && str[i] <= maxValue)
            {
                number = str[i] - '0';
            }
            else
            {
                char upperLetter = toupper(str[i]);
                if (upperLetter >= 'A' && upperLetter <= maxNumber)
                {
                    number = upperLetter - 'A' + 10;
                }
                else
                {
                    wasError = true;
                    cout << "Invalid symbol " << str[i] << '\n';
                }
            }
            if (checkMinus)
            {
                if (!SafeMult(n, radix, n) || !SafeAdd(n, -number, n))
                {
                    wasError = true;
                    cout << "Ошибка переполнения!" << '\n';
                }
            }
            else
            {
                if (!SafeMult(n, radix, n) || !SafeAdd(n, number, n))
                {
                    wasError = true;
                    cout << "Ошибка переполнения!" << '\n';
                }
            }

            i = i + 1;
        }
    }
    return n;
}

string IntToString(int n, int radix, bool &wasError)
{
    string str;
    if (radix < 2 || radix > ('Z' - 'A') + 10)
    {
        wasError = true;
        cout << "Ошибка системы счисления!" << '\n';
    }
    else
    {
        int  x;
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
                str += char (x + 'A' - 10);
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
            str.insert(0,"-");
        }
    }
    return str;
}


int main(int argc, char* argv[])
{
    int state1 = atoi(argv[1]);
    int state2 = atoi(argv[2]);
    bool wasError = false;
    int number = StringToInt(argv[3], state1, wasError);
    string str_number;
    if (!wasError)
    {
       str_number =  IntToString(number, state2, wasError);
       if (!wasError)
       {
           cout << str_number << '\n';
       }
    }

    return 0;
}
