# Project Setup
open_project trial_solution
set_top CumulativeSums

# Add design and testbench files
add_files cusums.cpp
add_files cusums.h
add_files -tb cusums_tb.cpp

# Solution Configuration
open_solution solution1
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default

# Run Simulation and Synthesis
csim_design
csynth_design
cosim_design

exit