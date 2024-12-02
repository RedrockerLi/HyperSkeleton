#ifndef __HYPER_CALC_HPP
#define __HYPER_CALC_HPP
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "dataStructure.hpp"
namespace hyper{
    template <typename num> 
    class Mat
    {
    private:
        uint32_t _row,_col;
        vector<num> _mat;
    public:
        Mat(uint32_t row, uint32_t col);
        num at(uint32_t row, uint32_t col) const;
        void set(uint32_t row, uint32_t col,num value);
        void ramdon(void);
        Mat operator*(const Mat& other);
    };

}

using hyper::Mat;
template <typename num>
Mat<num>::Mat(uint32_t row, uint32_t col) : _row(row), _col(col), _mat(row * col,0) {};

template <typename num>
num Mat<num>::at(uint32_t row, uint32_t col) const{
    return _mat[row*_col+col];
}

template <typename num>
void Mat<num>::set(uint32_t row, uint32_t col,num value){
    _mat[row*_col+col]=value;
}

template <typename num>
void Mat<num>::ramdon(){
    std::srand(static_cast<unsigned>(std::time(0)));
    for(uint32_t row=0;row<_row;row++){
        for(uint32_t col=0;col<_col;col++){
            _mat[row*_col+col]=std::rand() % 100;
        }
    }
}

template <typename num>
Mat<num> Mat<num>::operator*(const Mat& other){
    if(_col!=other._row){
        std::cout<<"Matrix dimensions must agree for multiplication.\n";
        exit(-1);
    }
    Mat<num> ans(_row,other._col);
    uint32_t i,j,k;
    #pragma omp parallel for shared(ans) private(i,j,k)
    for(i=0;i<_row;i++){
        for(k=0;k<_col;k++){
            for(j=0;j<other._col;j++){
                ans.set(i,j,ans.at(i,j)+at(i,k)*other.at(k,j));
            }
        }
    }
    return ans;
}

#endif