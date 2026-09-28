#include <iostream>
#include <vector>
#include <cmath>
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

        cout << "line load, w (kN/m): ";
        cin >> w;
        cout << endl;

        cout << "torsional moment, T (kNm): ";
        cin >> T;
        cout << endl;

        cout << "T location (mm): ";
        cin >> t_pos;
        cout << endl;

        cout << "type of support (simple(s)/fixed(f)): ";
        cin >> sup;
        cout << endl;

        cout << "self-weight (kN/m3): ";
        cin >> weight;
        cout << endl;

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

        //plot moment
        plt::plot(x, m);
        plt::title("Bending Moment Diagram");
        plt::show();

        //plot shear
        plt::plot(x, s);
        plt::title("Shear Force Diagram");
        plt::show();

        //plot torsion
        plt::plot(x, t);
        plt::title("Torsional Moment Diagram");
        plt::show();

        cout << "Do you want to analyse another beam? [Y/N]: ";
        cin >> response;
        cout << endl;

    }while(toupper(response) == 'Y');

    return 0;
}
