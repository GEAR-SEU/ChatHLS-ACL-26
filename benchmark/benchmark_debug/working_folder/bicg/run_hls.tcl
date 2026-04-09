open_project -reset test_proj
add_files bicg.cpp
add_files bicg.h
add_files bicg_tb.cpp -tb
add_files tb_data_hls.txt -tb
open_solution solution
set_top kernel_bicg
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
csim_design
csynth_design
cosim_design
exit
