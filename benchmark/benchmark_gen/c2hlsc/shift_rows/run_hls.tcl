# Project Setup
open_project trial_solution
set_top ShiftRows

# Add design and testbench files
add_files shift_rows.cpp
add_files shift_rows.h
add_files -tb shift_rows_tb.cpp

# Solution Configuration
open_solution solution1
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default

# Run Simulation and Synthesis
csim_design
csynth_design
cosim_design

exit