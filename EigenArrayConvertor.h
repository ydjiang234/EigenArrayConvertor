#ifndef EigenArrayConvertor_h
#define EigenArrayConvertor_h

#include <iostream>
#include <vector>
#include "Dense"

using Eigen::ArrayXd;
using Eigen::ArrayXXd;
using std::vector;

class EigenArrayConvertor
{
public:
    EigenArrayConvertor();
    ~EigenArrayConvertor();
    ArrayXd OneDimArray(vector<vector<double>> input);
    ArrayXXd TwoDimArray(vector<vector<double>> input);
    vector<vector<double>> FromOneDimArray(ArrayXd input);
    vector<vector<double>> FromTwoDimArray(ArrayXXd input);
private:
    vector<int> inputSize(vector<vector<double>> input);
};

#endif
