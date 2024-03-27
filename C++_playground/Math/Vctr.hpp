class vctr{
    protected:
        double x;
        double y;
        double z;
    public:
        vctr(double a, double b, double c);
        double get_x();
        double get_y();
        double get_z();
        bool is_paralell(vctr v);
        bool is_perpendicular(vctr v);
};