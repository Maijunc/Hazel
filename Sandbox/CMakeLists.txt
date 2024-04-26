# Sandbox/CMakeLists.txt

# Define the project Sandbox
add_executable(Sandbox)

file(GLOB SANDBOX_SOURCES "src/*.cpp" "src/*.h" "src/Hazel/*.h" "src/Hazel/*.cpp")

target_sources(Sandbox
        PRIVATE
        ${SANDBOX_SOURCES}
        )

target_include_directories(Sandbox
        PRIVATE
        "../Hazel/vendor/spdlog/include"
        "../Hazel/src"
        )

target_link_libraries(Sandbox
        PRIVATE
        Hazel
        )

# 这里是自动寻找.dylib文件的，如果要手动配置目标地址，就按下面的来
# target_link_libraries(Sandbox
#        PRIVATE
#        Hazel
#        LINK_DIRECTORIES
#        ${CMAKE_BINARY_DIR}/path_to_hazel_library_directory
#        )

set_target_properties(Sandbox
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${outputdir}/Sandbox"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${outputdir}/Sandbox"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${outputdir}/Sandbox"
        )

# Windows specific settings
if(WIN32)
    target_compile_definitions(Sandbox
            PRIVATE
            HZ_PLATFORM_WINDOWS
            _UNICODE
            UNICODE
            )
endif()

# Configuration settings
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Dist")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DHZ_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DHZ_RELEASE")
set(CMAKE_CXX_FLAGS_DIST "${CMAKE_CXX_FLAGS_DIST} -DHZ_DIST")

# Compiler flags
if(MSVC)
    target_compile_options(Sandbox PRIVATE /W4)
else()
    target_compile_options(Sandbox PRIVATE -Wall -Wextra -pedantic)
endif()
