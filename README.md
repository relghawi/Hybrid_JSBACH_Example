# Hybrid Model Parametrization Notebook + Importing to JSBACH

This Jupyter notebook provides a workflow for **The parameterizations of a hybrid land-atmosphere model** that integrates process-based equations with machine learning. It is based on the methodology described in:

**ElGhawi, R., Reimers, C., Schnur, R., Reichstein, M., Körner, M., Carvalhais, N., & Winkler, A. J. (2025). Hybrid-Modeling of Land-Atmosphere Fluxes Using Integrated Machine Learning in the ICON-ESM Modeling Framework. Authorea Preprints.**

---

## Overview

The notebook demonstrates:

1. **Loading and preprocessing example datasets** relevant for land-atmosphere flux modeling.  
2. **Initializing the hybrid model**, which combines physical equations (e.g., water and carbon fluxes) with machine learning.  
3. **Training and testing the hybrid model** on the example dataset of the grassland site AT-Neu.  
4. **Generating predictions** for transpiration (`T_TEA_NT_conv`) and night-time gross primary productivity (`GPP_NT`).  
5. **Visualizing model performance**, including scatter plots of observed vs. predicted variables and evaluation metrics.  

---

## Example Data

The notebook uses example NetCDF files structured similarly to the ICON-ESM output:

- **Unzip** `AT-Neu_exmaple.zip` and change **Path:** `./AT-Neu_exmaple.nc`  
- **Variables included (sample):**
  - **Targets:** 
  - `T_TEA_NT_conv` – observed transpiration  
  - `GPP_NT` – gross primary productivity
  - **Latents:**
  - `assimi_canopy_cond_limited_pft` – stomatal conductance  
  - `assimi_carbox_rate_max_cl_pft` – maximum carboxylation rates
  - `assimi_e_transport_rate_max_cl_pft` – maximum electron transport rates
  - Meteorological drivers: `precip_box`, `a2l_t_air_box`, `a2l_q_air_box`, etc.

> These are representative variables used in the hybrid modeling workflow. Users can replace the example dataset with their own NetCDF files, as long as variable names are consistent with the notebook structure.

---

## Notebook Workflow

1. **Load dependencies**: Python packages including `xarray`, `pandas`, `torch`, `pytorch_lightning`, and `matplotlib`.  
2. **Prep**: Normalization module and Indexing. 
3. **DataModule setup**: Split data into training, validation, and test sets.  
4. **Hybrid model initialization**: Define neural network parameters and latent variables.  
5. **Training**: Train the model using PyTorch Lightning, with early stopping and checkpointing.  
6. **Evaluation**: Generate predictions and calculate evaluation metrics (e.g., R²).  
7. **Visualization**: Scatter plots comparing observed vs. predicted values.  

---


