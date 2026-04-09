# Project Setup
open_project trial_solution
set_top wire_assign

# Add design and testbench files
add_files basic1.cpp
add_files wire_assign.h
add_files -tb test_wire_assign.cpp

# Solution Configuration
open_solution solution1
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default

# Run Simulation and Synthesis
csim_design
csynth_design
cosim_design

exit