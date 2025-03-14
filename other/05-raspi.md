<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | Raspi ]**

### Raspi

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

    configure and upgrade :

    ```
    sudo raspi-config
    (change locale and timezone)
    sudo apt update && sudo apt upgrade
    reboot
    ```


#### Switch to Trixie
    
    ```
    sudo nano /etc/apt/....
    comment raspi
    save close
    cat file
    sed -i.bak s/bookworm/trixie/g /etc/apt/sources.list
    cat /etc/apt/sources.list
    ```


#### Install XFCE

    install xfce
    
    ```
    sudo tasksel
    (select debian desktop and xfce)
    
    sudo systemctl set-default graphical.target
    sudo apt purge plymouth
    sudo apt install labwc swaybg kanshi
    reboot
    ```
    
    from XFCE desktop :
    
    create configuration files for labwc
    

#### Install Debian Trixie

* Installation
    
    Download an image from daily builds : https://raspi.debian.net/daily-images/  
    
    ```
    user : root
    passwd : <empty>

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
    sudo reboot
    
    sudo apt purge plymouth

    Add hostname manually in /etc/hosts :

    127.0.0.1	localhost
    127.0.1.1	<hostname>
    ::1	localhost ip6-localhost ip6-loopback
    ff02::1	ip6-allnodes
    ff02::2	ip6-allrouters
    ```


