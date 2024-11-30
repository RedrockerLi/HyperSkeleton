#include <cstdlib>
#include "layers.hpp"

FullyConnectedLayer :: FullyConnectedLayer(uint32_t inNum, uint32_t outNum) 
    : numIn(inNum), numOut(outNum), weight(outNum, vector<fp>(inNum)), bias(outNum) {
    for (uint32_t i = 0; i < numOut; i++) {
        for (uint32_t j = 0; j < numIn; j++) {
            weight[i][j] = static_cast<fp>(rand()) / static_cast<fp>(RAND_MAX);
        }
        bias[i]=static_cast<fp>(rand()) / static_cast<fp>(RAND_MAX);
    }
}

vector<fp> FullyConnectedLayer ::forward(vector<fp> input){
    vector<fp> output(numOut, 0);
    for (uint32_t i = 0; i < numOut; i++) {
        for (uint32_t j = 0; j < numIn; j++) {
            output[i] += weight[i][j] * input[j];
        }
        output[i] += bias[i];
    }
    return output;
}