
cmake_minimum_required (VERSION 3.1)

project(digidesign_c24_driver LANGUAGES C)

set(C24_DRIVER_SRC
	src/c24_frame.c
	src/c24_frame.h
	src/c24_handshake.c
	src/c24_handshake.h
	src/c24_protocol.h
	src/c24_request.c
	src/c24_request.h
	src/c24_surface.c
	src/c24_surface.h
	src/c24_surface_manager.c
	src/c24_surface_manager.h
	src/c24_surface_private_definitions.h
	src/c24_vu_meter_mask_request.c
	src/c24_vu_meter_mask_request.h
	src/log.h
	src/network.c
	src/network.h
	src/queue.c
	src/queue.h
	src/utility.c
	src/utility.h
)

add_library(c24_driver STATIC ${C24_DRIVER_SRC})
target_include_directories(c24_driver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(exemple src/exemple.c)
target_link_libraries(exemple c24_driver pthread m) # m = math is only needed because of the sin function
