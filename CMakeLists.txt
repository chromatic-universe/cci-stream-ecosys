# cci-stream-ecosys  chromatic-universe  2021   william k. johnson

# version
cmake_minimum_required(VERSION 3.2)

# project
project(cci-stream-ecosys)

# kernel upstream
#
add_subdirectory(cci-daemon/cci_daemon/src/core)
add_subdirectory(cci-daemon/cci_daemon/src/kernel)
#
# stream adapters
#
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



 








