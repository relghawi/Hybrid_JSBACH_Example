#include "util.h"

using namespace std;


torch::jit::script::Module load_model(const char* path) {
    torch::jit::script::Module model;
    try{
         model = torch::jit::load(path);
    }
    catch (const c10::Error& e) {
        cerr << "error loading the module\n";
    }

    return model;
};
