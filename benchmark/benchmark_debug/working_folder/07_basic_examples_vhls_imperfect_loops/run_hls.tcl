
# Create a project
open_project test_proj

# Add design files
add_files loop_imperfect.cpp
# Add test bench & files
add_files -tb loop_imperfect_test.cpp
add_files -tb result.golden.dat

# Set the top-level function
set_top loop_imperfect
open_solution solution

set_part {xc7z020clg484-1}
create_clock -period 10 -name default
csim_design
csynth_design
cosim_design
exit
