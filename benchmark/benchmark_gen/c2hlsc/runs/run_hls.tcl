# Project Setup
open_project trial_solution
set_top Runs

# Add design and testbench files
add_files runs.cpp
add_files runs.h
add_files -tb runs_tb.cpp

# Solution Configuration
open_solution solution1
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default

# Run Simulation and Synthesis
csim_design
csynth_design
cosim_design

exit