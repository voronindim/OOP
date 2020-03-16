#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

const int MAX_SIZE = 100;
const char FILL_START = 'O';
const char WALL = '#';
const char EMPTY_CHAR = ' ';
const char POINT_CHAR = '.';

typedef vector<string> Vector;

struct Coord
{
    int x;
    int y;
};

void Print(const Vector &field, ostream& output)
{
    for (const auto & i : field)
    {
        output << i << endl;
    }
}

void OpenOutputFileAndPrintResult(const Vector &field, const string &outputFileName)
{
    fstream outputFile;
    outputFile.open(outputFileName, std::ios::out );
    if (!outputFile.is_open())
    {
        cout << '\n';
        cout << "Output file not found!\n";
        cout << "Результат будет выдан в командной строке!\n";
        Print(field, cout);
    }
    else
    {
        Print(field, outputFile);
    }
}

bool ReadFieldFromFile(const string &inputFileName, Vector &field)
{
	ifstream fileInput;
	fileInput.open(inputFileName);
	if (!fileInput.is_open())
	{
		cout << "Input File not Found!\n";
		return false;
	}
	string str;
	while (getline(fileInput, str))
	{
		if (str.size() > MAX_SIZE || field.size() > MAX_SIZE - 1)
		{
			cout << "Превышен лимит области. Рабочее поле 100*100\n";
			return false;
		}
		for (char ch : str)
		{
			if (ch != FILL_START && ch != WALL && ch != EMPTY_CHAR)
			{
				cout << "Встречен неизвестный символ!\n";
				return false;
			}
		  }
		field.push_back(str);
	}
	return true;
}

void SetThePoints(Vector &resultVector, Coord &position)
{
    int i = position.x;
    int j = position.y;
    if (i >= resultVector.size() && i < MAX_SIZE && i > -1)
    {
        for (int k = resultVector.size(); k < MAX_SIZE ; k++)
        {
            string row(100, ' ');
            resultVector.push_back(row);
        }
    }
    if (j >= resultVector[i].size())
    {
        for (int k = resultVector[i].size(); k < MAX_SIZE ; k++)
        {
            resultVector[i].push_back(' ');
        }
    }
    if (i < MAX_SIZE && j < MAX_SIZE && i >= 0 && j >= 0 &&
    	(resultVector[i][j] == FILL_START || resultVector[i][j] == EMPTY_CHAR))
    {
        resultVector[i][j] = POINT_CHAR;
        Coord nextFill{};

        nextFill.x = i - 1;
        nextFill.y = j;
        SetThePoints(resultVector,nextFill);

        nextFill.x = i;
        nextFill.y = j - 1;
        SetThePoints(resultVector,nextFill);

        nextFill.x = i + 1;
        nextFill.y = j;
        SetThePoints(resultVector,nextFill);

        nextFill.x = i;
        nextFill.y = j + 1;
        SetThePoints(resultVector,nextFill);
    }
}

void FillingFieldWithDots(const Vector &field, Vector &resultField)
{
    list<Coord> initialCoord;
    for (int i = 0; i < field.size(); i++)
    {
        for (int j = 0; j < field[i].size(); j++)
        {
            if (field[i][j] == FILL_START)
            {
                Coord fillStart{};
                fillStart.x = i;
                fillStart.y = j;
                initialCoord.push_back(fillStart);
            }
        }
        resultField.push_back(field[i]);
    }

    for(Coord startFill : initialCoord)
    {
        SetThePoints(resultField, startFill);
    }
    for(Coord startFill : initialCoord)
    {
        resultField[startFill.x][startFill.y] = 'O';
    }
}


int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "Invalid arguments\n";
        cout << "Arguments should be: fill.exe <input file> <output file>\n";
        return 1;
    }
    string inputFileName = argv[1];
    string outputFileName = argv[2];
    Vector field;
    if (!ReadFieldFromFile(inputFileName, field))
    {
        return 1;
    }
    Vector resultField;
    FillingFieldWithDots(field, resultField);
    OpenOutputFileAndPrintResult(resultField, outputFileName);
    return 0;
}
