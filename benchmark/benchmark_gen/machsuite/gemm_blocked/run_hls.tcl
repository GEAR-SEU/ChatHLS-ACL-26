# Project Setup
open_project trial_solution
set_top bbgemm

# Add design and testbench files
add_files gemm_blocked.cpp
add_files gemm_blocked.h
add_files -tb gemm_blocked_tb.cpp
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