cmake_minimum_required(VERSION 3.5)

project(RidingMotorcycle)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "C:/Qt/5.15.1/mingw81_64/lib/cmake")


find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Quick REQUIRED)


add_executable(RidingMotorcycle
  main.cpp Sources/GameObjects/Player.cpp Sources/GameObjects/Player.h Sources/GameObjects/Hurdle.h Sources/GameObjects/Hurdle.cpp Sources/GameObjects/Score.cpp Sources/GameObjects/Score.h Sources/GameObjects/Game.cpp Sources/GameObjects/Game.h Sources/GameObjects/Health.cpp Sources/GameObjects/Health.h Sources/GameObjects/Heart.cpp Sources/GameObjects/Heart.h Sources/GameObjects/Button.cpp Sources/GameObjects/Button.h Sources/GameObjects/TextInformation.cpp Sources/GameObjects/TextInformation.h)


target_link_libraries(RidingMotorcycle Qt5::Core)
target_link_libraries(RidingMotorcycle Qt5::Widgets)
target_link_libraries(RidingMotorcycle Qt5::Quick)

