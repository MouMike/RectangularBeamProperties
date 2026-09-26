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
double Beam::calculate_moment(double position)
{

}
double Beam::calculate_shear(double position)
{

}
double Beam::calculate_torsion(double position)
{

}
