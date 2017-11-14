set(module_pipeline_lib_src_cpu
    src/Factory.cpp
    src/GreenburstConfiguration.cpp
    PARENT_SCOPE
)

TEST_UTILS()
add_executable(greenburst_launcher src/launcher_main.cpp)
target_link_libraries(greenburst_launcher ${GREENBURST_LIBRARIES})

add_subdirectory(test)
