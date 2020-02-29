#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;
const int matrixSize = 3;

bool CreateMatrix(const string& inputFileName, double (&matrix)[matrixSize][matrixSize])
{
	ifstream inputFile;
	inputFile.open(inputFileName);
	if (!(inputFile.is_open()))
	{
		cout << "Файла нет!\n";
		return false;
	}
	string str;
	string number;
	int i = 0;
	int check = 0;
	while (!inputFile.eof() && i < matrixSize)
	{
		getline(inputFile, str);
		int k = 0;
		for (int j = 0; j <= str.length(); j++)
		{
			if (str[j] >= '0' && str[j] <= '9')
			{
				number = number + str[j];
			}
			else
			{
				if (str[j] == ' ' || str[j] == '\0' || str[j] == '\t')
				{
					if (str[j - 1] == '.' || str[j - 1] == '-')
					{
						cout << "Матрица имеет ошибку!\n";
						return false;
					}
					if (!(number.empty()))
					{
						matrix[i][k] = atof(number.c_str());
						check = check + 1;
						number = "";
						if (k + 1 < matrixSize)
						{
							k = k + 1;
						}
						else
						{
							cout << "Матрица должна быть 3*3!\n";
							return false;
						}
					}
				}
				else
				{
					if (str[j] == '-')
					{
						if (number.empty())
						{
							number = number + str[j];
						}
						else
						{
							cout << "Минус может стоять только вначале числа! Проверьте матрицу!\n";
							return false;
						}
					}
					else
					{
						if (str[j] == '.')
						{
							if (!(number.empty()))
							{
								number = number + str[j];
							}
							else
							{
								cout << "Встречена отдельно стоящая точка! Проверьте матрицу!\n";
								return false;
							}
						}
						else
						{
							cout << "Матрица должна содержать только числа!\n";
							return false;
						}
					}
				}
			}
		}
		i = i + 1;
	}
	if (check != 9)
	{
		cout << "В матрице нехватает элементов!\n";
		return false;
	}
	return true;
}

double CountDeterminant(double (&matrix)[matrixSize][matrixSize])
{
	double determinant;
	determinant = matrix[0][0] * matrix[1][1] * matrix[2][2]
		+ matrix[1][0] * matrix[0][2] * matrix[2][1]
		+ matrix[2][0] * matrix[0][1] * matrix[1][2]
		- matrix[2][0] * matrix[1][1] * matrix[0][2]
		- matrix[1][0] * matrix[0][1] * matrix[2][2]
		- matrix[0][0] * matrix[2][1] * matrix[1][2];
	return determinant;
}

void CreateInverseMatrix(double (&matrix)[matrixSize][matrixSize], double (&minorMatrix)[matrixSize][matrixSize], const double& determinant)
{
    minorMatrix[0][0] = matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2];
    minorMatrix[1][0] = (-1) * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]);
    minorMatrix[2][0] = matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1];

    minorMatrix[0][1] = (-1) * (matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[0][2]);
    minorMatrix[1][1] = matrix[0][0] * matrix[2][2] - matrix[2][0] * matrix[0][2];
    minorMatrix[2][1] = (-1) * (matrix[0][0] * matrix[2][1] - matrix[2][0] * matrix[0][1]);

    minorMatrix[0][2] = matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2];
    minorMatrix[1][2] = (-1) * (matrix[0][0] * matrix[1][2] - matrix[1][0] * matrix[0][2]);
    minorMatrix[2][2] = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];

    for (int i = 0; i < matrixSize ; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            if (minorMatrix[i][j] == 0)
            {
                minorMatrix[i][j] = abs(minorMatrix[i][j]);
            }
            else
                minorMatrix[i][j] = round((minorMatrix[i][j] / determinant) * 1000) / 1000;
        }
    }
}

void Print(double(&minorMatrix)[matrixSize][matrixSize], const double& determinant)
{
    for (int i = 0; i < matrixSize ; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            cout << minorMatrix[i][j] <<  "   ";
        }
        cout << "\n";
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Количество параметров введено неправильно!\n";
        return 1;
    }
    string inputFileName = argv[1];
    double matrix[matrixSize][matrixSize];
    if (!(CreateMatrix(inputFileName, matrix)))
    {
        return 1;
    }
    double determinant = 0;
    determinant = CountDeterminant(matrix);
    if (determinant == 0)
    {
        cout << "Определитель матрицы равен 0. Такая матрица не имеет обратной! \n";
        return 1;
    }
    double minorMatrix[matrixSize][matrixSize];
    CreateInverseMatrix(matrix, minorMatrix, determinant);
    Print(minorMatrix, determinant);

    return 0;
}

