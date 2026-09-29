#include "Beam.h"
#include<iostream>
#include<fstream>

using namespace std;

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
        /*reaction = - ((p_load * (length - p_location) + w_load
                               * length * length / 2.0) / length);

        if(position < p_location)
        {
            moment  = reaction * position - w_load * position * position / 2.0;
        }

        else
        {
            moment  = reaction * position + p_load * (position - length / 2.0) - w_load * position * position / 2.0;
        }*/
    }

    return moment;

}
double Beam::calculate_shear(int position) const
{
    double reaction, shear, self_weight;

    self_weight = selfWeight * depth * 1e-03 * width * 1e-03;

    //for a simply supported beam
    if(tolower(supportType) == 's')
    {
        reaction = (1.6 * p_load * (length - p_location) * 1e-03 + (1.6 * w_load + 1.2 * self_weight)
                               * length * 1e-03 * length * 1e-03 / 2.0) / (length * 1e-03);

        if(position < p_location)
        {
            shear  = -reaction + (1.6 * w_load + 1.2 * self_weight) * position * 1e-03;
        }

        else
        {
            shear  = -reaction + 1.6 * p_load + (1.6 * w_load + 1.2 * self_weight) * position * 1e-03;
        }

    }

    //for a fixed beam
    else if(tolower(supportType) == 'f')
    {
        /*reaction = - ((p_load * (length - p_location) + w_load
                               * length * length / 2.0) / length);

        if(position < p_location)
        {
            shear  = reaction;
        }

        else
        {
            moment  = reaction - p_load;
        }*/
    }

    return shear;
}
double Beam::calculate_torsion(int position) const
{
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
    }

    return temp_torsion;
}
