# Project Setup
open_project trial_solution
set_top count_slow

# Add design and testbench files
add_files advanced2.cpp
add_files count_slow.h
add_files -tb count_slow_test.cpp

# Solution Configuration
open_solution solution1
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default

# Run Simulation and Synthesis
csim_design
csynth_design
cosim_design

exit