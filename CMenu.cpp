/*!
  @file CMenu.cpp
  @brief Implementation function menu
  @author Basso/Odino

	Details.
 */

#include "CMenu.h"

#include <iostream>
#include <vector>

using namespace std;

/// @brief Print function list
void PrintFunctionList(const vector<Function*>& functions) 
{
    if (functions.empty()) 
    {
        cout << "La lista delle funzioni è vuota.\n";
        return;
    }

    for (size_t i = 0; i < functions.size(); ++i) 
    {
        cout << "ID: " << i << " -> ";
        functions[i]->Dump();
    }
}

/// @brief Show the menu
void ShowMenu() {
    vector<Function*> functions;
    int choice = -1;

    while (choice != 0) {
        cout << "\n--- MENU PRINCIPALE ---\n";
        cout << "0 --- Esci dal menu'\n";
        cout << "1 --- Visualizza la lista delle funzioni\n";
        cout << "2 --- Inserisci una funzione\n";
        cout << "3 --- Elimina una funzione\n";
        cout << "4 --- Elimina tutte le funzioni\n";
        cout << "5 --- Seleziona una funzione\n";
        cout << "Scelta: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                PrintFunctionList(functions);
                break;
            }

            case 2: {
                int tipo;
                cout << "Scegli tipo di funzione da inserire:\n";
                cout << "1 --- Polinomiale\n";
                cout << "2 --- Logaritmica\n";
                cout << "3 --- Potenza\n";
                cout << "Tipo: ";
                cin >> tipo;

                Function* f = nullptr;

                if (tipo == 1) 
                {
                    int grado;
                    cout << "Inserisci il grado del polinomio: ";
                    cin >> grado;
                    double* coeff = new double[grado + 1];
                    for (int i = 0; i <= grado; ++i) 
                    {
                        cout << "Coefficiente x^" << i << ": ";
                        cin >> coeff[i];
                    }
                    f = new Polynomial(coeff, grado + 1);
                    delete[] coeff;
                }
                else if (tipo == 2) 
                {
                    double k, b;
                    cout << "Inserisci coefficiente k: ";
                    cin >> k;
                    cout << "Inserisci coefficiente b: ";
                    cin >> b;
                    f = new Log(k, b);
                }
                else if (tipo == 3) 
                {
                    double k, e;
                    cout << "Inserisci coefficiente k: ";
                    cin >> k;
                    cout << "Inserisci esponente e: ";
                    cin >> e;
                    f = new Power(k, e);
                }
                else 
                {
                    cout << "Tipo non valido.\n";
                    break;
                }

                cout << "Funzione da inserire:\n";
                f->Dump();
                functions.push_back(f);
                cout << "Funzione inserita\n";

                break;
            }

        }
    }
}