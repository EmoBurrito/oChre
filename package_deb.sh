#!/usr/bin/env bash
# Makes deb package

# Bash colour codes
GREEN="\e[32m"
NORMAL="\e[0m"
RED="\e[31m"

# Check for proper usage
if [ "$#" -lt 1 ]; then
    echo -e "${RED}ERROR: Illegal number of parameters."
    echo -e "USAGE: `basename "$0"` ochre_version [package_revision]${NORMAL}"
    exit 1
fi

# Set variables from parameters
ochre_version="${1}"
package_revision=1
if [ ! -z "${2}" ]; then
    package_revision="${2}"
fi
architecture_filename=`uname -m`
case ${architecture_filename} in
	x86_64)
		architecture_control="amd64"
		;;
	aarch64)
		architecture_control="arm64"
		;;
	*)
		architecture_control="unknown"
		;;
esac

package_name=ochre_${ochre_version}-${package_revision}_${architecture_filename}
echo -e "${GREEN}Packaging ${package_name}...${NORMAL}"
mkdir -p ${package_name}/{/etc/ochre,DEBIAN,/usr/games}
cp bin/oChre ${package_name}/usr/games

# Generate control file (deb metadata)
envsubst > ${package_name}/DEBIAN/control <<EOF
Package: ochre
Version: ${ochre_version}-${package_revision}
Priority: optional
Architecture: ${architecture_control}
Installed-Size: `du -c ${package_name}/{etc,usr} | grep total | sed 's/\s.*$//'`
Maintainer: Nathan Smith <xautotx@gmail.com>
Description: FOSS Blobber RPG
 Ochrewood Tribute is a pet project for myself and some friends to cut our C++ teeth on.
 We chose C++ because it iscompiled, object oriented, and cross platform.
 There are future plans to use Ogre for the GUI, but little has been done as of this point.
Homepage: https://github.com/EmoBurrito/oChre
Built-Using: g++ (= `g++ --version | grep g++ | awk '$0=$NF'`)
EOF

dpkg-deb --build ${package_name}
# echo -e "${GREEN}Cleaning up...${NORMAL}"
# rm -rf ${package_name}
echo -e "${GREEN}Done.${NORMAL}"
