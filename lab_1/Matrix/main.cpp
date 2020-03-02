#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;
const int MATRIX_SIZE = 3;

typedef double Matrix[MATRIX_SIZE][MATRIX_SIZE];

void Print(Matrix minorMatrix) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (j < 2) {
                cout << round((minorMatrix[i][j]) * 1000) / 1000 << "    ";
            } else {
                cout << round((minorMatrix[i][j]) * 1000) / 1000 << '\n';
            }
        }
    }
}

void MultMatrixByNumber(Matrix &matrix, double number) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = matrix[i][j] * number;
        }
    }
}

void AdjugateMatrix(Matrix &matrix, Matrix &inverseMatrix) {
    inverseMatrix[0][0] = matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2];
    inverseMatrix[1][0] = (-1) * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]);
    inverseMatrix[2][0] = matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1];

    inverseMatrix[0][1] = (-1) * (matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[0][2]);
    inverseMatrix[1][1] = matrix[0][0] * matrix[2][2] - matrix[2][0] * matrix[0][2];
    inverseMatrix[2][1] = (-1) * (matrix[0][0] * matrix[2][1] - matrix[2][0] * matrix[0][1]);

    inverseMatrix[0][2] = matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2];
    inverseMatrix[1][2] = (-1) * (matrix[0][0] * matrix[1][2] - matrix[1][0] * matrix[0][2]);
    inverseMatrix[2][2] = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
}

double FindingDeterminant(Matrix &matrix) {
    double determinant;
    determinant = matrix[0][0] * matrix[1][1] * matrix[2][2]
                  + matrix[1][0] * matrix[0][2] * matrix[2][1]
                  + matrix[2][0] * matrix[0][1] * matrix[1][2]
                  - matrix[2][0] * matrix[1][1] * matrix[0][2]
                  - matrix[1][0] * matrix[0][1] * matrix[2][2]
                  - matrix[0][0] * matrix[2][1] * matrix[1][2];
    return determinant;
}

bool ReadMatrixFromFile(const string &inputFileName, Matrix &matrix) {
    ifstream inputFile;
    inputFile.open(inputFileName);
    if (!(inputFile.is_open())) {
        cout << "Файла нет!\n";
        return false;
    }
    int check = 0;
    double tmp = 0;
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (inputFile.good()) {
                cout << tmp << endl;
                matrix[i][j] = tmp;
                check = check + 1;
                tmp = 0;
            } else {
                cout << "Встречен неизвестный символ в матрице!\n";
                return false;
            }
        }

    }

    if (check != 9) {
        cout << "В матрице нехватает элементов!\n";
        return false;
    }
    return true;
}

bool InvertMatrix(Matrix &matrix, Matrix &inverseMatrix) {
    double determinant = 0;
    determinant = FindingDeterminant(matrix);
    if (determinant == 0) {
        cout << "Определитель матрицы равен 0. Такая матрица не имеет обратной! \n";
        return false;
    }
    AdjugateMatrix(matrix, inverseMatrix);
    MultMatrixByNumber(inverseMatrix, 1 / determinant);
    return true;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        cout << "Количество параметров введено неправильно!\n"
                "Формат командной строки приложения: invert.exe <matrix file1>";
        return 1;
    }
    Matrix matrix;
    string inputFileName = argv[1];
    if (!(ReadMatrixFromFile(inputFileName, matrix))) {
        return 1;
    }
    Matrix inverseMatrix;
    if (!(InvertMatrix(matrix, inverseMatrix))) {
        return 1;
    }
    Print(inverseMatrix);
    return 0;
}

/*    Matrix matrix;
    if (!(ReadMatrixFromFile(inputFileName, matrix)))
    {
        return 1;
    }
    double determinant = 0;
    determinant = CountDeterminant(matrix);
    if (determinant == 0)
    {
        cout << "Определитель матрицы равен 0. Такая матрица не имеет обратной! \n";
		return 0;
	}
    Matrix minorMatrix;
    CreateInverseMatrix(matrix, minorMatrix, determinant);
    Print(minorMatrix, determinant);*/
