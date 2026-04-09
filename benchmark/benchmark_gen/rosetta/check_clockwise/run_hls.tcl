# Project Setup
open_project trial_solution
set_top check_clockwise

# Add design and testbench files
add_files check_clockwise.cpp
add_files check_clockwise.h
add_files -tb check_clockwise_tb.cpp

# Solution Configuration
open_solution solution1
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default

# Run Simulation and Synthesis
csim_design
csynth_design
cosim_design

exit