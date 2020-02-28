#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
const int matrixSize = 3;

int checkOpen(ifstream& file)
{
    file.open("matrix.txt");
    if (!(file.is_open()))
    {
	    cout << "NO FILE" << "\n";
	    return 1;
    }
    return 0;
}

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

void CountDeterminant(double (&matrix)[matrixSize][matrixSize], double& determinant)
{
    determinant = ((matrix[0][0] * matrix[1][1] * matrix[2][2])
                + (matrix[1][0] * matrix[0][2] * matrix[2][1])
		        + (matrix[2][0] * matrix[0][1] * matrix[1][2]))
		        - ((matrix[2][0] * matrix[1][1] * matrix[0][2])
		        + (matrix[1][0] * matrix[0][1] * matrix[2][2])
		        + (matrix[0][0] * matrix[2][1] * matrix[1][2]));
}

double FillingMinorMatrix(double (&matrix)[matrixSize][matrixSize], double (&minorMatrix)[matrixSize][matrixSize])
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
}

void OutputResult(double(&minorMatrix)[matrixSize][matrixSize], const double& determinant)
{
    for (int i = 0; i < matrixSize ; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            cout << round((minorMatrix[i][j] / determinant) * 1000) / 1000 << " ";

        }
        cout << "\n";
    }
}

int main()
{
    ifstream inputMatrix;
    checkOpen(inputMatrix);
    double matrix[matrixSize][matrixSize];
    double determinant = 0;
    FillingMatrix(matrix, inputMatrix);
    CountDeterminant(matrix, determinant);
    if (determinant == 0)
    {
        cout << "Определитель матрицы равен 0. Такая матрица не имеет обратной! \n";
        return 1;
    }
    double minorMatrix[matrixSize][matrixSize];
    FillingMinorMatrix(matrix, minorMatrix);
    OutputResult(minorMatrix, determinant);

    return 0;
}

