# Hazel/CMakeLists.txt

# Define the project Hazel
add_library(Hazel SHARED)

file(GLOB HAZEL_SOURCES "src/*.cpp" "src/*.h" "src/Hazel/*.cpp" "src/Hazel/*.h")

target_sources(Hazel
        PRIVATE
        ${HAZEL_SOURCES}
        )

target_include_directories(Hazel
        PRIVATE
        "vendor/spdlog/include"
        )

set_target_properties(Hazel
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${outputdir}/Hazel"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${outputdir}/Hazel"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${outputdir}/Hazel"
        )

# 设置语言为 C++
set_target_properties(Hazel PROPERTIES LINKER_LANGUAGE CXX)

# Windows specific settings
if(WIN32)
    target_compile_definitions(Hazel
            PRIVATE
            HZ_BUILD_DLL
            HZ_PLATFORM_WINDOWS
            _WINDLL
            _UNICODE
            UNICODE
            )

    add_custom_command(TARGET Hazel POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            "${CMAKE_BINARY_DIR}/bin/${outputdir}/Hazel/$
{CMAKE_BUILD_TYPE}/Hazel.dll" "${CMAKE_BINARY_DIR}/bin/${outputdir}/Sandbox"
            )
endif()

# Configuration settings
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Dist")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DHZ_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DHZ_RELEASE")
set(CMAKE_CXX_FLAGS_DIST "${CMAKE_CXX_FLAGS_DIST} -DHZ_DIST")

# Compiler flags
if(MSVC)
    target_compile_options(Hazel PRIVATE /W4)
else()
    target_compile_options(Hazel PRIVATE -Wall -Wextra -pedantic)
endif()
