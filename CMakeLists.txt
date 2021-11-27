if(CONFIG_HAS_RASPBERRYPI_PICO)
	add_subdirectory(pico-sdk)
	zephyr_include_directories(include)
endif()
