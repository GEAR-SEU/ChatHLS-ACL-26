# Project Setup
open_project trial_solution
set_top left_rotate

# Add design and testbench files
add_files intermediate5.cpp
add_files left_rotate.h
add_files -tb left_rotate_test.cpp

# Solution Configuration
open_solution solution1
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default

# Run Simulation and Synthesis
csim_design
csynth_design
cosim_design

exit