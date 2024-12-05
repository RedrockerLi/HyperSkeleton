#ifndef __TENSOR_HPP
#define __TENSOR_HPP
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <numeric>
#include "dataType.hpp"

template <typename num>
num multiplyVector(const std::vector<num>& vec) {
    return std::accumulate(vec.begin(), vec.end(), static_cast<num>(1), std::multiplies<num>());
}

namespace hyper{
    template <typename num> 
    class Tensor{
    private:
        vector<uint32_t> _shape;
    public:
        vector<num> tensor;
        Tensor(vector<uint32_t> shape) : _shape(shape), tensor(multiplyVector(shape),0) {};
        
    };
}

#endif