open_project -reset trial_solution
add_files heat-3d.cpp
add_files heat-3d.h
add_files heat-3d_tb.cpp -tb
add_files tb_data_hls.txt -tb
open_solution solution
set_top heat_3d
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default
csim_design
csynth_design
cosim_design
exit
