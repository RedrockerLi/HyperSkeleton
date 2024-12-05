#ifndef __MAT_HPP
#define __MAT_HPP
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "dataType.hpp"
namespace hyper{
    template <typename num> 
    class Mat
    {
    private:
        uint32_t _row,_col;
    public:
        vector<num> mat;
        Mat(uint32_t row, uint32_t col) : _row(row), _col(col), mat(row * col,0) {};
        uint32_t index(uint32_t row, uint32_t col) const{
            return row*_col+col;
        }
        void ramdon(void);
        Mat<num>& T(void);
        Mat operator*(const Mat& other);
    };
}

using hyper::Mat;

template <typename num>
void Mat<num>::ramdon(){
    std::srand(static_cast<unsigned>(std::time(0)));
    for(uint32_t row=0;row<_row;row++){
        for(uint32_t col=0;col<_col;col++){
            mat[index(row,col)]=std::rand() % 100;
        }
    }
}

template <typename num>
void swap(num& a, num& b) {
    num temp = a;
    a = b;
    b = temp;
}

template <typename num>
Mat<num>& Mat<num>::T(){
    if(_row==_col){
        uint32_t i,j;
        if(_row*_col>100){
            #pragma omp parallel for shared(mat) private(i,j)
            for(i=0;i<_row;i++){
                for(j=i+1;j<_col;j++){
                    swap(mat[i*_col+j],mat[j*_col+i]);
                }
            }
        }else{
            for(i=0;i<_row;i++){
                for(j=i+1;j<_col;j++){
                    swap(mat[i*_col+j],mat[j*_col+i]);
                }
            }
        }
    }else{
        Mat<num> result(_col, _row);
        for (uint32_t i = 0; i < _row; i++) {
            for (uint32_t j = 0; j < _col; j++) {
                result.mat[index(j,i)]=mat[index(i, j)];
            }
        }
        swap(_row,_col);
        memcpy(&(this->mat),result.mat,_row*_col);
    }
    return *this;
}

template <typename num>
Mat<num> Mat<num>::operator*(const Mat& other){
    if(_col!=other._row){
        std::cout<<"Matrix dimensions must agree for multiplication.\n";
        exit(-1);
    }
    Mat<num> ans(_row,other._col);
    uint32_t i,j,k;
    if(_row*_col*other._col>1000){
        #pragma omp parallel for shared(ans) private(i,j,k)
        for(i=0;i<_row;i++){
            for(k=0;k<_col;k++){
                for(j=0;j<other._col;j++){
                    ans.mat[index(i,j)]+=mat[index(i,k)]*other.mat[index(k,j)];
                }
            }
        }
    }else{
        for(i=0;i<_row;i++){
            for(k=0;k<_col;k++){
                for(j=0;j<other._col;j++){
                    ans.mat[index(i,j)]+=mat[index(i,k)]*other.mat[index(k,j)];
                }
            }
        }
    }
    return ans;
}

#endif