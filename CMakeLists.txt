cmake_minimum_required(VERSION 3.13)
project(operator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE "Release")

add_executable(operator src/operator.cpp
        #在raspberry 上再把注释删掉
	include/Motor_Control.cpp include/Motor_Control.h
        )

#在raspberry 上再把注释删掉
find_library(WIRINGPI_LIBRARIES NAMES wiringPi)

target_link_libraries(operator 
${WIRINGPI_LIBRARIES}

)
