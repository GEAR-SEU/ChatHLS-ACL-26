open_project vector_mul
add_files vector_mul.cpp
add_files -tb vector_mul_tb.cpp
set_top vector_mul
open_solution solution
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default
csim_design
csynth_design
cosim_design
exit
