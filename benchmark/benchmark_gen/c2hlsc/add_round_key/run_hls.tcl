# Project Setup
open_project trial_solution
set_top AddRoundKey

# Add design and testbench files
add_files add_round_key.cpp
add_files add_round_key.h
add_files -tb add_round_key_tb.cpp

# Solution Configuration
open_solution solution1
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default

# Run Simulation and Synthesis
csim_design
csynth_design
cosim_design

exit