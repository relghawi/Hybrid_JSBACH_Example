bin_PROGRAMS = c_exec
c_exec_SOURCES = use_hyb_reda.cpp
c_exec_LDADD = hyb_reda_cdrag.o hyb_reda_gs.o hyb_reda_ci.o hyb_reda_vcmax.o hyb_reda_jmax.o util.o
AM_CPPFLAGS = -I./libtorch/include
AM_LDFLAGS = -L./libtorch/lib -ltorch -lc10 -ldl -pthread -ltorch_cpu -D_GLIBCXX_USE_CXX11_ABI=0

util.o: util.cpp
	g++ -c $^ -o $@ $(AM_CPPFLAGS) $(AM_LDFLAGS)

hyb_reda_cdrag.o: hyb_reda_cdrag.cpp
	g++ -c $^ -o $@ $(AM_CPPFLAGS) $(AM_LDFLAGS)

hyb_reda_gs.o: hyb_reda_gs.cpp
	g++ -c $^ -o $@ $(AM_CPPFLAGS) $(AM_LDFLAGS)

hyb_reda_ci.o: hyb_reda_ci.cpp
	g++ -c $^ -o $@ $(AM_CPPFLAGS) $(AM_LDFLAGS)

hyb_reda_vcmax.o: hyb_reda_vcmax.cpp
	g++ -c $^ -o $@ $(AM_CPPFLAGS) $(AM_LDFLAGS)

hyb_reda_jmax.o: hyb_reda_jmax.cpp
	g++ -c $^ -o $@ $(AM_CPPFLAGS) $(AM_LDFLAGS)

c_exec: $(c_exec_LDADD)
	g++ $(c_exec_SOURCES) $(c_exec_LDADD) -o $@ $(AM_CPPFLAGS) $(AM_LDFLAGS)

clean:
	rm -f c_exec util.o hyb_reda_cdrag.o hyb_reda_gs.o hyb_reda_ci.o hyb_reda_vcmax.o hyb_reda_jmax.o
