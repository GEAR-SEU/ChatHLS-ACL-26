# Project Setup
open_project trial_solution
set_top fft1D_512

# Add design and testbench files
add_files fft_transpose.cpp
add_files fft_transpose.h
add_files -tb fft_transpose_tb.cpp
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