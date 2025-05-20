/*! @file CPower.cpp
	@brief Implementation of Power class 
	@author Basso/Odino

	Details.
*/ 


#include "CPower.h"

/// @brief  default Constructor
Power::Power() : Function() 
    {
        k_coeff=0;
        e_coeff=0;
    }
/// @brief parametric constructor 
/// @param k coefficient
///@param e exponent
Power::Power(double k, double e) : Function()
{
    k_coeff=0;
    e_coeff=0;
    SetPower(k,e);
}

/// @brief copy constructor
/// @param p 
Power::Power(const Power& p)
{
    k_coeff=p.k_coeff;
    e_coeff=p.e_coeff;
}

/// @brief Destructor
Power::~Power()
{
    
}

/// @brief Set the power function
/// @param k coefficient
///@param e exponent
void Power::SetPower(double k, double e) 
{
    if (isnan(k) || isnan(e)) 
        {
            cout<<("Invalid parameter")<<endl;  
        } 
    else if (k <= 0 && (e <= -1 || e >= 1))
        {
            cout << ("Invalid parameter") << endl;
        }
    else 
        {
            k_coeff = k;
            e_coeff = e;
        }
}
/// @brief Get the power function
/// @param in the input
/// @return the value of the power
double Power::GetValue(double in) const
{
    return pow(in, e_coeff)*k_coeff;
}

/// @brief Operator =
/// @param p function power
/// @return funcion power
Power& Power::operator=(const Power& p)
{
    if(this != &p)
    {
        k_coeff=p.k_coeff;
        e_coeff=p.e_coeff;
    }
    return *this;
}

/// @brief Operator ==
/// @param p fuction power
/// @return equal or not equal
bool Power::operator==(const Power& p)
{
    if(p.k_coeff==k_coeff && p.e_coeff==e_coeff)
    {
        return true;
    }
    else
    {
        return false;
    }
}
///@brief Debug
void Power::Dump()
{
    cout<<k_coeff<<"x^"<<e_coeff<<endl;
}
