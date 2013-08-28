
###########################
# Generated Lib
###########################

set(SERVICE_GENERATED_HEADERS
service-iface.h
)

set(SERVICE_GENERATED_SOURCES
service-iface.c
)

add_gdbus_codegen(
OUTFILES SERVICE_GENERATED_SOURCES
NAME service-iface
PREFIX com.canonical.Unity.Greeter.Broadcast.
NAMESPACE ServiceIface
SERVICE_XML ${CMAKE_CURRENT_SOURCE_DIR}/../data/com.canonical.Unity.Greeter.Broadcast.xml
)

add_library(service-generated STATIC ${SERVICE_GENERATED_SOURCES})

target_link_libraries(service-generated
${GLIB2_LIBRARIES}
${GOBJECT2_LIBRARIES}
)

###########################
# Service Executable
###########################

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

add_executable(service-exec service.c)

set_target_properties(service-exec PROPERTIES OUTPUT_NAME "unity-greeter-session-broadcast-service")

target_link_libraries(service-exec
service-generated
${GIO2_LIBRARIES}
)

###########################
# Installation
###########################

install(
  TARGETS service-exec
  RUNTIME DESTINATION "${CMAKE_INSTALL_FULL_LIBEXECDIR}/unity-greeter-session-broadcast"
)
