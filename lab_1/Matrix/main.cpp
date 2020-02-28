#include <iostream>
#include <fstream>
#include <cmath>
#include <optional>
#include <string>

using namespace std;
const int matrixSize = 3;

void FillingMatrix(double (&matrix)[matrixSize][matrixSize],  istream& inputMatrix)
{
    for (int i = 0; i < matrixSize;i++)
    {
	    for (int j = 0; j < matrixSize;j++)
	    {
	        inputMatrix >> matrix[i][j];
	    }
    }
}

double CountDeterminant(double (&matrix)[matrixSize][matrixSize])
{
    double determinant;
    determinant = ((matrix[0][0] * matrix[1][1] * matrix[2][2])
                + (matrix[1][0] * matrix[0][2] * matrix[2][1])
		        + (matrix[2][0] * matrix[0][1] * matrix[1][2]))
		        - ((matrix[2][0] * matrix[1][1] * matrix[0][2])
		        + (matrix[1][0] * matrix[0][1] * matrix[2][2])
		        + (matrix[0][0] * matrix[2][1] * matrix[1][2]));
    return determinant;
}

double FillingMinorMatrix(double (&matrix)[matrixSize][matrixSize], double (&minorMatrix)[matrixSize][matrixSize], const double& determinant)
{
    minorMatrix[0][0] = matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2];
    minorMatrix[0][1] = (-1) * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]);
    minorMatrix[0][2] = matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1];

    minorMatrix[1][0] = (-1) * (matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[0][2]);
    minorMatrix[1][1] = matrix[0][0] * matrix[2][2] - matrix[2][0] * matrix[0][2];
    minorMatrix[1][2] = (-1) * (matrix[0][0] * matrix[2][1] - matrix[2][0] * matrix[0][1]);

    minorMatrix[2][0] = matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2];
    minorMatrix[2][1] = (-1) * (matrix[0][0] * matrix[1][2] - matrix[1][0] * matrix[0][2]);
    minorMatrix[2][2] = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    for (int i = 0; i < matrixSize ; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
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
            cout << minorMatrix[i][j] <<  " ";
        }
        cout << "\n";
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Ошибка ввода! \n";
    }
    string inputFileName = argv[1];
    ifstream inputMatrix;
    inputMatrix.open(inputFileName);
    if (!(inputMatrix.is_open()))
    {
        cout << "NO FILE" << "\n";
        return 1;
    }
    double matrix[matrixSize][matrixSize];
    double determinant = 0;
    FillingMatrix(matrix, inputMatrix);
    determinant = CountDeterminant(matrix);
    if (determinant == 0)
    {
        cout << "Определитель матрицы равен 0. Такая матрица не имеет обратной! \n";
        return 1;
    }
    double minorMatrix[matrixSize][matrixSize];
    FillingMinorMatrix(matrix, minorMatrix, determinant);
    Print(minorMatrix, determinant);

    return 0;
}

