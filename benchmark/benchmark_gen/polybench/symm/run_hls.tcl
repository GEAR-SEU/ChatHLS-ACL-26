open_project -reset trial_solution
add_files symm.cpp
add_files symm.h
add_files symm_tb.cpp -tb
add_files tb_data_hls.txt -tb
open_solution solution
set_top kernel_symm
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default
csim_design
csynth_design
cosim_design
exit
