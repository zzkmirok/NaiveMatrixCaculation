#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#ifndef MATRIX_ADDING_HH
#define MATRIX_ADDING_HH
//这里可以加一个template
bool IsNumber(std::string& s);

class Matrix{
    private:
        unsigned m;
        unsigned n;
        std::vector<double> elements;
    public:
        Matrix();
        Matrix(unsigned m_, unsigned n_, std::vector<double> v);
        Matrix(unsigned m_, unsigned n_);
        unsigned Nrow();
        unsigned Ncolumn();
        std::vector<double> Elements();
        friend std::istream& operator>>(std::istream& input, Matrix& matrix);
        friend std::ostream& operator<<(std::ostream& output, Matrix& matrix);       
        friend Matrix operator+(Matrix matrix1, Matrix matrix2);
        friend Matrix operator*(Matrix matrix_l,Matrix matrix_r);

};
#endif 