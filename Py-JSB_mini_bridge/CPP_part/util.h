#ifndef util_reda
#define util_reda

#include <torch/script.h>
#include <iostream>

torch::jit::script::Module load_model(const char* path);

#endif
