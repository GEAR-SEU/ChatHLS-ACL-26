open_project wire_assign
add_files wire_assign.cpp
add_files -tb test_wire_assign.cpp
set_top wire_assign
open_solution solution
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default
csim_design
csynth_design
cosim_design
exit
