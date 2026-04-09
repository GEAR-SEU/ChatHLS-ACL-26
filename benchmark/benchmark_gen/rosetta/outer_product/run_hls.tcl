# Project Setup
open_project trial_solution
set_top outer_product

# Add design and testbench files
add_files outer_product.cpp
add_files outer_product.h
add_files -tb outer_product_tb.cpp

# Solution Configuration
open_solution solution1
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default

# Run Simulation and Synthesis
csim_design
csynth_design
cosim_design

exit