set(module_pipeline_lib_src_cpu
    src/EmptyPipeline.cpp
    src/Factory.cpp
    src/GreenburstConfiguration.cpp
    src/ProcessingPipeline.cpp
    PARENT_SCOPE
)

TEST_UTILS()
add_executable(greenburst_launcher src/launcher_main.cpp)
target_link_libraries(greenburst_launcher ${GREENBURST_LIBRARIES})
set_target_properties(greenburst_launcher PROPERTIES OUTPUT_NAME greenburst)

add_subdirectory(test)
