#!/bin/bash
#DivConf
#Configure sus equipos Debian y construya paquetes
DEB="DEB"
COPY="COPIAR"
CONF="CONF"
DEL="DEL"

CADENA1="uno"
CADENA2="dos"
CADENA3=""

if [ $1 = $DEB ]; then
	echo "Creando DEB"
	dpkg-buildpackage -rfakeroot -kadrian.arroyocalle@gmail.com

fi

if [ $1 = $COPY ];
then
sudo cp -rv usr / 
fi

if [ $1 = $CONF ]; then
	echo "Configurando con DivConf"
	sudo add-apt-repository ppa:~adrian-arroyocalle/divel
	sudo add-apt-repository ppa:~adrian-arroyocalle/azpazeta
fi

if [ $1 = $DEL ]; then
	echo "Eliminando"
fi
