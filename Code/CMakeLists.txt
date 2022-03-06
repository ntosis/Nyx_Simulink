cmake_minimum_required(VERSION 3.14.4)
project (buildSimulikStaticLib)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR ARM)

if(MINGW OR CYGWIN OR WIN32)
    set(UTIL_SEARCH_CMD where)
elseif(UNIX OR APPLE)
    set(UTIL_SEARCH_CMD which)
endif()

set(TOOLCHAIN_PREFIX arm-none-eabi-)

set(ENV{PATH} "/home/unix/Tools/gcc-arm-none-eabi-10.3-2021.10/bin")

execute_process(
  COMMAND ${UTIL_SEARCH_CMD} ${TOOLCHAIN_PREFIX}gcc
  OUTPUT_VARIABLE BINUTILS_PATH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}gcc)
set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER})
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}g++)

# Default C compiler flags
set(CMAKE_C_FLAGS_DEBUG_INIT "-g -Og -Wall -pedantic -DDEBUG")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG_INIT}" CACHE STRING "" FORCE)
set(CMAKE_C_FLAGS_RELEASE_INIT "-O3 -Wall")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE_INIT}" CACHE STRING "" FORCE)
set(CMAKE_C_FLAGS_MINSIZEREL_INIT "-Os -Wall")
set(CMAKE_C_FLAGS_MINSIZEREL "${CMAKE_C_FLAGS_MINSIZEREL_INIT}" CACHE STRING "" FORCE)
set(CMAKE_C_FLAGS_RELWITHDEBINFO_INIT  "-O2 -g -Wall")
set(CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELWITHDEBINFO_INIT}" CACHE STRING "" FORCE)
# Default C++ compiler flags
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g -Og -Wall -pedantic -DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG_INIT}" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-O3 -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE_INIT}" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_MINSIZEREL_INIT "-Os -Wall")
set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL_INIT}" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT  "-O2 -g -Wall")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT}" CACHE STRING "" FORCE)

set(CMAKE_OBJCOPY ${ARM_TOOLCHAIN_DIR}/${TOOLCHAIN_PREFIX}objcopy CACHE INTERNAL "objcopy tool")
set(CMAKE_SIZE_UTIL ${ARM_TOOLCHAIN_DIR}/${TOOLCHAIN_PREFIX}size CACHE INTERNAL "size tool")

#Set Sources and includes. 
#Bring the headers into the project
include_directories(ADCRawToIab
CalcSpinSpeednDir
FOC
PWMtoAngle
SafetyChecks
_sharedutils
Interface)
#compile options
add_compile_options(-mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx  -Og -ffunction-sections -fdata-sections -Wall -Wextra -fstack-usage
--specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb
-ffile-prefix-map=/home/runner/work/Nyx/Nyx/SW/STM32CubeIDE_prj=.
-ffile-prefix-map=/home/runner/work/Nyx_Simulink=.)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "ADCRawToIab/*.c"
"CalcSpinSpeednDir/*.c"
"FOC/*.c"
"PWMtoAngle/*.c"
"SafetyChecks/*.c"
"_sharedutils/*.c")

#Generate the static library from the sources
add_library(appSimulink STATIC ${SOURCES})


