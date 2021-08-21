cmake_minimum_required(VERSION 3.21.1)

# 프로젝트명 : 실행파일 이름이 된다. 버전도 여기에 적을 수 있다.
project(OLAS VERSION 1.0)

# adder use logic
# 라이브러리에 option을 준다.
# OFF로 바꾸면 subdirectory를 빌드에서 추가하지 않게 되는 코드로 사용하고자 한다. 더 아래의 코드와 함께 사용해서 말이다.
option(USE_ADDER "A simple library for adding 2 floats." ON)

if(USE_ADDER)
    # 빌드할 라이브러리 지정. 하위폴더를 지정
    add_subdirectory(Adder)

    list(APPEND EXTRA_LIB_DIRS "Adder")
    list(APPEND EXTRA_INCLUDES_DIRS "Adder")
    list(APPEND EXTRA_LINKS adder)
endif()

# 헤더 파일에도 이 버전에 대해서 인지시킨다.
# Input/Output 순서로 적는다.
configure_file(OLASConfig.h.in OLASConfig.h)
   
# 빌드해서 나올 것들. 프로젝트명을 실행파일 이름으로 한다. 빌드 대상은 main.cpp
add_executable(${PROJECT_NAME} main.cpp)

# 헤더파일을 input에서 output으로 만드는 데 필요한 경로를 입력한다.
# version number를 기록하는데 필요하다고 한다.
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})


# Download all the Submodules
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
	option(GIT_SUBMODULE "Check submodules during build" ON)
	if(GIT_SUBMODULE)
		message(STATUS "Submodule update")
		execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
		                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		                RESULT_VARIABLE GIT_SUBMOD_RESULT)
		if(NOT GIT_SUBMOD_RESULT EQUAL "0")
			message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}. please check...")
		endif()
	endif()
endif()

# Check all the Submodules
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
	message(FATAL_ERROR "git submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please...")
endif()

 
add_subdirectory(external/glfw)
 
# 헤더파일을 추가하는 곳을 지정. #include "Adder/adder.h"라고 안적을 수 있다.
target_include_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/include
    ${EXTRA_INCLUDES_DIRS}
)
 
# 링크할 라이브러리를 찾는곳. 디렉토리를 빌드하기 위해 경로를 지정한다. 이때 경로는 build된 파일이 있는 경로. 즉, out/build 기준이다.
target_link_directories(${PROJECT_NAME}
    PRIVATE external/glfw/src
    ${EXTRA_LIB_DIRS}
)
 
# exe파일에 링크할 라이브러리
target_link_libraries(${PROJECT_NAME} ${EXTRA_LINKS} glfw)