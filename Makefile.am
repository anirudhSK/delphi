AM_CXXFLAGS = $(PICKY_CXXFLAGS)
common_source = exception.hh ezio.cc ezio.hh                                   \
	file_descriptor.hh  timestamp.cc timestamp.hh                          \
	child_process.hh child_process.cc signalfd.hh signalfd.cc              \
	socket.cc socket.hh address.cc address.hh util.cc util.hh              \
	system_runner.hh system_runner.cc socket_type.hh                       \
	poller.hh poller.cc prober.cc prober.hh

bin_PROGRAMS = delphi
delphi_SOURCES = $(common_source) delphi.cc
delphi_LDADD = -lrt
delphi_LDFLAGS = -pthread
