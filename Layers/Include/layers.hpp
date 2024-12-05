#ifndef __LAYERS_HPP
#define __LAYERS_HPP
#include "dataType.hpp"

class FullyConnectedLayer
{
private:
    uint32_t _numIn;
    uint32_t _numOut;
    vector<vector<fp>> weight;
    vector<fp>  bias;
public:
    FullyConnectedLayer(uint32_t numIn,uint32_t numOut);
    ~FullyConnectedLayer();
    vector<fp> forward(vector<fp> input);
    vector<fp> backward(vector<fp> topDiff);
    vector<fp> update_param();
};

#endif
