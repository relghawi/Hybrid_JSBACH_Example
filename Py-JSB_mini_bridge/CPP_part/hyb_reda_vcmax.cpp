#include "hyb_reda_vcmax.h"

using namespace std;

Hyb_jsb_vcmax::Hyb_jsb_vcmax(char* path){

    model = load_model(path);

}

float Hyb_jsb_vcmax::forward(float apar_acc_tile, float CO2_flux_net, float rad_sw_down, 
float rad_sw_down_pot, float air_temp){

    vector<torch::jit::IValue> input_pipeline;
    torch::Tensor input = torch::ones({5});

    input[0] = apar_acc_tile;
    input[1] = CO2_flux_net;
    input[2] = rad_sw_down;
    input[3] = rad_sw_down_pot;
    input[4] = air_temp;


    input_pipeline.push_back(input);
    at::Tensor output = model.forward(input_pipeline).toTensor();
    float vcmax= output.item<float>();

        return vcmax;

        };



extern "C"{ 
    Hyb_jsb_vcmax *Hyb_jsb_vcmax__new(char* path) {
        return new Hyb_jsb_vcmax(path);
    
    }
    float Hyb_jsb_vcmax__forward(Hyb_jsb_vcmax *This, float apar_acc_tile, float CO2_flux_net, float rad_sw_down, 
    float rad_sw_down_pot, float air_temp){
      return This -> forward(apar_acc_tile,CO2_flux_net,rad_sw_down,rad_sw_down_pot,air_temp);
      
    }
    
    void Hyb_jsb_vcmax__delete(Hyb_jsb_vcmax *This){
      delete This;
    }

    

}
