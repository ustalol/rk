cmake_minimum_required(VERSION 3.16)
project(rk)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(documents STATIC
    src/IDocument.cpp
    src/PdfDocument.cpp
    src/HtmlDocument.cpp
    src/OdtDocument.cpp
    src/DocumentFactory.cpp
)

add_executable(${PROJECT_NAME}
    ConceptualExample.cpp
    MobilePhones.cpp
    Pizza.cpp
    Points.cpp
    Program.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE documents)

enable_testing()

add_executable(test_documents test/test_documents.cpp)
target_link_libraries(test_documents PRIVATE documents)

add_test(NAME test_documents_run COMMAND test_documents)
