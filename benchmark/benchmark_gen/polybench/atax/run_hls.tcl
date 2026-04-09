open_project -reset trial_solution
add_files atax.cpp
add_files atax.h
add_files atax_tb.cpp -tb
add_files tb_data_hls.txt -tb
open_solution solution
set_top kernel_atax
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default
csim_design
csynth_design
cosim_design
exit
