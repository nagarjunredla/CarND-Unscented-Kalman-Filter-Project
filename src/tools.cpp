#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
	/**
	TODO:
	* Calculate the RMSE here.
	*/
	int n_estimations = estimations.size();
	VectorXd rmse(4);
	rmse << 0., 0., 0., 0.;

	if(n_estimations == 0 || n_estimations != ground_truth.size()){
	    std::cerr << "Error" << std::endl;
	    return rmse;
	}

	//accumulate squared residuals
	for(int i=0; i < n_estimations; ++i){
		VectorXd residual = estimations[i] - ground_truth[i];

		//coefficient-wise multiplication
		residual = residual.array()*residual.array();
		rmse += residual;
	}

	//calculate the mean
	rmse = rmse / (double) n_estimations;

	//calculate the squared root
	rmse = rmse.array().sqrt();


	//return the result
	return rmse;
}