cmake_minimum_required(VERSION 3.10)
project(7WondersDuel)

set(CMAKE_CXX_STANDARD 17)

# Find SFML
set(SFML_DIR "D:/Projects/repo/_external/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

# Add executable
file(GLOB SOURCES
    "7 Wonders Duel/*.cpp"
    "Logging/*.cpp"  # Ensure Logging.cpp is included
)

add_executable(7WondersDuel ${SOURCES})

# Link SFML libraries
target_link_libraries(7WondersDuel PRIVATE 
    sfml-system sfml-window sfml-graphics sfml-network sfml-audio
Logging
)

add_subdirectory(Logging)  # Add this line to include the Logging project

# Specify the directories containing resources
file(GLOB FONTS
    "7 Wonders Duel/Fonts/*.ttf"  # Add paths to your font files
)

file(GLOB IMAGES
    "7 Wonders Duel/Images/*"  # Add paths to your image files
)

file(GLOB CONFIG
    "7 Wonders Duel/Config/*"  # Add paths to your config files
)

file(GLOB UTILS
    "7 Wonders Duel/Utils/*"  # Add paths to your utility files
)

# Use POST_BUILD to copy resources after the executable is built
add_custom_command(TARGET 7WondersDuel POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/7\ Wonders\ Duel/Fonts $<TARGET_FILE_DIR:7WondersDuel>/Fonts
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/7\ Wonders\ Duel/Images $<TARGET_FILE_DIR:7WondersDuel>/Images
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/7\ Wonders\ Duel/Config $<TARGET_FILE_DIR:7WondersDuel>/Config
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/7\ Wonders\ Duel/Utils $<TARGET_FILE_DIR:7WondersDuel>/Utils
    COMMENT "Copying resources to output directory"
)

# Add custom command to copy the required DLL files
add_custom_command(TARGET 7WondersDuel POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        D:/Projects/repo/_external/SFML-2.5.1/bin/openal32.dll $<TARGET_FILE_DIR:7WondersDuel>/openal32.dll
    COMMAND ${CMAKE_COMMAND} -E copy
        D:/Projects/repo/_external/SFML-2.5.1/bin/sfml-audio-2.dll $<TARGET_FILE_DIR:7WondersDuel>/sfml-audio-2.dll
    COMMAND ${CMAKE_COMMAND} -E copy
        D:/Projects/repo/_external/SFML-2.5.1/bin/sfml-audio-d-2.dll $<TARGET_FILE_DIR:7WondersDuel>/sfml-audio-d-2.dll
    COMMAND ${CMAKE_COMMAND} -E copy
        D:/Projects/repo/_external/SFML-2.5.1/bin/sfml-graphics-2.dll $<TARGET_FILE_DIR:7WondersDuel>/sfml-graphics-2.dll
    COMMAND ${CMAKE_COMMAND} -E copy
        D:/Projects/repo/_external/SFML-2.5.1/bin/sfml-graphics-d-2.dll $<TARGET_FILE_DIR:7WondersDuel>/sfml-graphics-d-2.dll
    COMMAND ${CMAKE_COMMAND} -E copy
        D:/Projects/repo/_external/SFML-2.5.1/bin/sfml-network-2.dll $<TARGET_FILE_DIR:7WondersDuel>/sfml-network-2.dll
    COMMAND ${CMAKE_COMMAND} -E copy
        D:/Projects/repo/_external/SFML-2.5.1/bin/sfml-network-d-2.dll $<TARGET_FILE_DIR:7WondersDuel>/sfml-network-d-2.dll
    COMMAND ${CMAKE_COMMAND} -E copy
        D:/Projects/repo/_external/SFML-2.5.1/bin/sfml-system-2.dll $<TARGET_FILE_DIR:7WondersDuel>/sfml-system-2.dll
    COMMAND ${CMAKE_COMMAND} -E copy
        D:/Projects/repo/_external/SFML-2.5.1/bin/sfml-system-d-2.dll $<TARGET_FILE_DIR:7WondersDuel>/sfml-system-d-2.dll
    COMMAND ${CMAKE_COMMAND} -E copy
        D:/Projects/repo/_external/SFML-2.5.1/bin/sfml-window-2.dll $<TARGET_FILE_DIR:7WondersDuel>/sfml-window-2.dll
    COMMAND ${CMAKE_COMMAND} -E copy
        D:/Projects/repo/_external/SFML-2.5.1/bin/sfml-window-d-2.dll $<TARGET_FILE_DIR:7WondersDuel>/sfml-window-d-2.dll
    COMMENT "Copying SFML DLLs to output directory"
)
