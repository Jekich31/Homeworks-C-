#include <iostream>

template <typename T>
class Matrix
{
private:
    int rows, cols;
    T** data;

public:
    Matrix(int r = 2, int c = 2);
    ~Matrix();

    void input();
    void randomFill();
    void print();

    T findMax();
    T findMin();

    Matrix operator+(const Matrix& other);
    Matrix operator-(const Matrix& other);
    Matrix operator*(const Matrix& other);
    Matrix operator/(const Matrix& other);
};