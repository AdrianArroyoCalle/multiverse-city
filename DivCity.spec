Name: DivCity
Version: 1.0.0
Release: 1
URL: http://sites.google.com/site/divelmedia
Summary: DivCity
License: GPL
Group: Games
BuildRoot: %{_tmppath}/%{name}-%{version}-buildroot

%description
Design your city, be patient and your city will work.

%install
rm -rf $RPM_BUILD_ROOT

mkdir -p %{build_root}/usr/games/multiverse-city
mkdir -p %{build_root}/usr/share/multiverse-city/media
mkdir -p %{build_root}/usr/share/applications
mkdir -p %{build_root}/usr/share/pixmaps

cp -rv usr %{build_root}
rm %{build_root}/usr/games/MultiverseCity
g++ -fPIC -c -o %_source_dir/libmctcube.o %_source_dir/libmctcube/main.cpp `wx-config --cppflags`	
g++ -fPIC -c -o %_source_dir/concejal.o %_source_dir/libmctcube/concejal.cpp `wx-config --cppflags`
g++ -shared -fPIC -o %{build_root}/usr/lib/libmctcube.so %_source_dir/libmctcube.o %_source_dir/concejal.o
cp %{build_root}/usr/lib/libmctcube.so %_source_dir/libmctcube.so
g++ -fPIC -c -o %_source_dir/libdivcore.o %_source_dir/divcore/main.cpp `wx-config --cppflags`	
g++ -shared -fPIC -o %{build_root}/usr/lib/libdivcore.so %_source_dir/libdivcore.o -lvlc
cp %{build_root}/usr/lib/libdivcore.so %_source_dir/libdivcore.so
g++ -c %_source_dir/MCT/main.cpp -o %_source_dir/main.o `wx-config --cppflags`
g++ -c %_source_dir/MCT/MCTFrame.cpp -o %_source_dir/mct.o `wx-config --cppflags`
g++ -o %{build_root}/usr/games/MultiverseCity %_source_dir/main.o %_source_dir/mct.o `wx-config --libs` -L. -lmctcube -lpthread -lvlc  -O3 -DVLC -DPTHREAD -ldivcore

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(0755,root,root)
/usr/share/templvs/Templvs.jar
/usr/share/applications/Templvs.desktop
/usr/share/pixmaps/templvs.xpm

%changelog
* Mon Nov 5 2012 Adrian Arroyo Calle
- Primera version
