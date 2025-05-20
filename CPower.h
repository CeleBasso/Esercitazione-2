/*! @file CPower.h
	@brief A class for power functions 
	@author Basso/Odino

	Details.
*/ 
#ifndef CPOWER_H
#define CPOWER_H

#include <iostream>
#include <cmath>
#include <cstring>
#include "CFunction.h"

using namespace std;

class Power : public Function  
{
    private:

    double k_coeff;
    double e_coeff;

    /// @name CONSTRUCTOR e DESTRUCTOR
    /// @{
    public:
    Power();
    Power(double k_coeff, double e_coeff);
    Power(const Power& p);
    ~Power();
    /// @}
    
    /// @name GETTER E SETTER
    /// @{
    double GetValue(double in) const;
    void SetPower(double k, double e);
    ///}@

    ///@name OPERATOR
    /// @{
    Power& operator=(const Power& p);
	bool operator==(const Power& p);
    ///@}

    /// @name DEBUG
    /// @{
    void Dump();
    /// @}
};

#endif



