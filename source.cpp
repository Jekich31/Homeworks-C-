#include "main.h"
#include <ctime>

using namespace std;

template <typename T>
Matrix<T>::Matrix(int r, int c)
{
    rows = r;
    cols = c;

    data = new T * [rows];
    for (int i = 0; i < rows; i++)
        data[i] = new T[cols];
}

template <typename T>
Matrix<T>::~Matrix()
{
    for (int i = 0; i < rows; i++)
        delete[] data[i];
    delete[] data;
}

template <typename T>
void Matrix<T>::input()
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> data[i][j];
        }
}

template <typename T>
void Matrix<T>::randomFill()
{
    srand(time(0));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] = rand() % 10;
}

template <typename T>
void Matrix<T>::print()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << data[i][j] << " ";
        cout << endl;
    }
}

template <typename T>
T Matrix<T>::findMax()
{
    T max = data[0][0];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (data[i][j] > max)
                max = data[i][j];

    return max;
}

template <typename T>
T Matrix<T>::findMin()
{
    T min = data[0][0];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (data[i][j] < min)
                min = data[i][j];

    return min;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& other)
{
    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.data[i][j] = data[i][j] + other.data[i][j];

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& other)
{
    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.data[i][j] = data[i][j] - other.data[i][j];

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& other)
{
    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.data[i][j] = data[i][j] * other.data[i][j];

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator/(const Matrix& other)
{
    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.data[i][j] = data[i][j] / other.data[i][j];

    return result;
}
template class Matrix<int>;
template class Matrix<double>;
