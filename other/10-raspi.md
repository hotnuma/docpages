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

    `sudo raspi-config`
    
    change locale and timezone
    
    `sudo apt update && sudo apt full-upgrade`
    
    if we don't need a camera : `sudo apt purge rpicam-apps-lite libpisp1`

    `reboot`

* Switch to Trixie

    ```
    sed -i.bak s/bookworm/trixie/g /etc/apt/sources.list
    sed -i.bak s/bookworm/trixie/g /etc/apt/sources.list.d/raspi.list
    sudo apt update && sudo apt full-upgrade
    sync
    reboot
    ```
    
* Switch to Unstable

    `sed -i.bak s/bookworm/unstable/g /etc/apt/sources.list`
    
    comment security and updates
    
    ```
    sudo apt update && sudo apt full-upgrade
    sync
    reboot
    ```

* Install XFCE

    `sudo tasksel`
    
    (select debian desktop and xfce)
    
    ```
    sudo systemctl set-default graphical.target
    sudo apt purge plymouth
    reboot
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
    autologin-user=<username>
    autologin-user-timeout=0
    autologin-session=labwc
    ```
    
    show current config : `lightdm --show-config`

* Wayland sessions
    
    ```
    ls /usr/share/wayland-sessions/
    
    labwc.desktop
    ```


#### Other

* apt-file

    ```
    sudo apt install apt-file
    sudo apt-file update
    ```
    
* Board model
    
    `cat /sys/firmware/devicetree/base/model`

* Need to run as sudo
    
    https://forums.raspberrypi.com/viewtopic.php?t=384959  

* Oak Raspberry Pi Case
    
    [https://www.instructables.com/Oak-Raspberry-Pi...](https://www.instructables.com/Oak-Raspberry-Pi-case-for-under-10/)  

* Other programs
    
    `sudo apt install hardinfo inxi`

* Read CPU temperature

    `vcgencmd measure_temp`

* Read system infos

    ```
    uname -a
    vcgencmd version
    vcgencmd bootloader_version
    vcgencmd bootloader_config
    rpi-eeprom-config
    ```

* Release notes
    
    https://downloads.raspberrypi.org/raspios_arm64/release_notes.txt  

* Remove unused kernels
    
    https://forums.raspberrypi.com/viewtopic.php?t=371710  
    
    for rpi4 : `sudo apt --autoremove remove linux-image-*-2712`

* RPI5 USB max current
    
    Set `usb_max_current_enable=1` in `/boot/firmware/config.txt`

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
    
* Wrong keyboard on Wayfire
    
    https://github.com/raspberrypi/bookworm-feedback/issues/119  

* XL4016E1 Buck converter
    
    [https://www.az-delivery.de/fr/products/xh-m401-dc-dc-step-do](https://www.az-delivery.de/fr/products/xh-m401-dc-dc-step-down-xl4016e1-poti)  

<br/>


