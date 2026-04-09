# Project Setup
open_project trial_solution
set_top truthtable

# Add design and testbench files
add_files intermediate7.cpp
add_files truthtable.h
add_files -tb truthtable_test.cpp
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