################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
proj_mains/%.obj: ../proj_mains/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv8/ccs_base/arm/include" --include_path="/Applications/ti/ccsv8/ccs_base/arm/include/CMSIS" --include_path="/Users/Will/workspace_v8/ecen2440" --include_path="/Applications/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.4.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="proj_mains/$(basename $(<F)).d_raw" --obj_directory="proj_mains" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


