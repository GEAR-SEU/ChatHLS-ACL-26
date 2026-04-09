# Project Setup
open_project trial_solution
set_top counter

# Add design and testbench files
add_files intermediate2.cpp
add_files counter.h
add_files -tb counter_test.cpp
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