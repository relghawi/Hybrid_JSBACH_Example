#ifndef hyb_reda_gs
#define hyb_reda_gs

#include <torch/script.h>
#include <iostream>
#include <memory>
#include "util.h"

class Hyb_jsb_gs
{
        torch::jit::script::Module model;
    public:
        Hyb_jsb_gs (char* path);
        float forward(float rad_sw_down, 
        float rad_sw_down_pot, float air_temp,float P,float VPD_JSB,float net_radiation);
};

extern "C"{ 
    Hyb_jsb_gs *Hyb_jsb_gs__new(char* path);
    
    float Hyb_jsb_gs__forward(Hyb_jsb_gs *This, float rad_sw_down, 
    float rad_sw_down_pot, float air_temp, float P, float VPD_JSB, float net_radiation);
    
    void Hyb_jsb_gs__delete(Hyb_jsb_gs *This);
    }


#endif
