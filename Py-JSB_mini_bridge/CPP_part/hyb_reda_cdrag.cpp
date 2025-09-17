#include "hyb_reda_cdrag.h"

using namespace std;

Hyb_jsb_cdrag::Hyb_jsb_cdrag(char* path){

    model = load_model(path);

}

float Hyb_jsb_cdrag::forward(float wind_speed, float apar_acc_tile){

    vector<torch::jit::IValue> input_pipeline;
    torch::Tensor input = torch::ones({2});

    input[0] = wind_speed;
    input[1] = apar_acc_tile;


    input_pipeline.push_back(input);
    at::Tensor output = model.forward(input_pipeline).toTensor();
    float cdrag=output.item<float>();

        return cdrag;

        };



extern "C"{ 
    Hyb_jsb_cdrag *Hyb_jsb_cdrag__new(char* path) {
        return new Hyb_jsb_cdrag(path);
    
    }
    float Hyb_jsb_cdrag__forward(Hyb_jsb_cdrag *This, float wind_speed, float apar_acc_tile){
      return This -> forward(wind_speed,apar_acc_tile);
      
    }
    
    void Hyb_jsb_cdrag__delete(Hyb_jsb_cdrag *This){
      delete This;
    }

    

}
