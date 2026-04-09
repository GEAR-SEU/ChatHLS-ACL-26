# Project Setup
open_project trial_solution
set_top adv_fsm

# Add design and testbench files
add_files advanced3.cpp
add_files adv_fsm.h
add_files -tb adv_fsm_test.cpp

# Solution Configuration
open_solution solution1
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default

# Run Simulation and Synthesis
csim_design
csynth_design
cosim_design

exit