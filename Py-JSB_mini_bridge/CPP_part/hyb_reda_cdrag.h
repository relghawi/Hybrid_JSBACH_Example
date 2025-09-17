#ifndef hyb_reda_cdrag
#define hyb_reda_cdrag

#include <torch/script.h>
#include <iostream>
#include <memory>
#include "util.h"

class Hyb_jsb_cdrag
{
        torch::jit::script::Module model;
    public:
        Hyb_jsb_cdrag (char* path);
        float forward(float wind_speed, float apar_acc_tile);
};

extern "C"{ 
    Hyb_jsb_cdrag *Hyb_jsb_cdrag__new(char* path);
    
    float Hyb_jsb_cdrag__forward(Hyb_jsb_cdrag *This, float wind_speed, float apar_acc_tile);
    
    void Hyb_jsb_cdrag__delete(Hyb_jsb_cdrag *This);
    

}
#endif
