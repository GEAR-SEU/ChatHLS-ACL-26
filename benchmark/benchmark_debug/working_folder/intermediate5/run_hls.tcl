# Create a project
open_project -reset test_proj

# Add design files
add_files left_rotate.cpp
# Add test bench & files
add_files -tb left_rotate_test.cpp 
# Set the top-level function
set_top left_rotate

# ########################################################
# Create a solution
open_solution solution1
# Define technology and clock rate
set_part  {xc7a200tfbg676-3}
create_clock -period 10

# Set variable to select which steps to execute
set hls_exec 2

csim_design
# Set any optimization directives
# End of directives

if {$hls_exec == 1} {
	# Run Synthesis and Exit
	csynth_design
} elseif {$hls_exec == 2} {
	# Run Synthesis, RTL Simulation and Exit
	csynth_design
	cosim_design
} elseif {$hls_exec == 3} { 
	# Run Synthesis, RTL Simulation, RTL implementation and Exit
	csynth_design
	cosim_design
	export_design
} else {
	# Default is to exit after running csynth
	csynth_design
}

exit
