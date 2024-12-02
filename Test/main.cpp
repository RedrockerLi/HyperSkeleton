#include <iostream>
#include "dataStructure.hpp"
#include "hyperCalc.hpp"
#include "timer.hpp"

int main(){
    Mat<fp> A(1000,1000);
    Mat<fp> B(1000,1000);
    Mat<fp> C(1000,1000);
    Timer timer("mat mul");
    A.ramdon();
    B.ramdon();
    timer.start();
    C=A*B;
    timer.stop();
    timer.print();
    return 0;
}