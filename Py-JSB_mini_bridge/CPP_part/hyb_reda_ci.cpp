#include "hyb_reda_ci.h"

using namespace std;

Hyb_jsb_ci::Hyb_jsb_ci(char* path){

    model = load_model(path);

}

float Hyb_jsb_ci::forward(float apar_acc_tile, float CO2_flux_net){

    vector<torch::jit::IValue> input_pipeline;
    torch::Tensor input = torch::ones({2});

    input[0] = apar_acc_tile;
    input[1] = CO2_flux_net;


    input_pipeline.push_back(input);
    at::Tensor output = model.forward(input_pipeline).toTensor();
    float ci= output.item<float>();


        return ci;

        };



extern "C"{ 
    Hyb_jsb_ci *Hyb_jsb_ci__new(char* path) {
        return new Hyb_jsb_ci(path);
    
    }
    float Hyb_jsb_ci__forward(Hyb_jsb_ci *This, float apar_acc_tile, float CO2_flux_net){
      return This -> forward(apar_acc_tile,CO2_flux_net);
      
    }
    
    void Hyb_jsb_ci__delete(Hyb_jsb_ci *This){
      delete This;
    }

    

}
