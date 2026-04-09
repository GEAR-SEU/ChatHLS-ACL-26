open_project -reset test_proj
add_files matmul.cpp

set_top matmul
open_solution -reset solution

set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default

csynth_design
exit
