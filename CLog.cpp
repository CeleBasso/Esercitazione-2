/*! @file CLog.cpp
	@brief Implementation of Log class 
	@author Basso/Odino

	Details.
*/ 
#include "CLog.h"

///@brief default constractor
Log::Log()
{
    k_coeff=0;
    b_coeff=-1;
}
/// @brief deconstractor
Log::~Log()
{}
/// @brief parameter constractor
/// @param k_coeff 
/// @param b_coeff 
Log::Log(double k, double b)
{
    k_coeff=0;
    b_coeff=-1;
    SetLog(k,b);
}
/// @brief copy constructor
/// @param l 
Log::Log(const Log& l)
{
    b_coeff=l.b_coeff;
    k_coeff=l.k_coeff;
}

/// @brief Set the log function
/// @param k coefficient
/// @param b base
void Log::SetLog(double k, double b) 
{
    if (isnan(k) || isnan(b) || b<=1) 
        {
            cout<<("The parameters are not valid")<<endl;  
        } 
    else 
        {
            k_coeff = k;
            b_coeff = b;
        }
}
/// @brief Get the log function
/// @param in the input
/// @return the value of the log
double Log::GetValue(double in) const
{
    if (isnan(k_coeff ) || isnan(b_coeff) || b_coeff<=1)
    {
        cout<<"Invalid parameter "<<endl;
        return(-1);
    }
    if(isnan(in) || in<=0)
    {
        cout<<"Invalid parameter"<<endl;
        return (-1);
    }
        return k_coeff*log(in)/log(b_coeff); 
    

}

/// @brief Operator =
/// @param l function log
/// @return funcion log
Log& Log::operator=(const Log& l)
{
    if(this != &l)
    {
        k_coeff=l.k_coeff;
        b_coeff=l.b_coeff;
    }
    return *this;
}

/// @brief Operator ==
/// @param l fuction power
/// @return equal or not equal
bool Log::operator==(const Log& l)
{
    if(l.k_coeff==k_coeff && l.b_coeff==b_coeff)
    {
        return true;
    }
    else
    {
        return false;
    }
}
///@brief Debug
void Log::Dump()
{
    cout<<k_coeff<<"log_"<<b_coeff<<"x"<<endl;
}