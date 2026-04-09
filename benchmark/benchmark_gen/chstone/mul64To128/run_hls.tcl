# Project Setup
open_project trial_solution
set_top mul64To128

# Add design and testbench files
add_files mul64To128.cpp
add_files mul64To128.h
add_files -tb mul64To128_tb.cpp

# Solution Configuration
open_solution solution1
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default

# Run Simulation and Synthesis
csim_design
csynth_design
cosim_design

exit