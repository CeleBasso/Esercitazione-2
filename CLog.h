/*! @file CLog.h
	@brief A class for log functions 
	@author Basso/Odino

	Details.
*/ 

#ifndef CLOG_H
#define CLOG_H

#include <iostream>
#include <cmath>
#include <cstring>
#include "CFunction.h"

using namespace std;

class Log : public Function  
{
    private:

    double k_coeff;
    double b_coeff;

    /// @name CONSTRUCTOR e DESTRUCTOR
    /// @{
    public:
    Log();
    Log(double k_coeff, double b_coeff);
    Log(const Log& l);
    ~Log();
    /// @}
    
    /// @name GETTER E SETTER
    /// @{
    double GetValue(double in) const;
    void SetLog(double k, double b);
    ///}@

    ///@name OPERATOR
    /// @{
    Log& operator=(const Log& l);
	bool operator==(const Log& l);
    ///@}

    /// @name DEBUG
    /// @{
    void Dump();
    /// @}
};

#endif

