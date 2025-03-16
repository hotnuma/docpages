<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | Raspi ]**

## Raspi

---

#### References

* Rpi

    https://github.com/orgs/raspberrypi-ui/repositories  
    https://github.com/orgs/RPi-Distro/repositories  
    https://github.com/orgs/raspberrypi/repositories  
    https://github.com/raspberrypi/bookworm-feedback/issues  
    
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





<!--

#### Old raspi docs

* rpi links

    https://www.raspberrypi.com/documentation/  
    https://www.raspberrypi.com/documentation/computers/raspberry-pi.html  
    https://linuxhint.com/gpio-pinout-raspberry-pi/  
    [tearing_test](https://www.youtube.com/watch?v=cuXsupMuik4)  
    [howto_desktops](https://forums.raspberrypi.com/viewtopic.php?t=133691)  
    [howto_autostart](https://forums.raspberrypi.com/viewtopic.php?t=294014)  
    https://github.com/raspberrypi/rpi-eeprom  

* Install Thorium Browser

    https://github.com/Alex313031/Thorium-Raspi/releases  
    
    `sudo unzip -d /opt/thorium thorium-browser_128.0.6613.194_arm64.zip`
    
    under wayland : `/opt/thorium/thorium --ozone-platform=wayland`

* Avoid keyring password
    
    https://unix.stackexchange.com/questions/324843/  
    
    `rm ~/.local/share/keyrings/*.keyring`
    
    Restart Chrome, when prompted to create a keyring, continue without entering a password. (Turns out you would have been okay if you did this the first time.)

* SD cards

    [best-ssd-storage](https://jamesachambers.com/best-ssd-storage-adapters-for-raspberry-pi-4-400/)  

* Revert to specific firmware using git commit hash

    https://www.raspberrypi.com/documentation/computers/os.html  
    
    `sudo rpi-update 6e61ab523f0a9d2fbb4319f6f6430d4c13203c0e`

* Revert to stable firmware

    ```
    sudo apt update
    sudo apt install --reinstall libraspberrypi0 libraspberrypi-{bin,dev,doc} raspberrypi-bootloader raspberrypi-kernel
    ```

* Fix screen tearing
    
    `/etc/xdg/menus/lxde-pi-applications.menu`
    
    https://forum.manjaro.org/t/how-to-fix-intel-screen-tearing-on-xfce/31361/1  
    
    ```
    1- Go to “setting manager”
    2- Go to “setting editor”
    3- Choose “xfwm4”
    4- Find “vblank_mode” and select
    5- Press the “edit”
    6- Type glx to “value” section
    7- Save and reboot

    Note: This is the gui way of those commands
    xfwm4 --replace --vblank=glx &
    xfconf-query -c xfwm4 -p /general/vblank_mode -s glx
    ```

* SSD Boot
    
    Change boot order with `raspi-config`
    
    View current EEPROM configuration : `rpi-eeprom-config`
    
    Edit configuration : `sudo -E rpi-eeprom-config --edit`
    
    Add `USB_MSD_DISCOVER_TIMEOUT=5`
    
    [udev_trim](https://forums.raspberrypi.com/viewtopic.php?t=307276#p1839171)  

* CPU governor

    https://askubuntu.com/questions/1021748/  
    https://raspberrypi.stackexchange.com/questions/9034/  

* Display settings

    https://forums.raspberrypi.com/viewtopic.php?p=1945199#p1945199  
    https://forums.raspberrypi.com/viewtopic.php?p=1945198#p1945198  
    https://forums.raspberrypi.com/viewtopic.php?t=325011#p1945199  
    
    `video=HDMI-1:800x480@60`

* Test RPi version

    https://forums.raspberrypi.com/viewtopic.php?t=34678  
    https://forums.raspberrypi.com/viewtopic.php?t=200059  

    ```
    ARCH=$(uname -m)
    VERSION=$(cat /etc/debian_version)
    if [[ $ARCH != "aarch64" ]] || [[ $VERSION != 11* ]]; then
        echo " *** This script was tested only on a Raspberry Pi 4B 64 bit"
        echo " *** abort..."
        exit 1
    fi

    cat /proc/cpuinfo
    grep -q BCM2708 /proc/cpuinfo
    cat /etc/*-release
    cat /proc/device-tree/model
    cat /sys/firmware/devicetree/base/model
    ```

* Anti-rpi

    https://www.fsf.org/resources/hw/single-board-computers  
    https://wiki.debian.org/RaspberryPi/  

    Limitations
    
    - 1.2A current limit for all USB plugs
    - slow SD controller (40 MB/s)
    - incompatible usb to sata controllers

* Drive consumption

    Toshiba Canvio Basics : a maximum of 900mA power, even in the largest capacity version.
    
    Kingston a400 SSD : 0.195W Idle / 0.279W Avg / 0.642W (MAX) Read / 1.535W (MAX) Write

* Upgrade
    
    https://gist.github.com/jauderho/6b7d42030e264a135450ecc0ba521bd8  
    https://raspberrytips.com/update-raspberry-pi-latest-version/  

-->


