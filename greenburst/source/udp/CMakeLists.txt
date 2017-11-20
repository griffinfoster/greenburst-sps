set(module_udp_lib_src_cpu
    src/Config.cpp
    src/BeamFormerDataTraits.cpp
    src/BeamFormerPacket.cpp
    src/BeamFormerPacketHeader.cpp
    src/BeamFormerPacketInspector.cpp
    src/Sample.cpp
    src/UdpStream.cpp
    PARENT_SCOPE
)

TEST_UTILS()

add_subdirectory(test)
