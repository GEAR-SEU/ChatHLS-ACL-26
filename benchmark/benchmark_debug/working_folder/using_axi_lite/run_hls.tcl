# Create a project
open_project -reset test_proj

# Add design files
add_files example.cpp
# Add test bench & files
add_files -tb example_test.cpp

# Set the top-level function
set_top example

open_solution solution1
set_part {xc7z020clg484-1}
create_clock -period 10 -name default

csim_design
csynth_design
cosim_design

exit