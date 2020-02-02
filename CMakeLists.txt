cmake_minimum_required(VERSION 3.11)
project("GGJ2020")

# Set c++ version
set(CMAKE_CXX_STANDARD 17)

# Set include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Link libaries directories for Windows, MacOsX or Linux
if (WIN32)
    if (CMAKE_CL_64)
        link_directories(${CMAKE_SOURCE_DIR}/lib/win64)
    else (CMAKE_CL_64)
        link_directories(${CMAKE_SOURCE_DIR}/lib/win32)
    endif (CMAKE_CL_64)
elseif (APPLE)
	link_directories(${CMAKE_SOURCE_DIR}/lib/osx)
endif ()

# Build type: Debug, RelWithDebInfo, MinSizeRel or Release
# Debug: print debug messages and use -g for valgrind
# RelWithDebInfo: print debug messages and don't use -g
# Release: no debug message and no -g
if (WIN32)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -DDEBUG")
    set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL}")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
else (WIN32)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -g")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -DDEBUG")
    set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL}")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -Wno-unused-variable -Wno-unused-parameter")
endif (WIN32)

# Sources
SET(SOURCES
        src/Main.cpp
        src/Core/Core.cpp
        src/Core/Core.hpp
        src/Object/GameObject/IGameObject.hpp
        src/Object/GameObject/AGameObject.cpp
        src/Object/GameObject/AGameObject.hpp
        src/Object/GameObject/StaticGameObject.cpp
        src/Object/GameObject/StaticGameObject.hpp
        src/Object/GameObject/AnimatedGameObject.cpp
        src/Object/GameObject/AnimatedGameObject.hpp
        src/Object/GameObject/Objects/PlayerOld.cpp
        src/Object/GameObject/Objects/PlayerOld.hpp
        src/Object/GameObject/Objects/PlayerSchool.cpp
        src/Object/GameObject/Objects/PlayerSchool.hpp
        src/Object/UIObject/IUIObject.hpp
        src/Object/SoundObject/MusicObject.cpp
        src/Object/SoundObject/MusicObject.hpp
        src/Object/SoundObject/SoundObject.cpp
        src/Object/SoundObject/SoundObject.hpp
        src/Scene/IScene.hpp
        src/Scene/AScene.cpp
        src/Scene/AScene.hpp
        src/Scene/SceneManager.hpp
        src/Scene/SceneManager.cpp
        src/Scene/Intro.cpp
        src/Scene/Intro.hpp
        src/Scene/MainMenu.cpp
        src/Scene/MainMenu.hpp
        src/Scene/Settings.cpp
        src/Scene/Settings.hpp
        src/Utils/Using.hpp
        src/Utils/FontLoader.hpp
        src/Utils/Collision/Collision.cpp
        src/Utils/Collision/Collision.hpp
        src/Utils/Exception/Exception.cpp
        src/Utils/Exception/Exception.hpp
        src/Utils/Exception/ObjectError.cpp
        src/Utils/Exception/ObjectError.hpp
        src/Utils/Exception/SceneError.cpp
        src/Utils/Exception/SceneError.hpp
        src/Utils/Exception/MusicError.cpp
        src/Utils/Exception/MusicError.hpp
        src/Utils/Exception/ShaderError.cpp
        src/Utils/Exception/ShaderError.hpp
        src/Object/UIObject/Sprite.cpp
        src/Object/UIObject/Sprite.hpp
        src/Object/UIObject/Text.cpp
        src/Object/UIObject/Text.hpp
        src/Object/UIObject/Fade.cpp
        src/Object/UIObject/Fade.hpp
        src/Object/UIObject/Button.cpp
        src/Object/UIObject/Button.hpp
        src/Object/UIObject/Rect.cpp
        src/Object/UIObject/Rect.hpp
        src/Scene/LevelTwo.cpp
        src/Scene/LevelTwo.hpp
        src/Scene/LevelOne.cpp
        src/Scene/LevelOne.hpp
        src/Object/UIObject/TippingText.cpp
        src/Object/UIObject/TippingText.hpp
        )

# Binary
add_executable(ggj ${SOURCES})

if (WIN32)
    target_link_libraries(ggj sfml-audio sfml-system sfml-graphics sfml-window)
else (WIN32)
    target_link_libraries(ggj pthread sfml-audio sfml-system sfml-graphics sfml-window)
endif (WIN32)

add_custom_command(TARGET ggj POST_BUILD
        COMMAND ${CMAKE_COMMAND}
        ARGS -E copy $<TARGET_FILE:ggj> ${CMAKE_SOURCE_DIR}/)

if (WIN32)
    set(DLLS_FILES openal32.dll sfml-audio-2.dll sfml-system-2.dll sfml-graphics-2.dll sfml-window-2.dll msvcp140d.dll vcruntime140d.dll ucrtbased.dll)
    if (CMAKE_CL_64)
        set(DLLS_PATH ${CMAKE_SOURCE_DIR}/lib/win64/)
    else (CMAKE_CL_64)
        set(DLLS_PATH ${CMAKE_SOURCE_DIR}/lib/win32/)
    endif (CMAKE_CL_64)
    foreach (file_i ${DLLS_FILES})
        add_custom_command(TARGET ggj POST_BUILD
                COMMAND ${CMAKE_COMMAND}
                ARGS -E copy ${DLLS_PATH}${file_i} ${CMAKE_SOURCE_DIR}/)
    endforeach (file_i)
endif (WIN32)