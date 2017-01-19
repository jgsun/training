#!/bin/sh

# script for download the vmlinux of ubuntu for debug

codename=$(lsb_release -c | awk  '{print $2}')
sudo tee /etc/apt/sources.list.d/ddebs.list << EOF
deb http://ddebs.ubuntu.com/ ${codename} main restricted universe multiverse
deb http://ddebs.ubuntu.com/ ${codename}-security main restricted universe multiverse
deb http://ddebs.ubuntu.com/ ${codename}-updates  main restricted universe multiverse
deb http://ddebs.ubuntu.com/ ${codename}-proposed main restricted universe multiverse
EOF
# sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys ECDCAD72428D7C01
sudo gpg --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys C8CAB6595FDFF622

sudo apt-get update
sudo apt-get install linux-image-$(uname -r)-dbgsym

# restore the sources list
sudo rm /etc/apt/sources.list.d/ddebs.list
sudo apt-get update
