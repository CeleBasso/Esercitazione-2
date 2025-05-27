/*!
 @file CMenu.cpp
 @brief implementation a list of Function
 @author Basso/Odino

  Details.
 */

#include "CMenu.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>

using namespace std;

/// @brief choice confirmation function
/// @param messaggio string of confirm
/// @return true if confirmed
bool ChiediConferma(const string &messaggio)
{
    string risposta;
    while (true)
    {
        cout << messaggio << " (s/n): ";
        getline(cin >> ws, risposta); // legge la riga ignorando spazi iniziali
        transform(risposta.begin(), risposta.end(), risposta.begin(),
                  [](unsigned char c)
                  { return static_cast<char>(tolower(c)); });

        if (risposta == "s" || risposta == "si" || risposta == "si'")
            return true;
        if (risposta == "n" || risposta == "no")
            return false;

        cout << "Risposta non valida. Digita 's' per si' o 'n' per no.\n";
    }
}

/// @brief Print of list of function 
/// @param functions the various functions
void PrintFunctionList(const vector<Function *> &functions)
{
    if (functions.empty())
    {
        cout << "La lista delle funzioni e' vuota.\n";
        return;
    }

    for (size_t i = 0; i < functions.size(); ++i)
    {
        cout << "ID: " << i << " -> ";
        functions[i]->Dump();
    }
}

/// @brief Menu print
void ShowMenu()
{
    vector<Function *> functions;
    int choice = -1;

    while (choice != 0)
    {
        cout << "\n--- MENU PRINCIPALE ---\n";
        cout << "0 --- Esci dal menu'\n";
        cout << "1 --- Visualizza la lista delle funzioni\n";
        cout << "2 --- Inserisci una funzione\n";
        cout << "3 --- Elimina una funzione\n";
        cout << "4 --- Elimina tutte le funzioni\n";
        cout << "5 --- Seleziona una funzione\n";
        cout << "Scelta: ";

        string input;
        getline(cin >> ws, input);

        try
        {
            choice = stoi(input);
        }
        catch (exception &e)
        {
            cout << "Input non valido. Inserisci un numero." << endl;
            continue; 
        }

        switch (choice)
        {
        /// @brief print of funcion case 1
        case 1:
            PrintFunctionList(functions);
            break;

        /// @brief insert a function case 2
        case 2:
        {
            int tipo;
            cout << "Scegli tipo di funzione da inserire:\n";
            cout << "1 --- Polinomiale\n";
            cout << "2 --- Logaritmica\n";
            cout << "3 --- Potenza\n";
            cout << "Tipo: ";
            cin >> tipo;

            Function *f = nullptr;

            if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Input non valido\n";
                    break;
                }
                
            /// @brief Insert a polynomial function
            if (tipo == 1)
            {
                int grado;
                cout << "Inserisci il grado del polinomio: ";
                cin >> grado;

                if (grado <0)
                {
                    cout << "Coefficiente minore di 0, non valido\n";
                    break;
                }

                double *coeff = new double[grado + 1];
                for (int i = 0; i <= grado; ++i)
                {
                    cout << "Coefficiente x^" << i << ": ";
                    cin >> coeff[i];
                }

                f = new Polynomial(coeff, grado + 1);
                delete[] coeff;
            }
            /// @brief Insert a logarithmic function
            else if (tipo == 2)
            {
                double k, b;
                cout << "Inserisci coefficiente k: ";
                cin >> k;
                cout << "Inserisci coefficiente b: ";
                cin >> b;

                if (cin.fail() || b <= 0)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Input non valido\n";
                    break;
                }

                f = new Log(k, b);
            }
            /// @brief Insert a power function
            else if (tipo == 3)
            {
                double k, e;
                cout << "Inserisci coefficiente k: ";
                cin >> k;
                cout << "Inserisci esponente e: ";
                cin >> e;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Input non valido\n";
                    break;
                }

                f = new Power(k, e);
            }
            else
            {
                cout << "Tipo non valido.\n";
                break;
            }

            cout << "\nFunzione creata:\n";
            f->Dump();

            /// @brief ask for confirmation of entry
            if (ChiediConferma("Confermi l'inserimento della funzione?"))
            {
                functions.push_back(f);
                cout << "Funzione inserita.\n";
            }
            else
            {
                delete f;
                cout << "Inserimento annullato.\n";
            }
            break;
        }

        /// @brief delete a function
        case 3:
        {
            PrintFunctionList(functions);
            if (functions.empty())
                break;

            size_t id;
            cout << "Inserisci l'ID della funzione da eliminare: ";
            cin >> id;

            if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Input non valido\n";
                    break;
                }

            if (id >= functions.size())
            {
                cout << "ID non valido.\n";
                break;
            }

            cout << "\nFunzione selezionata:\n";
            functions[id]->Dump();

            /// @brief ask for deletion confirmation
            if (ChiediConferma("Confermi l'eliminazione della funzione?"))
            {
                delete functions[id];
                functions.erase(functions.begin() +(int)id);
                cout << "Funzione eliminata.\n";
            }
            else
            {
                cout << "Eliminazione annullata.\n";
            }
            break;
        }

        /// @brief delete all function
        case 4:
        {
            for (Function *f : functions)
                delete f;
            functions.clear();
            cout << "Tutte le funzioni sono state eliminate.\n";
            break;
        }
        /// @brief select a function and solvable with a value
        case 5:
        {
            PrintFunctionList(functions);
            if (functions.empty())
                break;

            size_t id;
            cout << "Inserisci l'ID della funzione da selezionare: ";
            cin >> id;

             if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input non valido. Inserisci un numero.\n";
                continue;
            }

            if (id >= functions.size())
            {
                cout << "ID non valido.\n";
                break;
            }

            Function *f = functions[id];
            f->Dump();

            double x;
            cout << "Inserisci il valore di x: ";
            cin >> x;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input non valido. Inserisci un numero.\n";
                break;
            }
            else
            {
                 cout << "Valore della funzione per x = " << x
                 << ": " << f->GetValue(x) << "\n";
            break;
            }

        }

        case 0:
            cout << "Uscita...\n";
            break;

        default:
            cout << "Scelta non valida.\n";
        }
    }

    /// @brief final cleaning
    for (Function *f : functions)
        delete f;
}