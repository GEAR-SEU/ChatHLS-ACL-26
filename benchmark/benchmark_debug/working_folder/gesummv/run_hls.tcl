open_project -reset test_proj
add_files gesummv.cpp
add_files gesummv.h
add_files gesummv_tb.cpp -tb
add_files tb_data_hls.txt -tb
open_solution solution
set_top kernel_gesummv
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
csim_design
csynth_design
cosim_design
exit
