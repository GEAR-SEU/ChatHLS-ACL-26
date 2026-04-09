open_project -reset test_proj
add_files gemm.cpp
add_files gemm.h
add_files gemm_tb.cpp -tb
add_files tb_data_hls.txt -tb
open_solution solution
set_top kernel_gemm
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
csim_design
csynth_design
cosim_design
exit
