cmake_minimum_required(VERSION 3.20)
project(MySFMLApp)

set(CMAKE_CXX_STANDARD 20)
set(BUILD_SHARED_LIBS OFF)

add_subdirectory(SFML)

# ------------------------------------
# Load RTL first (defines rtl_enable)
# ------------------------------------
add_subdirectory(ReflectionTemplateLib)

add_executable(MySFMLApp src/main.cpp)

target_link_libraries(MySFMLApp PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)

# ----------------------------------------------
# Enable RTL (runtime + registration injection)
# ----------------------------------------------
rtl_enable(MySFMLApp)

target_compile_definitions(MySFMLApp PRIVATE SFML_STATIC)