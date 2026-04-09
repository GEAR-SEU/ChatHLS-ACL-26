open_project -reset trial_solution
add_files jacobi-2d.cpp
add_files jacobi-2d.h
add_files jacobi-2d_tb.cpp -tb
add_files tb_data_hls.txt -tb
open_solution solution
set_top kernel_jacobi_2d
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default
csim_design
csynth_design
cosim_design
exit
