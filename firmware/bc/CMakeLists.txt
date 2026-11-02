add_executable(bc.elf
    main.c
    ../common/startup.c
    ../common/uart.c
)

target_include_directories(bc.elf PRIVATE
    ../common
)

target_link_options(bc.elf PRIVATE
    -T${CMAKE_SOURCE_DIR}/cmake/mps2-an386.ld
)

set_target_properties(bc.elf PROPERTIES
    OUTPUT_NAME "bc"
)

add_custom_command(TARGET bc.elf POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:bc.elf>
)
