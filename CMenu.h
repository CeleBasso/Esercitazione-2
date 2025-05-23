/*! @file CMenu.h
	@brief file for menu implementation
	@author Basso/Odino

	Details.
*/ 

#ifndef MENU_H
#define MENU_H
#include <vector>
#include "CPolynomial.h"
#include "CLog.h"
#include "CPower.h"

/// @brief function menu
void ShowMenu();

/// @brief function to print a list
void PrintFunctionList(const vector<Function*>& functions);

/// @brief functions that takes the confirm to do a task
bool ChiediConferma(const string &messaggio);

#endif // MENU_H