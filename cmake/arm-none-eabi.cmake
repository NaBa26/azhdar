set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_SIZE arm-none-eabi-size)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(TARGET_FLAGS
    -mcpu=cortex-m4
    -mthumb
    -mfloat-abi=soft
)

set(CMAKE_C_FLAGS
    "${TARGET_FLAGS}
     -ffreestanding
     -fno-builtin
     -ffunction-sections
     -fdata-sections
     -Wall
     -Wextra
     -g3"
)

set(CMAKE_EXE_LINKER_FLAGS
    "${TARGET_FLAGS}
     -nostdlib
     -Wl,--gc-sections"
)
