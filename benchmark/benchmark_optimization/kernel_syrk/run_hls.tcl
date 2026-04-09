open_project -reset test_proj
add_files kernel_syrk.cpp

set_top kernel_syrk
open_solution -reset solution

set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default

csynth_design
exit
