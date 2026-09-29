#ifndef BEAM_H
#define BEAM_H

class Beam
{
    public:
        Beam();
        void set_depth(int pdepth);
        void set_width(int pwidth);
        void set_length(int plength);
        void set_p_load(double pp_load);
        void set_p_location(int pp_location);
        void set_w_load(double pw_load);
        void set_torsion(double ptorsion);
        void set_t_location(int pt_location);
        void set_supportType(char psupport);
        void set_selfWeight(double weight);
        int get_depth() const;
        int get_width() const;
        int get_length() const;
        double get_p_load() const;
        int get_p_location() const;
        double get_w_load() const;
        double get_torsion() const;
        int get_t_location() const;
        char get_supportType() const;
        double get_selfWeight() const;
        double calculate_moment(int position) const;
        double calculate_shear(int position) const;
        double calculate_torsion(int position) const;

    private:
        int depth;
        int width;
        int length;
        double p_load;
        int p_location;
        double w_load;
        double torsion;
        int t_location;
        char supportType;
        double selfWeight;

        //double moment;
        //double shear;
        //double torsion;
};

#endif // BEAM_H
