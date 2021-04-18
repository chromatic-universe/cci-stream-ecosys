//chromatic_stream_mda.h   chromatic universe 2020  william k. johnson

#pragma once

//c++ std
#include <string>
#include <memory>
#include <map>
#include <fstream>
#include <sstream>
#include <exception>
#include <chrono>
#include <future>
#include <cassert>
//cci
#include <cci_meta_daemon.h>
#include <cci_time_utils.h>
//contrib
#include <Python.h>
#include <ace/Service_Config.h>
#include <ace/Service_Repository.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PosixThreadFactory.h>
#include <thrift/server/TThreadedServer.h>

//policies
#include <mda_environment_policy.hpp>
#include <mda_stream_handle_policy.hpp>
#include <mda_sys_init_policy.hpp>
#include <mda_sys_deinit_policy.hpp>
#include <mda_daemon_procedure_policy.hpp>

//sycall
#include <cci_stream_mda_syscall.h>
#include <shared_types.h>
#include <SharedService.h>




namespace cci_stream_mda
{


		//forward declarations
		class mda_metadata_store;




		//aliases
		using meta_store_t = mda_metadata_store*;
		using void_ptr = void*;



		//domain metadata store
		class mda_metadata_store
		{


			public :

				mda_metadata_store( const bool daemonize = true ) :  m_ptr_mem_share { nullptr } ,
										      m_fd { 0 }  ,
										      m_semaphore { nullptr } ,
										      m_daemonize { daemonize }
				{}

				~mda_metadata_store()
				{}


			private :

				//attributes
				void_ptr 	    m_ptr_mem_share;
				int 		    m_fd;
				sem_t* 		    m_semaphore;
				bool            m_daemonize;
                                std::string     m_chroot_dir;
                                std::string     m_log_path;
                                std::string     m_conf_file;


			public :

				//accessors-inspectors
				void_ptr mem_share() { return m_ptr_mem_share; }
				int fd() const noexcept { return m_fd; }
				sem_t* semaphore()  { return m_semaphore; }
				bool daemonize() const noexcept { return m_daemonize; }
                                std::string chroot_dir() const noexcept { return m_chroot_dir; }
				std::string log_path() const noexcept { return m_log_path; }
				std::string conf_file() const noexcept { return m_conf_file; }
				//mutators
				void mem_share( void_ptr share ) { m_ptr_mem_share = share; }
				void fd( const int dw ) { m_fd = dw; }
				void semaphore( sem_t* sema ) { m_semaphore = sema; }
				void daemonize( const bool dz ) { m_daemonize = dz; }
                                void chroot_dir( const std::string& root ) { m_chroot_dir = root; }
    			        void log_path( const std::string& log  ) { m_log_path = log; }
				void conf_file( const std::string& conf  ) { m_conf_file = conf; }


		};




		//cci_stream_mda
		using cci_stream_mda_dispatcher = cci_policy::cci_daemon_dispatcher<        //metadata store
											    meta_store_t ,
											    //stream hamdles
											    cci_mda_policy::mda_ace_stream_context ,
											    //environment
											    cci_mda_policy::mda_default_environment_context ,
											    //init
											    cci_mda_policy::stream_mda_sys_init ,
											    //runtime procedure
											    cci_mda_policy::stream_mda_daemon_procedure ,
										            //command line itnerface
											    cci_policy::default_command_line ,
											    //deinit
											    cci_mda_policy::stream_mda_sys_deinit>;






}


