class Beam
{
    public:
        void set_depth(int pdepth);
        void set_width(int pwidth);
        void set_length(int plength);
        void set_p_load(int pp_load);
        void set_p_location(int pp_location);
        void set_w_load(int pw_load);
        void set_supportType(char psupport);
        int get_depth() const;
        int get_width() const;
        int get_length() const;
        int get_p_load() const;
        int get_p_location() const;
        int get_w_load() const;
        char get_supportType() const;
        double calculate_moment(int position);
        double calculate_shear(int position);
        double calculate_torsion(int position);

    private:
        int depth;
        int width;
        int length;
        int p_load;
        int p_location;
        int w_load;
        char supportType;
        int moment;
        int shear;
        int torsion;


};
