#include "Beam.h"
#include <vector>
#include<iostream>
#include<fstream>
#include "matplotlibcpp.h"

using namespace std;

namespace plt = matplotlibcpp;

Beam::Beam(): depth(0), width(0), length(0), p_load(0), p_location(0), w_load(0),
                torsion(0), t_location(0), supportType(' '), selfWeight(0)
{
}
void Beam::set_depth(int pdepth)
{
    depth = pdepth;
}
void Beam::set_width(int pwidth)
{
    width = pwidth;
}
void Beam::set_length(int plength)
{
    length = plength;
}
void Beam::set_p_load(double pp_load)
{
    p_load = pp_load;
}
void Beam::set_p_location(int pp_location)
{
    p_location = pp_location;
}
void Beam::set_torsion(double ptorsion)
{
    torsion = ptorsion;
}
void Beam::set_t_location(int pt_location)
{
    t_location = pt_location;
}
void Beam::set_w_load(double pw_load)
{
    w_load = pw_load;
}
void Beam::set_supportType(char psupport)
{
    supportType = psupport;
}
void Beam::set_selfWeight(double weight)
{
    selfWeight = weight;
}
int Beam::get_depth() const
{
    return depth;
}
int Beam::get_width() const
{
    return width;
}
int Beam::get_length() const
{
    return length;
}
double Beam::get_p_load() const
{
    return p_load;
}
int Beam::get_p_location() const
{
    return p_location;
}
double Beam::get_w_load() const
{
    return w_load;
}
double Beam::get_torsion() const
{
    return torsion;
}
int Beam::get_t_location() const
{
    return t_location;
}
char Beam::get_supportType() const
{
    return supportType;
}
double Beam::get_selfWeight() const
{
    return selfWeight;
}
double Beam::calculate_moment(int position) const
{
    //SANS10100-1, clause 4.2.2
    double reaction, moment, self_weight;

    self_weight = selfWeight * depth * 1e-03 * width * 1e-03;

    //for a simply supported beam
    if(tolower(supportType) == 's')
    {
        reaction = (1.6 * p_load * (length - p_location) * 1e-03 + (1.6 * w_load + 1.2 * self_weight)
                               * length * 1e-03 * length * 1e-03 / 2.0) / (length * 1e-03);

        if(position < p_location)
        {
            moment  = reaction * position * 1e-03 - (1.6 * w_load + 1.2 * self_weight) * position * 1e-03 * position * 1e-03 / 2.0;
        }

        else
        {
            moment  = reaction * position * 1e-03 - 1.6 * p_load * (position - length / 2.0)
            * 1e-03 - (1.6 * w_load + 1.2 * self_weight) * position * 1e-03 * position * 1e-03 / 2.0;
        }

    }

    //for a fixed beam
    else if(tolower(supportType) == 'f')
    {
        reaction = (1.6 * p_load * (length - p_location) * 1e-03 + (1.6 * w_load + 1.2 * self_weight)
                               * length * 1e-03 * length * 1e-03 / 2.0) / (length * 1e-03);

        double Mp1, Mp2, Mw;


        Mw = - (1.6 * w_load + 1.2 * self_weight) * pow(length * 1e-03, 2) / 12;  //free moment due to distributed load
        Mp1 = - 1.6 * p_load * p_location * 1e-03 * pow((length - p_location) * 1e-03, 2) / pow(length * 1e-03, 2);  //free moment at first support due to p_load
        Mp2 = - 1.6 * p_load * pow(p_location * 1e-03, 2) * (length - p_location) * 1e-03 / pow(length * 1e-03, 2);  //free moment at second support due to p_load


        if(position < p_location)
        {
            moment  = Mw + Mp1 + (Mp2 - Mp1) * position * 1e-03 / length * 1e-03 + reaction * position * 1e-03 - (1.6 * w_load + 1.2 * self_weight)
            * pow(position * 1e-03, 2) / 2;
        }

        else
        {
            moment  = Mw + Mp1 + (Mp2 - Mp1) * position * 1e-03 / (length * 1e-03) + reaction * position * 1e-03 - 1.6 * p_load * (position - length / 2.0)
            * 1e-03 - (1.6 * w_load + 1.2 * self_weight) * position * 1e-03 * position * 1e-03 / 2.0;
        }
    }

    return moment;

}
double Beam::calculate_shear(int position) const
{
    //SANS10100-1, clause 4.2.2
    double reaction, shear, self_weight;

    self_weight = selfWeight * depth * 1e-03 * width * 1e-03;

    //for a simply supported beam
    if(tolower(supportType) == 's')
    {
        reaction = (1.6 * p_load * (length - p_location) * 1e-03 + (1.6 * w_load + 1.2 * self_weight)
                               * length * 1e-03 * length * 1e-03 / 2.0) / (length * 1e-03);

        if(position < p_location)
        {
            shear  = reaction - (1.6 * w_load + 1.2 * self_weight) * position * 1e-03;
        }

        else
        {
            shear  = reaction - 1.6 * p_load - (1.6 * w_load + 1.2 * self_weight) * position * 1e-03;
        }

    }

    //for a fixed beam
    else if(tolower(supportType) == 'f')
    {
        //reaction = (1.6 * p_load * (length - p_location) * 1e-03 + (1.6 * w_load + 1.2 * self_weight)
        //                       * length * 1e-03 * length * 1e-03 / 2.0) / (length * 1e-03);

        if(position < p_location)
        {
            shear  = 1.6 * p_load * pow((length - p_location) * 1e-03, 2) * (3 * p_location * 1e-03 + (length - p_location) * 1e-03) / pow(length * 1e-03, 3)
            + (1.6 * w_load + 1.2 * self_weight) * (length * 1e-03 / 2 - position * 1e-03);
        }

        else
        {
            shear  = - 1.6 * p_load * pow((length - p_location) * 1e-03, 2) * (3 * p_location * 1e-03 + (length - p_location) * 1e-03) / pow(length * 1e-03, 3)
            + (1.6 * w_load + 1.2 * self_weight) * (length * 1e-03 / 2 - position * 1e-03);
        }
    }

    return shear;
}
double Beam::calculate_torsion(int position) const
{
    //SANS10100-1, clause 4.2.2
    double temp_torsion;

    //for a simply supported beam
    if(tolower(supportType) == 's')
    {
        if(position < t_location)
        {
            temp_torsion  = -1.6 * torsion / 2;
        }

        else
        {
            temp_torsion  = 1.6 * torsion / 2;
        }
    }

    //for a fixed beam
    else if(tolower(supportType) == 'f')
    {
        /*reaction = - ((p_load * (length - t_location) + w_load
                               * length * length / 2.0) / length);

        if(position < t_location)
        {
            shear  = reaction;
        }

        else
        {
            moment  = reaction - p_load;
        }*/

        temp_torsion = 0;
    }

    return temp_torsion;
}
void Beam::displayResults(int beamLength) const
{
    //create vectors to store results
        vector<double> x, m, s, t;

        //store results in vectors
        for (double i = 0; i < beamLength; i += 1)
        {
            x.push_back(i);
            m.push_back(calculate_moment(i));
            s.push_back(calculate_shear(i));
            t.push_back(calculate_torsion(i));
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
}
