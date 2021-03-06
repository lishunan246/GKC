#
# Copyright (c) 2015, Xin YUAN, courses of Zhejiang University
# All rights reserved.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the 2-Clause BSD License.
#
# Author contact information:
#   yxxinyuan@zju.edu.cn
#
if(WIN32)
    set(ASIO_INCLUDE "D:/asio-1.10.6/include" CACHE PATH "ASIO库的include目录")
    include_directories(${ASIO_INCLUDE})
    
endif()

find_package(Threads REQUIRED)

INCLUDE_DIRECTORIES(
	"${CMAKE_CURRENT_BINARY_DIR}"
	"${CMAKE_CURRENT_SOURCE_DIR}"
	"${PROJECT_SOURCE_DIR}/RT/GkcSys/public"
	"${PROJECT_SOURCE_DIR}/RT/GkcHostSvc/include"
	"${PROJECT_SOURCE_DIR}/public/include")
LINK_DIRECTORIES("${PROJECT_BINARY_DIR}/bin")
SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")
SET(SRC_PCH_LIST "src/PreComp.cpp")
SET(SRC_LIST "src/Main.cpp")
ADD_EXECUTABLE(GkcHostSvc ${SRC_PCH_LIST} ${SRC_LIST})

add_executable(GkcHostSvcClient src/HostSvcClient.cpp)
SET_PCH(GkcHostSvc "exe" "PreComp.h" ${SRC_PCH_LIST} ${SRC_LIST})

SET_TARGET_SUBSYSTEM("Background")
SET_TARGET_PROPERTIES(GkcHostSvc PROPERTIES OUTPUT_NAME "GkcHostSvc"
	LINK_FLAGS "${STRING_LINK_FLAGS_TARGET}")
TARGET_LINK_LIBRARIES(GkcHostSvc GkcSys ${STRING_LINK_EXTRA_LIBS})
target_link_libraries(GkcHostSvcClient ${CMAKE_THREAD_LIBS_INIT})
#copy
SET_POSTBUILD_PATH_COPY(GkcHostSvc "platform" "machine" "no-config" "config" "${PROJECT_SOURCE_DIR}/RT/GkcHostSvc/setup" "*" "${EXECUTABLE_OUTPUT_PATH}")

INSTALL(TARGETS GkcHostSvc
	RUNTIME DESTINATION public/assemblies COMPONENT runtime)

SET_POSTBUILD_SRC_PATH("platform" "machine" "no-config" "" "${PROJECT_SOURCE_DIR}/RT/GkcHostSvc/setup")
INSTALL(DIRECTORY "${POSTBUILD_SRC_PATH}/"
	DESTINATION public/assemblies COMPONENT runtime)

#end

#client

