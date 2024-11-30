#ifndef __LAYERS_HPP
#define __LAYERS_HPP
#include "dataStructure.hpp"

class FullyConnectedLayer
{
private:
    uint32_t numIn;
    uint32_t numOut;
    vector<vector<fp>> weight;
    vector<fp>  bias;
public:
    FullyConnectedLayer(uint32_t inNum,uint32_t outNum);
    ~FullyConnectedLayer();
    vector<fp> forward(vector<fp> input);
    vector<fp> backward(vector<fp> topDiff);
    vector<fp> update_param();
};

#endif
