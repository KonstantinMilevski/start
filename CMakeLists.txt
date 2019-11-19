cmake_minimum_required(VERSION 3.16)
project(books-lib CXX)

add_executable(books-lib main.cpp
book.cpp
keeper.cpp
librarian.cpp
menu.cpp
reader.cpp
tinyxml2.cpp
keeper.h
librarian.h
menu.h
reader.h
tinyxml2.h
book.h
                                
                                 )
target_compile_features(books-lib PUBLIC cxx_std_17)



#install(TARGETS 04-render
#        RUNTIME DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../../bin/tests
#        LIBRARY DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../../bin/tests
#        ARCHIVE DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../../bin/tests)
