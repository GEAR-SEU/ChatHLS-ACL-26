open_project test_proj

add_files loop_functions.cpp
add_files -tb loop_functions_test.cpp
add_files -tb result.golden.dat

set_top loop_functions
open_solution solution

set_part {xc7z020clg484-1}
create_clock -period 10 -name default
csim_design
csynth_design
cosim_design
exit
