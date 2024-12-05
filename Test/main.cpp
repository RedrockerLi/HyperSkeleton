#include <iostream>
#include "dataType.hpp"
#include "mat.hpp"
#include "timer.hpp"

#define M 100

int main(){
    Mat<fp> A(M,M);
    Mat<fp> B(M,M);
    Mat<fp> C(M,M);
    Timer timer("mat mul");
    A.ramdon();
    B.ramdon();
    timer.start();
    C=A*B;
    timer.stop();
    timer.print();
    return 0;
}