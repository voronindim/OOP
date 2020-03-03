#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
const int MATRIX_SIZE = 3;

typedef double Matrix[MATRIX_SIZE][MATRIX_SIZE];

void PrintMatrix(const Matrix matrix)
{
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			if (j < 2)
			{
				cout << setprecision(3) << matrix[i][j] << "\t";
			}
			else
			{
				cout << matrix[i][j] << '\n';
			}
		}
	}
}

void MultMatrixByNumber(Matrix& matrix, double number)
{
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			matrix[i][j] = matrix[i][j] * number;
		}
	}
}

void AdjugateMatrix(const Matrix& matrix, Matrix& adjugateMatrix)
{
	adjugateMatrix[0][0] = matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2];
	adjugateMatrix[1][0] = (-1) * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]);
	adjugateMatrix[2][0] = matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1];

	adjugateMatrix[0][1] = (-1) * (matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[0][2]);
	adjugateMatrix[1][1] = matrix[0][0] * matrix[2][2] - matrix[2][0] * matrix[0][2];
	adjugateMatrix[2][1] = (-1) * (matrix[0][0] * matrix[2][1] - matrix[2][0] * matrix[0][1]);

	adjugateMatrix[0][2] = matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2];
	adjugateMatrix[1][2] = (-1) * (matrix[0][0] * matrix[1][2] - matrix[1][0] * matrix[0][2]);
	adjugateMatrix[2][2] = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
}

double CalculateDeterminant(const Matrix& matrix)
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

bool ReadMatrixFromFile(const string& inputFileName, Matrix& matrix)
{
	ifstream inputFile;
	inputFile.open(inputFileName);
	if (!(inputFile.is_open()))
	{
		cout << "Файла нет!\n";
		return false;
	}
	string row;
	int i = 0;
	while (getline(inputFile, row) && i < MATRIX_SIZE)
	{
		int j = 0;
		double number;
		stringstream ss(row);
		while (ss >> number)
		{
			matrix[i][j] = number;
			j = j + 1;
		}
		if (j != MATRIX_SIZE)
		{
			cout << "Неверное количество элементов в матрице!\n";
			return false;
		}
		i = i + 1;
	}
	return true;
}

bool InvertMatrix(Matrix& matrix, Matrix& inverseMatrix)
{
	double determinant = 0;
	determinant = CalculateDeterminant(matrix);
	if (determinant == 0)
	{
		cout << "Определитель матрицы равен 0. Такая матрица не имеет обратной! \n";
		return true;
	}
	AdjugateMatrix(matrix, inverseMatrix);
	MultMatrixByNumber(inverseMatrix, 1 / determinant);
	return true;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "Количество параметров введено неправильно!\n"
				"Формат командной строки приложения: invert.exe <matrix file1>";
		return 1;
	}
	Matrix matrix;
	string matrixFileName = argv[1];
	if (!(ReadMatrixFromFile(matrixFileName, matrix)))
	{
		return 1;
	}
	Matrix inverseMatrix;
	if (!(InvertMatrix(matrix, inverseMatrix)))
	{
		return 1;
	}
	PrintMatrix(inverseMatrix);
	return 0;
}
