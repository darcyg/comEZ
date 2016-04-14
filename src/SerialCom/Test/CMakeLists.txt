cmake_minimum_required (VERSION 2.6)


set(project_name SerialCom_Test)

project(${project_name})

#set Variables
SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -O2 -Wall -std=c++11")

set(EXECUTABLE_PATH ${PROJECT_SOURCE_DIR}/bin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_PATH}/${project_name})


#find boost packages
find_package(Boost COMPONENTS date_time filesystem graph iostreams 
               math_c99 mpi prg_exec_monitor program_options
               regex serialization signals system thread wave REQUIRED)
#find_package(Boost REQUIRED COMPONENTS)
               
               
               
include_directories(${Boost_INCLUDE_DIR}
                    ${PROJECT_SOURCE_DIR} )
                    
link_directories(${Boost_LIBRARY_DIR} )


#grab files
file(GLOB source_files "main_test.cpp"
                       "../*.cpp" )
                    

file(GLOB source_files_thread "main_test_thread.cpp"
                       "../*.cpp" )       

#add executable_1
add_executable(${project_name} ${source_files})
add_executable(${project_name}_thread ${source_files_thread})

#link executable_1
target_link_libraries(${project_name} ${Boost_LIBRARIES} )
target_link_libraries(${project_name}_thread ${Boost_LIBRARIES} )
                                      
#-->may ad subdir:                                      
#add_subdirectory(...)
                                      
                                      

