# Project Setup
open_project trial_solution
set_top priority_encoder

# Add design and testbench files
add_files basic3.cpp
add_files priority_encoder.h
add_files -tb test_priority_encoder.cpp
add_files -tb result_golden.dat

# Solution Configuration
open_solution solution1
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default

# Run Simulation and Synthesis
csim_design
csynth_design
cosim_design

exit