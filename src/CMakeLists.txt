qt5_wrap_cpp(lab6QtClasses
  )

set(lab6Sources
  main.cpp)

qtquick_compiler_add_resources(RESOURCES
  "${RESOURCES_DIR}/resources.qrc"
  )

if (ANDROID)
  set(BINARY_NAME ${LIBRARY_NAME})
  add_library(${LIBRARY_NAME}
    SHARED
    ${RESOURCES}
    ${lab6Sources}
    )
else()
  set(BINARY_NAME ${EXECUTABLE_NAME})
  add_executable(${EXECUTABLE_NAME}
    ${lab6Sources}
    ${RESOURCES}
    )
endif()

qt5_use_modules(${BINARY_NAME} Core Widgets Gui Quick Qml)

if (ANDROID)
  add_qt_android_apk(${APK_NAME} ${LIBRARY_NAME})
endif()
