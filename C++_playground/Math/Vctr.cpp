#include "Vctr.hpp"
using namespace std;

vctr::vctr(double a = 0, double b = 0, double c = 0){
    x = a;
    y = b;
    z = c;
}

double vctr::get_x(){
    return x;
}

double vctr::get_y(){
    return y;
}

double vctr::get_z(){
    return z;
}

bool vctr::is_paralell(vctr v){
    double xyz[3] = {x, y, z};
    double vctrXYZ[3] = {v.get_x(), v.get_y(), v.get_z()};
    for(int i=0;i<3;i++){
        double a = xyz[i] > vctrXYZ[i] ? xyz[i] : vctrXYZ[i];
        double b = xyz[i] < vctrXYZ[i] ? xyz[i] : vctrXYZ[i];
    }
    return true
}
