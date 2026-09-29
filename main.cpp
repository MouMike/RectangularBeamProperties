#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "matplotlibcpp.h"
#include "Beam.h"

using namespace std;

namespace plt = matplotlibcpp;

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

        if (toupper(loadInput) == 'Y')
        {
            ifstream inStream;
            inStream.open("inputFile.txt");

            inStream >> dep >> wid >> len >> P >> p_pos >> w >> T >> t_pos >> sup >> weight;

            inStream.close();
        }

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

        if(toupper(loadInput) == 'N')
        {
            char saveInput;
            cout << "Do you want to save the input data to file? [Y/N]: ";
            cin >> saveInput;

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

        //create vectors to store results
        vector<double> x, m, s, t;

        //store results in vectors
        for (double i = 0; i < len; i += 0.1)
        {
            x.push_back(i);
            m.push_back(beam.calculate_moment(i));
            s.push_back(beam.calculate_shear(i));
            t.push_back(beam.calculate_torsion(i));
        }

        //plot bending moment diagram
        plt::subplot(3,1,1);
        plt::plot(x, m);
        plt::title("Bending Moment Diagram");
        plt::ylabel("Bending Moment (kNm)");
        //plt::show();

        //plot shear force diagram
        plt::subplot(3,1,2);
        plt::plot(x, s);
        plt::title("Shear Force Diagram");
        plt::ylabel("Shear Force (kN)");
        //plt::show();

        //plot torsional moment diagram
        plt::subplot(3,1,3);
        plt::plot(x, t);
        plt::title("Torsional Moment Diagram");
        plt::ylabel("Torsional Moment (kNm)");

        plt::tight_layout(); // Fixes overlapping labels
        plt::show();

        cout << "Do you want to analyse another beam? [Y/N]: ";
        cin >> response;
        cout << endl;

    }while(toupper(response) == 'Y');

    return 0;
}
