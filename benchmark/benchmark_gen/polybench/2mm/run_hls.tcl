open_project -reset trial_solution
set_top kernel_2mm

add_files 2mm.cpp
add_files 2mm.h
add_files 2mm_tb.cpp -tb
add_files tb_data_hls.txt -tb
add_files tb_data.txt -tb

open_solution solution
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default

csim_design
csynth_design
cosim_design

exit
