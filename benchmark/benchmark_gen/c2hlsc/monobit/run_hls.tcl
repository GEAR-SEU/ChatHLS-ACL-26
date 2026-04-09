# Project Setup
open_project trial_solution
set_top Frequency

# Add design and testbench files
add_files monobit.cpp
add_files monobit.h
add_files -tb monobit_tb.cpp

# Solution Configuration
open_solution solution1
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default

# Run Simulation and Synthesis
csim_design
csynth_design
cosim_design

exit