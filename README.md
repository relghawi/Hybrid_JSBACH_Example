# Hybrid Model Parametrization Notebook

This Jupyter notebook provides a workflow for **The parameterizations of a hybrid land-atmosphere model** that integrates process-based equations with machine learning. It is based on the methodology described in:

**ElGhawi, R., Reimers, C., Schnur, R., Reichstein, M., Körner, M., Carvalhais, N., & Winkler, A. J. (2025). Hybrid-Modeling of Land-Atmosphere Fluxes Using Integrated Machine Learning in the ICON-ESM Modeling Framework. Authorea Preprints.**

---

## Overview

The notebook demonstrates:

1. **Loading and preprocessing example datasets** relevant for land-atmosphere flux modeling.  
2. **Initializing the hybrid model**, which combines physical equations (e.g., energy and carbon fluxes) with machine learning to capture unresolved processes.  
3. **Training and testing the hybrid model** on the example data.  
4. **Generating predictions** for temperature (`T_TEA_NT_conv`) and gross primary productivity (`GPP_NT`).  
5. **Visualizing model performance**, including scatter plots of observed vs. predicted variables and evaluation metrics.  

---

## Example Data

The notebook uses example NetCDF files structured similarly to the ICON-ESM output:

- **Path:** `/example_data/merged_example.nc`  
- **Variables included (sample):**  
  - `T_TEA_NT_conv` – observed temperature  
  - `GPP_NT` – gross primary productivity  
  - `rad_lai_cl_pft` – radiation absorbed per PFT  
  - `assimi_carbox_rate_cl` – assimilation rates  
  - Meteorological drivers: `precip_box`, `a2l_t_air_box`, `a2l_q_air_box`, etc.

> These are representative variables used in the hybrid modeling workflow. Users can replace the example dataset with their own NetCDF files, as long as variable names are consistent with the notebook structure.

---

## Notebook Workflow

1. **Load dependencies**: Python packages including `xarray`, `pandas`, `torch`, `pytorch_lightning`, and `matplotlib`.  
2. **Data loading**: Convert NetCDF to `xarray.Dataset`, optionally subset by site or canopy layer.  
3. **DataModule setup**: Split data into training, validation, and test sets.  
4. **Hybrid model initialization**: Define neural network parameters and latent variables.  
5. **Training**: Train the model using PyTorch Lightning, with early stopping and checkpointing.  
6. **Evaluation**: Generate predictions and calculate evaluation metrics (e.g., R²).  
7. **Visualization**: Scatter plots comparing observed vs. predicted values.  

---


