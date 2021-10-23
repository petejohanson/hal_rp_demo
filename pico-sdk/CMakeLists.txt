zephyr_library()

set(RP2_COMMON_DIR ${CMAKE_CURRENT_LIST_DIR}/src/rp2_common)
set(RP2040_DIR ${CMAKE_CURRENT_LIST_DIR}/src/rp2040)
set(COMMON_DIR ${CMAKE_CURRENT_LIST_DIR}/src/common)
set(BOOT_STAGE_DIR ${RP2_COMMON_DIR}/boot_stage2)

# Compile the second stage bootloader as a separate executable

add_executable(boot_stage2)

if(CONFIG_RP2_FLASH_W25Q080)
	target_sources(boot_stage2 PRIVATE ${BOOT_STAGE_DIR}/boot2_w25q080.S)
elseif(CONFIG_RP2_FLASH_GENERIC_03H)
	target_sources(boot_stage2 PRIVATE ${BOOT_STAGE_DIR}/boot2_generic_03h.S)
elseif(CONFIG_RP2_FLASH_IS25LP080)
	target_sources(boot_stage2 PRIVATE ${BOOT_STAGE_DIR}/boot2_is25lp080.S)
elseif(CONFIG_RP2_FLASH_W25X10CL)
	target_sources(boot_stage2 PRIVATE ${BOOT_STAGE_DIR}/boot2_w25x10cl.S)
else()
	message(FATAL_ERROR Unknown flash type)
endif()

target_include_directories(boot_stage2 PUBLIC
	${CMAKE_CURRENT_LIST_DIR}
	${BOOT_STAGE_DIR}/asminclude
	${RP2_COMMON_DIR}/pico_platform/include
	${RP2040_DIR}/hardware_regs/include
	${COMMON_DIR}/pico_base/include
	)

target_link_options(boot_stage2 PRIVATE
	"-nostartfiles"
	"--specs=nosys.specs"
	"LINKER:--script=${BOOT_STAGE_DIR}/boot_stage2.ld"
	)

# Generates a binary file from the compiled bootloader
add_custom_target(bootloader_bin ALL DEPENDS boot_stage2.bin)
add_custom_command(OUTPUT boot_stage2.bin
	DEPENDS boot_stage2
	COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:boot_stage2> boot_stage2.bin
	)

# Checksums the binary, pads it, and generates an assembly file
add_custom_target(boot_stage2_asm ALL DEPENDS boot_stage2.S)
add_custom_command(OUTPUT boot_stage2.S
	DEPENDS boot_stage2.bin
	COMMAND ${Python3_EXECUTABLE} ${BOOT_STAGE_DIR}/pad_checksum
	-s 0xffffffff boot_stage2.bin boot_stage2.S)

# Pico sources necessary for every build
zephyr_library_sources(
	${RP2_COMMON_DIR}/hardware_clocks/clocks.c
	${RP2_COMMON_DIR}/hardware_pll/pll.c
	${RP2_COMMON_DIR}/hardware_xosc/xosc.c
	${RP2_COMMON_DIR}/hardware_watchdog/watchdog.c
	${RP2_COMMON_DIR}/pico_platform/platform.c
)

# Pico headers necessary for every build
zephyr_include_directories(
	${RP2_COMMON_DIR}/hardware_base/include
	${RP2_COMMON_DIR}/hardware_clocks/include
	${RP2_COMMON_DIR}/hardware_watchdog/include
	${RP2_COMMON_DIR}/hardware_xosc/include
	${RP2_COMMON_DIR}/hardware_pll/include
	${RP2_COMMON_DIR}/hardware_vreg/include
	${RP2_COMMON_DIR}/hardware_irq/include
	${RP2_COMMON_DIR}/hardware_sync/include
	${RP2_COMMON_DIR}/hardware_timer/include
	${RP2_COMMON_DIR}/hardware_resets/include
	${RP2040_DIR}/hardware_regs/include
	${RP2040_DIR}/hardware_structs/include
	${COMMON_DIR}/pico_base/include
	${COMMON_DIR}/pico_binary_info/include
	${RP2_COMMON_DIR}/pico_platform/include
	${CMAKE_CURRENT_LIST_DIR}
)

# Utilizes the pico_simple_hardware_target macro used by
# pico-sdk, to easily add sources and headers by adding
# subdirectories
macro(pico_simple_hardware_target NAME)
	zephyr_library_sources(${CMAKE_CURRENT_LIST_DIR}/${NAME}.c)
	zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
endmacro()

if(CONFIG_GPIO OR CONFIG_SERIAL)
	add_subdirectory(${RP2_COMMON_DIR}/hardware_gpio)
endif()

if(CONFIG_SERIAL)
	add_subdirectory(${RP2_COMMON_DIR}/hardware_uart)
endif()

if(CONFIG_ADC)
	add_subdirectory(${RP2_COMMON_DIR}/hardware_adc)
endif()

if(CONFIG_PWM)
	add_subdirectory(${RP2_COMMON_DIR}/hardware_pwm)
endif()
