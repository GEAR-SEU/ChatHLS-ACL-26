# Auto-generated TCL file for HLS
open_project -reset project_1

set_top transformer

add_files transformer.cpp
add_files transformer.h

add_files -tb DRAM_attn_input.txt
add_files -tb DRAM_weights_q.txt
add_files -tb DRAM_weights_k.txt
add_files -tb DRAM_weights_v.txt
add_files -tb DRAM_layer_norm_weights_1.txt
add_files -tb DRAM_FF_weights_1.txt
add_files -tb DRAM_FF_weights_2.txt
add_files -tb DRAM_layer_norm_weights_2.txt
add_files -tb DRAM_output.txt
open_solution "solution1"

set_part {xczu7ev-ffvc1156-2-e}

create_clock -period 10 -name default

csynth_design

exit