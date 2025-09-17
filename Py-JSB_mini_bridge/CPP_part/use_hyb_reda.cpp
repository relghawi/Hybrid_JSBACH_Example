#include "use_hyb_reda.h"

using namespace std;

int main(int argc, char **argv){
    if (argc != 6){
        cout << "Provide the path to a .pt file: <name_of_program> <path/to/model.pt>" << endl;
        return -1;
    }

    Hyb_jsb_cdrag model_cdrag = Hyb_jsb_cdrag(argv[1]);
    Hyb_jsb_gs model_gs = Hyb_jsb_gs(argv[2]);
    Hyb_jsb_ci model_ci = Hyb_jsb_ci(argv[3]);
    Hyb_jsb_vcmax model_vcmax = Hyb_jsb_vcmax(argv[4]);
    Hyb_jsb_jmax model_jmax = Hyb_jsb_jmax(argv[5]);        
    
    
    for (int i = 0; i<3; i++){
        float wind_speed,apar_acc_tile,CO2_flux_net,rad_sw_down,rad_sw_down_pot,air_temp,P,VPD_JSB,net_radiation;
        float outputs;
        cin >>  wind_speed >> apar_acc_tile >> CO2_flux_net >> rad_sw_down >> rad_sw_down_pot >> air_temp >> P >> VPD_JSB >> net_radiation;
        outputs=model_cdrag.forward(wind_speed,apar_acc_tile);
        cout << "cdrag: " << outputs << endl;

        outputs=model_ci.forward(apar_acc_tile,CO2_flux_net);
        cout << "ci: " << outputs << endl;
        
        outputs=model_gs.forward(rad_sw_down,rad_sw_down_pot,air_temp,P,VPD_JSB,net_radiation);
        cout << "gs: " << outputs << endl;

        outputs=model_jmax.forward(apar_acc_tile,CO2_flux_net,rad_sw_down,rad_sw_down_pot,air_temp);
        cout << "Jmax: " << outputs << endl;

        outputs=model_vcmax.forward(apar_acc_tile,CO2_flux_net,rad_sw_down,rad_sw_down_pot,air_temp);
        cout << "Vcmax: " << outputs << endl;

        
    }

}
