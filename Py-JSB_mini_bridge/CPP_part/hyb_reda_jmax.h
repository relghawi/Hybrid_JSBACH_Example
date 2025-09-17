#ifndef hyb_reda_jmax
#define hyb_reda_jmax

#include <torch/script.h>
#include <iostream>
#include <memory>
#include "util.h"

class Hyb_jsb_jmax
{
        torch::jit::script::Module model;
    public:
        Hyb_jsb_jmax (char* path);
        float forward(float apar_acc_tile, float CO2_flux_net, float rad_sw_down, 
        float rad_sw_down_pot, float air_temp);
};

extern "C"{ 
    Hyb_jsb_jmax *Hyb_jsb_jmax__new(char* path) ;
    
    float Hyb_jsb_jmax__forward(Hyb_jsb_jmax *This, float apar_acc_tile, float CO2_flux_net, float rad_sw_down, 
    float rad_sw_down_pot, float air_temp);
    
    void Hyb_jsb_jmax__delete(Hyb_jsb_jmax *This);
    }

#endif
