#include "MatrixAdd.hh"
bool IsNumber(std::string& s){
    //bool flag;
    for(auto c:s)
    {
        if((isdigit(c)==false)&&(c!='.')){
            return false;
        }
        
    }
    return true;
}
Matrix::Matrix()
{
    m = 0;
    n = 0;
}
Matrix::Matrix(unsigned m_, unsigned n_):m(m_),n(n_)
{}

Matrix::Matrix(unsigned m_, unsigned n_, std::vector<double> v):m(m_),n(n_)
{
    elements = v;
}

unsigned Matrix::Nrow(){return m;}
unsigned Matrix::Ncolumn(){return n;}
std::vector<double> Matrix::Elements(){return elements;}

std::istream& operator>>(std::istream& input, Matrix& matrix)
{
    
    matrix.elements.clear();
    std::string s;
    if(!std::getline(input,s))
    {
        std::cout<<"input nothing"<<std::endl;
    }
    else
    {
        s.erase(s.find('['),1);
        s.erase(s.find(']'),1);
        std::stringstream allstream(s);
    
        unsigned i=0;
        unsigned j=0;
        matrix.m=0;
        matrix.n=0;
        for(std::string row;std::getline(allstream,row,';');)
        {
        
            if(i==1)
            {
                matrix.n=j;
                j=0;
            }
            else if(i>1)
            {
                if(j!=matrix.n)
                {
                    std::cout<<"wrong input j"<<std::endl;//可以加错误代码
                }
                    j=0;
            }
            else{}
            ++i;
            std::stringstream rowstream(row);
            //std::string cell;
            //while(std::getline(rowstream,cell,' '))//||std::getline(rowstream,cell,' '))
            //这里也可以用while写
            if(row.find(',')!=std::string::npos)
            {
                for(std::string cell;std::getline(rowstream,cell,',');)
                {
                
                    matrix.elements.push_back(stod(cell));
                    //std::cout<<stod(cell)<<",";
                    ++j;
                } 
            }
            else{
                for(std::string cell; std::getline(rowstream,cell,' ');)
                {
                    if(cell.size()!=0)
                    {
                        matrix.elements.push_back(stod(cell));
                        //std::cout<<stod(cell)<<" ";
                        ++j;
                    }
                }
            }
       
            //std::cout<<std::endl;
        }
        matrix.m=i;

    }
    return input;
    

}

std::ostream& operator<<(std::ostream& output, Matrix& matrix)
{
    for(unsigned i=0;i<matrix.m;++i){
        for(unsigned j=0;j<matrix.n;++j)
        {
            output<<matrix.elements[i*matrix.n+j]<<" ";
        }
        output<<std::endl;
    }
    return output;
}     


Matrix operator+(Matrix matrix1, Matrix matrix2)
{
    if(matrix1.m!=matrix2.m||matrix1.n!=matrix2.n){
        std::cout<<"Error Matrix add"<<std::endl;//错误有待处理
        return Matrix();
    }
    else
    {
        for(unsigned i=0; i<matrix1.m*matrix1.n;++i)
        {
            matrix1.elements[i] +=matrix2.elements[i];
        }
        return Matrix(matrix1);
    }
}

Matrix operator*(Matrix matrix_l,Matrix matrix_r)
{
    if(matrix_l.n!=matrix_r.m)
    {
        std::cout<<"Error Matrix Mul"<<std::endl;//错误有待处理
        //return Matrix();
    }
    else{
        Matrix result(matrix_l.m,matrix_r.n);
        for(unsigned i=0;i<result.m;++i)
        {
            for(unsigned j=0;j<result.n;++j)
            {
                result.elements.push_back(0.0);
                for(unsigned k=0;k<matrix_r.m;++k)
                    result.elements[i*result.n+j]+=matrix_l.elements[i*matrix_l.n+k]*matrix_r.elements[k*matrix_r.n+j];
            }
        }
        return result;
    }
    return Matrix();
}
