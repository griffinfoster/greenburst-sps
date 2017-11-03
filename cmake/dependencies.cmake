# thirdparty dependencies
include(cmake/googletest.cmake)

include(cmake/boost.cmake)
find_package(Panda REQUIRED)
find_package(Cheetah REQUIRED)
include(cmake/hiredis.cmake)

include_directories(SYSTEM ${Boost_INCLUDE_DIR} ${CHEETAH_INCLUDE_DIR} ${PANDA_INCLUDE_DIR})
set(DEPENDENCY_LIBRARIES
    ${CHEETAH_LIBRARIES}
    ${PANDA_LIBRARIES}
    ${Boost_LIBRARIES}
    ${HIREDIS_LIBRARIES}
)

include(compiler_settings)
include(cmake/cuda.cmake)

