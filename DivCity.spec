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


#Fedora, openSUSE
mkdir %{buildroot}
mkdir -p %{buildroot}/usr/share
mkdir -p %{buildroot}/usr/share/templvs
mkdir %{buildroot}/usr/share/applications
mkdir %{buildroot}/usr/share/pixmaps
cp %_sourcedir/Templvs.jar %{buildroot}/usr/share/templvs/
cp %_sourcedir/Templvs.desktop %{buildroot}/usr/share/applications/
cp %_sourcedir/sample.xpm %{buildroot}/usr/share/pixmaps/templvs.xpm

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(0755,root,root)
#Cree solo los archivos estandar de Fedora, openSUSE
/usr/share/templvs/Templvs.jar
/usr/share/applications/Templvs.desktop
/usr/share/pixmaps/templvs.xpm

%changelog
* Mon Nov 5 2012 Adrian Arroyo Calle
- Primera version
