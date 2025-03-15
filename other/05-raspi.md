<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | Raspi ]**

## Raspi

---

#### Install RaspiOS Lite 64

* Copy image

    *replace sdX with the corresponding device, for example sdc*

    ```
    unxz ./raspios64-lite.img.xz
    lsblk
    umount /dev/sdX?
    sudo dd if=./raspios64-lite.img of=/dev/sdX bs=4M conv=fsync status=progress
    ```

* Upgrade

    ```
    sudo raspi-config
    (change locale and timezone)
    sudo apt update && sudo apt upgrade
    reboot
    ```

* Switch to Trixie

    `sudo nano /etc/apt/sources.list.d/raspi.list`
    
    comment the repository like so :
    
    ```
    #deb http://archive.raspberrypi.com/debian/ bookworm main
    # Uncomment line below then 'apt-get update' to enable 'apt-get source'
    #deb-src http://archive.raspberrypi.com/debian/ bookworm main
    ```

    edit sources.list : 
    
    `sed -i.bak s/bookworm/trixie/g /etc/apt/sources.list`
    
    ```
    sudo apt update && sudo apt upgrade
    sudo apt full-upgrade
    reboot
    ```
    
    list raspi packages : `apt list ?obsolete`

* Install XFCE

    ```
    sudo tasksel
    (select debian desktop and xfce)
    
    sudo systemctl set-default graphical.target
    sudo apt purge plymouth
    reboot
    ```


#### Install Debian Trixie

* Installation
    
    Download an image from daily builds :  
    https://raspi.debian.net/daily-images/  
    
    Default user is **root** with empty password.

    ```
    apt update && apt upgrade
    apt install sudo debconf kbd locales

    dpkg-reconfigure tzdata
    dpkg-reconfigure locales

    useradd -s /bin/bash -d /home/<username> -m <username>
    passwd <username>
    usermod -aG sudo <username>
    reboot

    (log as new user)
    
    sudo tasksel
    (select debian desktop and xfce)
    
    sudo apt purge plymouth
    sudo reboot
    ```

    Add hostname manually in `/etc/hosts` :

    ```
    127.0.0.1	localhost
    127.0.1.1	<hostname>
    ::1	localhost ip6-localhost ip6-loopback
    ff02::1	ip6-allnodes
    ff02::2	ip6-allrouters
    ```


#### Manual configuration

* Install labwc

    `sudo apt install labwc swaybg kanshi`
    
    https://labwc.github.io/getting-started.html  
    
    create configuration files for labwc in `~/.config/labwc`  
    reboot and select the labwc session  

* Menu icons
    
    create settings.ini into `~/.config/gtk-3.0` :
    
    ```
    [Settings]
    gtk-button-images=1
    gtk-menu-images=1
    ```

* XFCE panel

    force all plugins to run as internal:

    `xfconf-query -c xfce4-panel -p /force-all-internal -t bool -s true --create`
    
<br/>


