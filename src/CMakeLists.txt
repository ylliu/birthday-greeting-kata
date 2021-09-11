project(birthday_greeting_lib)
cmake_minimum_required(VERSION 3.20)

# Custom location of the PostgreSQL library
set(PostgreSQL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../PostgreSQL13")

set(PostgreSQL_LIBRARY_DIR "${PostgreSQL_DIR}/lib")
set(PostgreSQL_INCLUDE_DIRS "${PostgreSQL_DIR}/include")

set(HEADER_FILES
        DataBaseEmployeesRepository.h
        Employee.h
        Date.h
        BirthdayService.h
        MailSender.h
        SmtpMessage.h
        EmployeeRepository.h
        GreetingSender.h
        )

set(SOURCE_FILES
        DataBaseEmployeesRepository.cpp
        Employee.cpp
        Date.cpp
        BirthdayService.cpp
        MailSender.cpp
        SmtpMessage.cpp
        EmployeeRepository.cpp
        GreetingSender.cpp
        )
# json
include_directories(../lib/json)
# Include the found INCLUDE directory
include_directories(${PostgreSQL_INCLUDE_DIRS})

link_directories(${PostgreSQL_LIBRARY_DIRS})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(${PROJECT_NAME} libjsoncpp.a)