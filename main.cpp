#include <iostream>
#include <cmath>
#include <fstream>
#include "Beam.h"

using namespace std;

int main()
{
    int dep, wid, len, p_pos, t_pos;
    double P, w, T, weight, moment, shear, torsion;
    char sup, response;

    do{
        char loadInput;

        cout << "Do you want to load input from file? [Y/N]: ";
        cin >> loadInput;
        cout << endl;

        //loads input from file
        if (toupper(loadInput) == 'Y')
        {
            ifstream inStream;
            inStream.open("inputFile.txt");

            inStream >> dep >> wid >> len >> P >> p_pos >> w >> T >> t_pos >> sup >> weight;

            inStream.close();
        }

        //if input was not loaded from file, prompts user for input
        else if (toupper(loadInput) == 'N')
        {
            //prompt user input
            cout << "Enter Beam Properties" << endl;

            cout << "depth (mm): ";
            cin >> dep;
            cout << endl;

            cout << "width (mm): ";
            cin >> wid;
            cout << endl;

            cout << "length (mm): ";
            cin >> len;
            cout << endl;

            cout << "point load, P (kN): ";
            cin >> P;
            cout << endl;

            cout << "P location (mm): ";
            cin >> p_pos;
            cout << endl;

            cout << "uniformly distributed load, w (kN/m): ";
            cin >> w;
            cout << endl;

            cout << "torsional moment, T (kNm): ";
            cin >> T;
            cout << endl;

            cout << "T location (mm): ";
            cin >> t_pos;
            cout << endl;

            cout << "type of support (simple[s]/fixed[f]): ";
            cin >> sup;
            cout << endl;

            cout << "self-weight (kN/m3): ";
            cin >> weight;
            cout << endl;
        }

        Beam beam;

        //set beam properties
        beam.set_depth(dep);
        beam.set_width(wid);
        beam.set_length(len);
        beam.set_p_load(P);
        beam.set_p_location(p_pos);
        beam.set_w_load(w);
        beam.set_torsion(T);
        beam.set_t_location(t_pos);
        beam.set_supportType(sup);
        beam.set_selfWeight(weight);

        //if input was not loaded from a file (i.e. input not already in file), provides option to save it to file
        if(toupper(loadInput) == 'N')
        {
            char saveInput;

            cout << "Do you want to save the input data to file? [Y/N]: ";
            cin >> saveInput;

            //saves user input to file "inputFile.txt"
            if (toupper(saveInput) == 'Y')
            {
                ofstream outStream;
                outStream.open("inputFile.txt");

                outStream << beam.get_depth() << "\n" << beam.get_width() << "\n" << beam.get_length() << "\n"
                << beam.get_p_load() << "\n" << beam.get_p_location() << "\n" << beam.get_w_load() << "\n"
                << beam.get_torsion() << "\n" << beam.get_t_location() << "\n" << beam.get_supportType() << "\n"
                << beam.get_selfWeight() << endl;

                outStream.close();
            }
        }

        beam.displayResults(len);

        cout << "Do you want to analyse another beam? [Y/N]: ";
        cin >> response;
        cout << endl;

    }while(toupper(response) == 'Y');

    return 0;
}
