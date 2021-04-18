# cci-stream-ecosys  chromatic-universe  2021   william k. johnson

# version
cmake_minimum_required(VERSION 3.1)

# project
project(cci-stream-ecosys)

if(NOT WIN32)
	  string(ASCII 27 Esc)
	    set(ColourReset "${Esc}[m")
	      set(ColourBold  "${Esc}[1m")
	        set(Red         "${Esc}[31m")
		  set(Green       "${Esc}[32m")
		    set(Yellow      "${Esc}[33m")
		      set(Blue        "${Esc}[34m")
		        set(Magenta     "${Esc}[35m")
			  set(Cyan        "${Esc}[36m")
			    set(White       "${Esc}[37m")
			      set(BoldRed     "${Esc}[1;31m")
			        set(BoldGreen   "${Esc}[1;32m")
				  set(BoldYellow  "${Esc}[1;33m")
				    set(BoldBlue    "${Esc}[1;34m")
				      set(BoldMagenta "${Esc}[1;35m")
				        set(BoldCyan    "${Esc}[1;36m")
					  set(BoldWhite   "${Esc}[1;37m")
endif()

message( "${BoldBlue}--cci-stream-ecosys  chromatic universe  2021 ...\n--${ColourReset}" )
# required libs
find_library(UUID_LIB libuuid.so PATHS $ENV{DEV}/lib
	                               /lib
				       /lib64
                                       /usr/local/lib
                                       /usr/lib)
if(NOT UUID_LIB)
	message( FATAL_ERROR  "${BoldRed--no...libuuid  not found...${ColourReset}" )
else()
	message( "${BoldBlue}--libuuid found at ${UUID_LIB}...${ColourReset}" )
endif()


# kernel upstream
#
add_subdirectory(cci-daemon/cci_daemon/src/core)
add_subdirectory(cci-daemon/cci_daemon/src/kernel)
#
# stream adapters
#${BoldBlue}
add_subdirectory(cci-develop/cci-cpp-stream/kafka)
add_subdirectory(cci-develop/cci-cpp-stream/curlpp)
add_subdirectory(cci-develop/cci-cpp-stream/stream_event)
#
# spool
#
add_subdirectory(cci-spool-fs)
#
# tunnel
#
add_subdirectory(cci_trinity_tunnel)
#
# stream message transfer agent
#
add_subdirectory(cci-stream-mta)
#
# stream message distribution agent
#
add_subdirectory(cci-stream-mda)
#
# stream compulsion
#
add_subdirectory(cci-stream-peer-compulsion)
#
# ingestors
#
add_subdirectory(cci-faux-smtpd-async)
#
# runtime supplicant sypport
#
add_subdirectory(cci-unbound-marshaler)
#
# supplicants
#
add_subdirectory(imap2020)
#
# stream graph distribution agent
add_subdirectory(cci-stream-gda)



 








