cmake_minimum_required(VERSION 3.0.0)

project(volga_way)

add_subdirectory(loader)
add_subdirectory(gui)
add_subdirectory(volga)

add_custom_target(copy_build)
add_custom_command(
    TARGET copy_build POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/volga/volga_way ${CMAKE_CURRENT_SOURCE_DIR}/bin/volga_way
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_SOURCE_DIR}/bin/assets
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_SOURCE_DIR}/bin/vwfs
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/assets ${CMAKE_CURRENT_SOURCE_DIR}/bin/assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/vwfs ${CMAKE_CURRENT_SOURCE_DIR}/bin/vwfs/
)