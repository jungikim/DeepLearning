#pragma once
#include "common.h"

namespace NeuralNet{

struct Layer{
public:
	virtual ~Layer(){}
	Layer(){}
	Layer(int outputDim0):outputDim(outputDim0){}
	virtual void activateUp() = 0;
	virtual void calGrad(std::shared_ptr<arma::mat> delta_in) = 0;
	virtual void calGrad(std::shared_ptr<arma::mat> delta_in, int t) {}
	virtual void save(std::string filename){}
    virtual void load(std::string filename){}
	int outputDim;
	std::shared_ptr<arma::mat> output;
	std::vector<std::shared_ptr<arma::mat>> outputMem;
	virtual void saveOutputMemory();
};

inline void Layer::saveOutputMemory(){
    outputMem.push_back(output);
}
}
