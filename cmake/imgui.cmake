include(FetchContent)
FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/TupoyeMenu/imgui.git
    GIT_TAG        c60e2d62325d488275d453af3bf21832d551e778
    GIT_PROGRESS TRUE
)
message("ImGui")

FetchContent_MakeAvailable(imgui)
file(GLOB SRC_IMGUI
    "${imgui_SOURCE_DIR}/*.cpp"
    "${imgui_SOURCE_DIR}/backends/imgui_impl_win32.cpp"
    "${imgui_SOURCE_DIR}/backends/imgui_impl_dx12.cpp"
    "${imgui_SOURCE_DIR}/backends/imgui_impl_dx11.cpp"
    "${imgui_SOURCE_DIR}/misc/cpp/imgui_stdlib.cpp"
)

add_library(imgui STATIC ${SRC_IMGUI})
source_group(TREE ${imgui_SOURCE_DIR} PREFIX "imgui" FILES ${SRC_IMGUI} )
target_include_directories(imgui PRIVATE
    "${imgui_SOURCE_DIR}"
    "${imgui_SOURCE_DIR}/backends"
    "${imgui_SOURCE_DIR}/misc/cpp"
)
set_property(TARGET imgui PROPERTY CXX_STANDARD 20)
