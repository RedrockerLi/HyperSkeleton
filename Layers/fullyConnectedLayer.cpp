#include <cstdlib>
#include "layers.hpp"

FullyConnectedLayer :: FullyConnectedLayer(uint32_t numIn, uint32_t numOut) 
    : _numIn(numIn), _numOut(numOut), weight(numOut, vector<fp>(numIn)), bias(numOut) {
    for (uint32_t i = 0; i < numOut; i++) {
        for (uint32_t j = 0; j < numIn; j++) {
            weight[i][j] = static_cast<fp>(rand()) / static_cast<fp>(RAND_MAX);
        }
        bias[i]=static_cast<fp>(rand()) / static_cast<fp>(RAND_MAX);
    }
}

vector<fp> FullyConnectedLayer ::forward(vector<fp> input){
    vector<fp> output(_numOut, 0);
    for (uint32_t i = 0; i < _numOut; i++) {
        for (uint32_t j = 0; j < _numIn; j++) {
            output[i] += weight[i][j] * input[j];
        }
        output[i] += bias[i];
    }
    return output;
}