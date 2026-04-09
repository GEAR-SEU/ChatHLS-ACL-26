# Project Setup
open_project trial_solution
set_top shift64RightJamming

# Add design and testbench files
add_files shift64RightJamming.cpp
add_files shift64RightJamming.h
add_files -tb shift64RightJamming_tb.cpp

# Solution Configuration
open_solution solution1
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default

# Run Simulation and Synthesis
csim_design
csynth_design
cosim_design

exit