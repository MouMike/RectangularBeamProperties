class Beam
{
    public:
        void set_depth(int pdepth);
        void set_width(int pwidth);
        void set_length(int plength);
        void set_p_load(double pp_load);
        void set_p_location(int pp_location);
        void set_w_load(double pw_load);
        void set_supportType(char psupport);
        int get_depth() const;
        int get_width() const;
        int get_length() const;
        double get_p_load() const;
        int get_p_location() const;
        double get_w_load() const;
        char get_supportType() const;
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
        char supportType;
        //double moment;
        //double shear;
        //double torsion;


};
