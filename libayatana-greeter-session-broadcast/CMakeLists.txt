
###########################
# Version Information
###########################

set(API_VERSION 1)
set(ABI_VERSION 1)

###########################
# Generated Lib
###########################

set(GENERATED_HEADERS
service-iface.h
)

set(GENERATED_SOURCES
service-iface.c
)

add_gdbus_codegen(
OUTFILES GENERATED_SOURCES
NAME service-iface
PREFIX org.ayatana.Desktop.Greeter.Broadcast.
NAMESPACE _ServiceIface
SERVICE_XML ${CMAKE_CURRENT_SOURCE_DIR}/../data/org.ayatana.Desktop.Greeter.Broadcast.xml
)

add_library(generated STATIC ${GENERATED_SOURCES})

target_link_libraries(generated
${GLIB2_LIBRARIES}
${GOBJECT2_LIBRARIES}
${GIO2_LIBRARIES}
)

###########################
# Lib
###########################

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fvisibility=hidden")

set(BROADCAST_HEADERS
ayatana-greeter-session-broadcast.h
)

set(BROADCAST_SOURCES
ayatana-greeter-session-broadcast.c
)

add_library(broadcast SHARED ${BROADCAST_SOURCES})

set_target_properties(broadcast PROPERTIES
  VERSION ${API_VERSION}.0.0
  SOVERSION ${ABI_VERSION}
  OUTPUT_NAME "ayatana-greeter-session-broadcast"
)

target_link_libraries(broadcast
generated
${GLIB2_LIBRARIES}
${GOBJECT2_LIBRARIES}
-Wl,--no-undefined
)

###########################
# Pkg Config
###########################

set(BROADCAST_PC "ayatana-greeter-session-broadcast-${API_VERSION}.pc")
set(apiversion "${API_VERSION}")
set(libdir "${CMAKE_INSTALL_FULL_LIBDIR}")
set(includedir "${CMAKE_INSTALL_FULL_INCLUDEDIR}")
set(VERSION "${ABI_VERSION}")

configure_file("ayatana-greeter-session-broadcast.pc.in" "${CMAKE_CURRENT_BINARY_DIR}/${BROADCAST_PC}" @ONLY)

###########################
# Installation
###########################

install(
  FILES ${BROADCAST_HEADERS}
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/libayatana-greeter-session-broadcast-${API_VERSION}"
)

install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/${BROADCAST_PC}"
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig"
)

install(
  TARGETS broadcast
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
