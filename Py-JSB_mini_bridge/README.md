# Pytorch-JSBACH

## LIBTORCH Library

wget https://download.pytorch.org/libtorch/nightly/cpu/libtorch-shared-with-deps-latest.zip
unzip libtorch-shared-with-deps-latest.zip


## CPP_part

To get started with CPP_part, to compile the files, run the following commands in order:
```
cd pytorch-jsbach/CPP_part/
```
### In the configure.ac (line 10) and Makefile.am (lines 4 and 5 ). file, you must specify your path to torchlib. Keep the /lib and /include at the end.


```
autoscan
autoreconf -f -i
aclocal
autoheader 
automake --add-missing
```

To make sure that Torch is installed and its libraries are in the standard library search paths, use the LDFLAGS environment variable to tell the linker where to find the libraries.

To set environment variable for your system, run in terminal

```export LDFLAGS="-L/path/to/torch/lib"```

and 

```export LD_LIBRARY_PATH=/path/to/torch/lib```

and change to the absolute path of your torchlib library.

Do ```echo $LD_LIBRARY_PATH``` and you should see your path to torchlib library.

To generate a new configure script.

Then run 
``` ./configure ``` and
``` make ```

Once it has compiled, ``` cd .. ``` and you are in pytorch-jsbach/  and run the ./c_exec with the .pt models and 9 inputs:

```
CPP_part/c_exec Pytorch_part/model_hyb_cdrag.pt Pytorch_part/model_hyb_gs.pt Pytorch_part/model_hyb_ci.pt Pytorch_part/model_hyb_vcmax.pt Pytorch_part/model_hyb_jmax.pt
10 12 13 10 15 12 90 20 12
```
