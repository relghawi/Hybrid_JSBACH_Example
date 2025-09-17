#include "hyb_reda_gs.h"

using namespace std;

Hyb_jsb_gs::Hyb_jsb_gs(char* path){

    model = load_model(path);

}

float Hyb_jsb_gs::forward(float rad_sw_down, 
float rad_sw_down_pot, float air_temp, float P, float VPD_JSB, float net_radiation){

    vector<torch::jit::IValue> input_pipeline;
    torch::Tensor input = torch::ones({6});

    input[0] = rad_sw_down;
    input[1] = rad_sw_down_pot;
    input[2] = air_temp;
    input[3] = P;
    input[4] = VPD_JSB;
    input[5] = net_radiation;

    input_pipeline.push_back(input);
    at::Tensor output = model.forward(input_pipeline).toTensor();
    float gs=output.item<float>();

        return gs;

        };



extern "C"{ 
    Hyb_jsb_gs *Hyb_jsb_gs__new(char* path) {
        return new Hyb_jsb_gs(path);
    
    }
    float Hyb_jsb_gs__forward(Hyb_jsb_gs *This, float rad_sw_down, 
    float rad_sw_down_pot, float air_temp, float P, float VPD_JSB, float net_radiation){
      return This -> forward(rad_sw_down,rad_sw_down_pot,air_temp,P,VPD_JSB,net_radiation);
      
    }
    
    void Hyb_jsb_gs__delete(Hyb_jsb_gs *This){
      delete This;
    }

    

}
