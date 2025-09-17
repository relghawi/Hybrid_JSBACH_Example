#ifndef hyb_reda_vcmax
#define hyb_reda_vcmax

#include <torch/script.h>
#include <iostream>
#include <memory>
#include "util.h"

class Hyb_jsb_vcmax
{
        torch::jit::script::Module model;
    public:
        Hyb_jsb_vcmax (char* path);
        float forward(float apar_acc_tile, float CO2_flux_net, float rad_sw_down, 
        float rad_sw_down_pot, float air_temp);
};


extern "C"{ 
    Hyb_jsb_vcmax *Hyb_jsb_vcmax__new(char* path);
    
    float Hyb_jsb_vcmax__forward(Hyb_jsb_vcmax *This, float apar_acc_tile, float CO2_flux_net, float rad_sw_down, 
    float rad_sw_down_pot, float air_temp);
      
    
    void Hyb_jsb_vcmax__delete(Hyb_jsb_vcmax *This);
    }


#endif
