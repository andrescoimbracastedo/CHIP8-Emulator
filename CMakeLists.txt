cmake_minimum_required(VERSION 3.14)
project(chip8)

set(CMAKE_CXX_STANDARD 11)

# -------------------------
# System SDL2
# -------------------------
find_package(SDL2 REQUIRED)


# -------------------------
# Your executable
# -------------------------
add_executable(chip8
    Source/Chip8.cpp
    Source/Main.cpp
    Source/Platform.cpp
)

target_compile_options(chip8 PRIVATE -Wall)

target_include_directories(chip8 PRIVATE
    Source
)

# -------------------------
# Output Directories & Asset Copying
# -------------------------

# Send the final executable binary to a "bin" folder in your project root
set_target_properties(chip8 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)

# Automatically copy the Roms directory to the same output "bin" folder
file(COPY "${CMAKE_SOURCE_DIR}/Roms" DESTINATION "${CMAKE_SOURCE_DIR}/bin")

# -------------------------
# Link system SDL2
# -------------------------
target_link_libraries(chip8 PRIVATE
    SDL2::SDL2
)
