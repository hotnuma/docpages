
rpi debian --------------------------------------------------------------------

user : root
passwd : <empty>

apt update
apt upgrade
apt install sudo debconf kbd locales

dpkg-reconfigure tzdata
dpkg-reconfigure locales

useradd -s /bin/bash -d /home/hotnuma -m hotnuma
passwd hotnuma
usermod -aG sudo hotnuma
reboot

(log as new user)
sudo tasksel
sudo reboot

Add hostname manually in /etc/hosts :

127.0.0.1	localhost
127.0.1.1	<hostname>
::1	localhost ip6-localhost ip6-loopback
ff02::1	ip6-allnodes
ff02::2	ip6-allrouters


