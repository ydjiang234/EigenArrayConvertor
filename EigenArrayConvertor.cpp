#include <iostream>
#include <vector>
#include "Dense"
#include "EigenArrayConvertor.h"

using Eigen::ArrayXd;
using Eigen::ArrayXXd;
using std::vector;

EigenArrayConvertor::EigenArrayConvertor() {}
EigenArrayConvertor::~EigenArrayConvertor() {}

ArrayXd EigenArrayConvertor::OneDimArray(vector<vector<double>> input)
{
    vector<int> curSize = inputSize(input);
    ArrayXd out;
    if (curSize[1]==1)
    {
        out = ArrayXd(curSize[0]);
        for (int i=0; i<curSize[0]; i++)
            out(i) = input[i][0];
    }
    else if (curSize[0]==1)
    {
        out = ArrayXd(curSize[1]);
        for (int j=0; j<curSize[1]; j++)
            out(j) = input[0][j];
    }
    else
    {
        std::cout<<"Input vector is two dimentional.\nPlease use the function TwoDimArray()"<<std::endl;
    }
    return out;
}

ArrayXXd EigenArrayConvertor::TwoDimArray(vector<vector<double>> input)
{
    vector<int> curSize = inputSize(input);
    ArrayXXd out = ArrayXXd(curSize[0], curSize[1]);
    for (int i=0; i<curSize[0]; i++)
    {
        for (int j=0; j<curSize[1]; j++)
        {
            out(i,j) = input[i][j];
        }
    }
    return out;
}

vector<int> EigenArrayConvertor::inputSize(vector<vector<double>> input)
{
    vector<int> out(2);
    out[0] = input.size();
    out[1] = input[0].size();
    return out;
}

vector<vector<double>> EigenArrayConvertor::FromOneDimArray(ArrayXd input)
{
    vector<vector<double>> out;
    for (int i=0; i<input.rows(); i++)
    {
        vector<double> temp = {input(i)};
        out.push_back(temp);
    }
    return out;
}

vector<vector<double>> EigenArrayConvertor::FromTwoDimArray(ArrayXXd input)
{
    vector<vector<double>> out;
    for (int i=0; i<input.rows(); i++)
    {
        vector<double> temp_row;
        for (int j=0; j<input.cols(); j++)
            temp_row.push_back(input(i,j));
        out.push_back(temp_row);
    }
    return out;
}
