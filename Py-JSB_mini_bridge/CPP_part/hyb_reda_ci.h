#ifndef hyb_reda_ci
#define hyb_reda_ci

#include <torch/script.h>
#include <iostream>
#include <memory>
#include "util.h"

class Hyb_jsb_ci
{
        torch::jit::script::Module model;
    public:
        Hyb_jsb_ci (char* path);
        float forward(float apar_acc_tile, float CO2_flux_net);
};

extern "C"{ 
    Hyb_jsb_ci *Hyb_jsb_ci__new(char* path);
    
    float Hyb_jsb_ci__forward(Hyb_jsb_ci *This, float apar_acc_tile, float CO2_flux_net);
      
    void Hyb_jsb_ci__delete(Hyb_jsb_ci *This);
    }


#endif
