include_directories(${GTEST_INCLUDE_DIR})

link_directories(${GTEST_LIBRARY_DIR})

set(
   gtest_pipelines_src
    src/gtest_pipelines.cpp
)
add_executable(gtest_pipelines ${gtest_pipelines_src} )
target_link_libraries(gtest_pipelines ${GREENBURST_TEST_UTILS} ${GREENBURST_LIBRARIES} ${GTEST_LIBRARIES})
add_test(gtest_pipelines gtest_pipelines --test_data "${CMAKE_CURRENT_LIST_DIR}/data")
