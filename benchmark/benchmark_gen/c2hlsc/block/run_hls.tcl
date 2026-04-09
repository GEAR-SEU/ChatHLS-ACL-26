# Project Setup
open_project trial_solution
set_top BlockFrequency

# Add design and testbench files
add_files block.cpp
add_files block.h
add_files -tb block_tb.cpp

# Solution Configuration
open_solution solution1
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default

# Run Simulation and Synthesis
csim_design
csynth_design
cosim_design

exit