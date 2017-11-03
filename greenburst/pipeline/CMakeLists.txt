set(module_pipeline_lib_src_cpu
    src/EmptyPipeline.cpp
    src/GreenburstConfiguration.cpp
    src/ProcessingPipeline.cpp
    PARENT_SCOPE
)

TEST_UTILS()

add_subdirectory(test)
