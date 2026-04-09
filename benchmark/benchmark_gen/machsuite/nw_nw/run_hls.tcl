# Project Setup
open_project trial_solution
set_top needwun

# Add design and testbench files
add_files nw_nw.cpp
add_files nw_nw.h
add_files -tb nw_nw_tb.cpp
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