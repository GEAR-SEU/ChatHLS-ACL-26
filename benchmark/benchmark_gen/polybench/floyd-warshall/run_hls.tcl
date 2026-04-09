open_project -reset trial_solution
add_files floyd-warshall.cpp
add_files floyd-warshall.h
add_files floyd-warshall_tb.cpp -tb
add_files tb_data_hls.txt -tb
open_solution solution
set_top kernel_floyd_warshall
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default
csim_design
csynth_design
cosim_design
exit
