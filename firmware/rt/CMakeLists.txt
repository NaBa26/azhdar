add_executable(rt.elf
    main.c
    ../common/startup.c
    ../common/uart.c
)

target_include_directories(rt.elf PRIVATE
    ../common
)

target_link_options(rt.elf PRIVATE
    -T${CMAKE_SOURCE_DIR}/cmake/mps2-an386.ld
)

set_target_properties(rt.elf PROPERTIES
    OUTPUT_NAME "rt"
)

add_custom_command(TARGET rt.elf POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:rt.elf>
)
