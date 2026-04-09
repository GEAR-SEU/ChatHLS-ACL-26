# Project Setup
open_project trial_solution
set_top aes256_encrypt_ecb

# Add design and testbench files
add_files aes_aes.cpp
add_files aes_aes.h
add_files -tb aes_aes_tb.cpp
add_files -tb input.data
add_files -tb check.data

# Solution Configuration
open_solution solution1
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default

# Run Simulation and Synthesis
csim_design
csynth_design
cosim_design

exit