#include "Beam.h"
#include<iostream>
#include<fstream>

using namespace std;

void Beam::set_depth(int pdepth)
[
    depth = pdepth;
]
void Beam::set_width(int pwidth)
[
    width = pwidth;
]
void Beam::set_length(int plength)
[
    length = plength;
]
void Beam::set_p_load(double pp_load)
[
    p_load = pp_load;
]
void Beam::set_p_location(int pp_location)
[
    p_location = pp_location;
]
void Beam::set_w_load(double pw_load)
[
    w_load = pw_load;
]
void Beam::set_supportType(char psupport)
[
    support = psupport;
]
int Beam::get_depth() const
[
    return depth;
]
int Beam::get_width() const
[
    return width;
]
int Beam::get_length() const
[
    return length;
]
double Beam::get_p_load() const
[
    return p_load;
]
int Beam::get_p_location() const
[
    return p_location;
]
double Beam::get_w_load() const
[
    return w_load;
]
char Beam::get_supportType() const
[
    return supportType;
]
double Beam::calculate_moment(int position)
{
    double reaction, moment;

    //for a simply supported beam
    if(tolower(supportType) == "s")
    {
        reaction = - ((p_load * (length - p_location) + w_load
                               * length * length / 2.0) / length);

        if(position < p_location)
        {
            moment  = reaction * position - w_load * position * position / 2.0;
        }

        else
        {
            moment  = reaction * position + p_load * (position - length / 2.0) - w_load * position * position / 2.0;
        }

    }

    //for a fixed beam
    else if(tolower(supportType) == "f")
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
double Beam::calculate_shear(int position)
{
    double reaction, shear;

    //for a simply supported beam
    if(tolower(supportType) == "s")
    {
        reaction = - ((p_load * (length - p_location) + w_load
                               * length * length / 2.0) / length);

        if(position < p_location)
        {
            shear  = -reaction - w_load * position;      //forgot to include w
        }

        else
        {
            moment  = -reaction - p_load - w_load * position;      //forgot to include w
        }

    }

    //for a fixed beam
    else if(tolower(supportType) == "f")
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
}
double Beam::calculate_torsion(int position)
{

}
