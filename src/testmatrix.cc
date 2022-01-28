#include"MatrixAdd.hh"
//using namespace std;
int main()
{
    //std::cout<<"Cmake successfully"<<std::endl;
    Matrix matrix1,matrix2,matrix;
    std::cin>>matrix1>>matrix2;
    matrix = matrix1 * matrix2;
    std::cout<<matrix<<std::endl;
    std::cin>>matrix1>>matrix2;
    matrix = matrix1 + matrix2;
    std::cout<<matrix<<std::endl;
    //for private branch difference
    return 0;
}
