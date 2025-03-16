<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | Raspi ]**

## Raspi

---

#### References

* Labwc
    
    https://labwc.github.io/getting-started.html  
    https://github.com/labwc/labwc-artwork/  
    https://wiki.archlinux.org/title/Labwc  


#### RaspiOS Lite 64

* Installation

    [raspberry-pi-os-64-bit](https://www.raspberrypi.com/software/operating-systems/#raspberry-pi-os-64-bit)  
    
    Download RaspiOS Lite 64 bits and copy the image :
    
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
    
    list local raspi packages : `apt list ?obsolete`

* Install XFCE

    ```
    sudo tasksel
    (select debian desktop and xfce)
    
    sudo systemctl set-default graphical.target
    sudo apt purge plymouth
    reboot
    ```

* Upgrade error
    
    https://serverfault.com/questions/905921/  
    
    ```
    update-initramfs: Generating /boot/initrd.img-6.6.74+rpt-rpi-v8
    mkinitramfs: failed to determine device for /
    mkinitramfs: workaround is MODULES=most, check:
    grep -r MODULES /etc/initramfs-tools
    ```
    
    check MODULES : `grep -r MODULES= /etc/initramfs-tools`
    
    `sudo nano /etc/initramfs-tools/initramfs.conf`
    
    change **MODULES=dep** to **MODULES=most**
    
    `update-initramfs -u`


#### Debian Trixie

* Installation
    
    Download an image from daily builds :  
    https://raspi.debian.net/daily-images/  
    
    *the FAQ says these images are not compatible with the RPI 5*
    
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
    ```

    log as new user
    
    ```
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

* Xfce Configuration
    
    https://wiki.archlinux.org/title/Xfwm  
    
    `xfconf-query -c xfwm4 -p /general/vblank_mode -s glx`

    `xfconf-query -c xfce4-panel -p /force-all-internal -t bool -s true --create`

* Install labwc

    `sudo apt install labwc swaybg kanshi`
    
    https://labwc.github.io/getting-started.html  
    
    create configuration files for labwc in `~/.config/labwc`  
    
    configs and themes : 
    
    https://github.com/hotnuma/sysconfig/tree/master/labwc  
    
    reboot and select the labwc session  

* Menu icons
    
    create settings.ini into `~/.config/gtk-3.0` :
    
    ```
    [Settings]
    gtk-button-images=1
    gtk-menu-images=1
    ```

* Configure a static ip
    
    https://hotnuma.github.io/docpages/linux/10-network.html  


#### System Startup

* Lightdm config

    https://wiki.archlinux.org/title/LightDM  
    
    ```
    cat /etc/lightdm/lightdm.conf
    
    [Seat:*]
    autologin-guest=false
    autologin-user=hotnuma
    autologin-user-timeout=0
    autologin-session=labwc
    ```
    
    show current config : `lightdm --show-config`

* Wayland sessions
    
    ```
    ls /usr/share/wayland-sessions/
    
    labwc.desktop
    ```

* Processes
    
    ```
    total : 233156 kB / 35 prc
    ```


#### Other

* apt-file

    ```
    sudo apt install apt-file
    sudo apt-file update
    ```
    
* Other programs
    
    `sudo apt install hardinfo inxi`

* Read CPU temperature

    `vcgencmd measure_temp`

* kernel, firmware, bootloader, eeprom

    ```
    uname -a
    vcgencmd version
    vcgencmd bootloader_version
    vcgencmd bootloader_config
    rpi-eeprom-config
    ```

* USB Chipset
    
    https://forums.raspberrypi.com/viewtopic.php?t=245931  
    https://forums.raspberrypi.com/viewtopic.php?t=326157  
    
    ```
    That's true for most of the JMS578 family of USB 3.0 bridge chips,
    but not necessarily with the 580 series USB 3.1 chips.
    I have a USB 3.1 Gen 2 enclosure with a JMS583 chip that works
    fine with Pi computers. It supports UASP in RPiOS, and TRIM works
    with a udev rule.
    ```
    
* Board model
    
    `cat /sys/firmware/devicetree/base/model`

* Release notes : 
    
    https://downloads.raspberrypi.org/raspios_arm64/release_notes.txt  

<br/>


