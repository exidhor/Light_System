#set(SPECIFIC_SFML_PATH "A:/DEV_RES/SFML-2.4.0-GCC")
set(SPECIFIC_SFML_INCLUDE_PATH "A:/Project/SFML_MODIFIED/include")

set(SFML_LIB_PATH "${PROJECT_SOURCE_DIR}/extlibs/lib")

set(SFML_LIB_PATH_DBG "${SFML_LIB_PATH}/Debug")
set(SFML_LIB_PATH_REL "${SFML_LIB_PATH}/Release")

set(SFML_LIB_DBG
        ${SFML_LIB_PATH_DBG}/libsfml-audio-d.a
        ${SFML_LIB_PATH_DBG}/libsfml-graphics-d.a
        ${SFML_LIB_PATH_DBG}/libsfml-main-d.a
        ${SFML_LIB_PATH_DBG}/libsfml-system-d.a
        ${SFML_LIB_PATH_DBG}/libsfml-window-d.a)

set(SFML_LIB_REL
        ${SFML_LIB_PATH_DBG}/libsfml-audio.a
        ${SFML_LIB_PATH_DBG}/libsfml-graphics.a
        ${SFML_LIB_PATH_DBG}/libsfml-main.a
        ${SFML_LIB_PATH_DBG}/libsfml-system.a
        ${SFML_LIB_PATH_DBG}/libsfml-window.a)