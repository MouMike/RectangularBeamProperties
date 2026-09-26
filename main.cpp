#include <iostream>
#include "plot.h"
#include "Beam.cpp"

using namespace std;

int main()
{
    int dep, wid, len, p, w;
    double loc, moment, shear, torsion;
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

        cout << "point load, p (kN): ";
        cin >> p;
        cout << endl;

        cout << "p location (mm): ";
        cin >> loc;
        cout << endl;

        cout << "line load, w (kN/m): ";
        cin >> w;
        cout << endl;

        cout << "type of support (simple(s)/fixed(f)): ";
        cin >> sup;
        cout << endl;

        Beam beam;

        //set beam properties
        beam.set_depth(dep);
        beam.set_width(wid);
        beam.set_length(len);
        beam.set_p_load(p);
        beam.set_p_location(loc);
        beam.set_w_load(w);
        beam.set_supportType(sup);

        if(tolower(sup) == "s")
        {
            signalsmith::plot::Plot2D plot;
            auto &line = plot.line();

            for (double x = 0; x < len; x += 0.1)
            {
                line.add(x, beam.calculate_moment(x));
            }

            plot.write("output.svg");
            /////////////
            for(int x = 0; x <= len; x++)
            {
                //calculate moment
                moment =

                //calculate shear


                //calculate torsion


            }///////////////
        }
        else if(tolower(sup) == "f")
        {
            for(double x = 0; x <= len; x += 0.1)
            {
                //calculate moment
                moment =

                //calculate shear


                //calculate torsion


            }


        }

        cout << "Do you want to analyse another beam? [Y/N]: ";
        cin >> response;
        cout << endl;


    }while(toupper(response) == "Y")


    return 0;
}
