open_project -reset test_proj
add_files mvt.cpp
add_files mvt.h
add_files mvt_tb.cpp -tb
add_files tb_data_hls.txt -tb
open_solution solution
set_top kernel_mvt
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
csim_design
csynth_design
cosim_design
exit
