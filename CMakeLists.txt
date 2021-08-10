cmake_minimum_required(VERSION 3.21.1)

# 프로젝트명 : 실행파일 이름이 된다.
project(OLAS) 

# 빌드해서 나올 것들. 프로젝트명을 실행파일 이름으로 한다. 빌드 대상은 main.cpp
add_executable(${PROJECT_NAME} main.cpp)

# 빌드할 라이브러리 지정. 하위폴더를 지정
add_subdirectory(Adder)

# 헤더파일을 추가하는 곳을 지정. #include "Adder/adder.h"라고 안적을 수 있다.
target_include_directories(${PROJECT_NAME} PRIVATE Adder)

# 링크할 라이브러리를 찾는곳. 디렉토리를 빌드하기 위해 경로를 지정한다. 이때 경로는 build된 파일이 있는 경로. 즉, out/build 기준이다.
target_link_directories(${PROJECT_NAME} PRIVATE Adder)

# exe파일에 링크할 라이브러리
target_link_libraries(${PROJECT_NAME} adder)