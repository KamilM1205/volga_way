project(loader)

add_library(${PROJECT_NAME} src/loader.cpp)
add_library(sub::loader ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)