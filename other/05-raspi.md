<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | [Install](00-install.html) | Raspi | [Build](10-build.html) ]**

## Raspi

---

#### References

* Raspi
    
    https://www.raspberrypi.com/documentation/  
    https://pinout.xyz/  
    
    https://github.com/orgs/raspberrypi-ui/repositories  
    https://github.com/orgs/raspberrypi/repositories  
    https://github.com/orgs/RPi-Distro/repositories  

* Labwc
    
    https://github.com/labwc/labwc/commits/master/  
    https://labwc.github.io/getting-started.html  
    https://wiki.archlinux.org/title/Labwc  


#### System Install

* RaspiOS Lite 64

    [raspberry-pi-os-64-bit](https://www.raspberrypi.com/software/operating-systems/#raspberry-pi-os-64-bit)  
    
    Download RaspiOS Lite 64 bits and copy the image :
    
    *replace /dev/sdX with the corresponding device, for example /dev/sdc*

    ```
    sha256sum ./raspios64-lite.img.xz
    unxz ./raspios64-lite.img.xz
    lsblk
    umount /dev/sdX?
    sudo dd if=/dev/zero of=/dev/sdX bs=512 count=1 conv=notrunc
    sudo dd if=./raspios64-lite.img of=/dev/sdX bs=4M conv=fsync status=progress
    ```

* Upgrade packages

    ```
    sudo apt update && sudo apt full-upgrade
    sudo apt purge rpicam-apps-lite rpi-connect-lite libpisp1
    sudo dpkg-reconfigure tzdata  
    sudo dpkg-reconfigure locales  
    sync
    reboot
    ```

* Switch to Unstable

    `sudo nano /etc/apt/sources.list`

    ```
    deb http://deb.debian.org/debian unstable main contrib non-free non-free-firmware
    deb-src http://deb.debian.org/debian unstable main contrib non-free non-free-firmware
    ```
    
    ```
    sudo apt update && sudo apt full-upgrade
    sync
    reboot
    ```
    
    https://forums.raspberrypi.com/viewtopic.php?t=335951#p2036878  
    
    ```
    Package: *
    Pin: release a=unstable
    Pin-Priority: 800

    Package: *
    Pin: origin "archive.raspberry.org"
    Pin-Priority: 200
    ```
    
* Install XFCE

    `sudo apt install tasksel`
    
    `sudo tasksel`
    
    (select debian desktop and xfce)
    
    ```
    sudo apt install gldriver-test
    sudo apt purge plymouth
    sudo systemctl set-default graphical.target
    sync
    reboot
    ```


#### Manual configuration

* Common settings

    https://hotnuma.github.io/docpages/other/00-install.html#common  

* Change border size with Labwc
    
    create overrride file : `nano ~/.config/labwc/themerc-override`
    
    ```
    border.width: 3
    ```

* Enable menu icons
    
    create Gtk settings file : `nano ~/.config/gtk-3.0/settings.ini`
    
    ```
    [Settings]
    gtk-button-images=1
    gtk-menu-images=1
    ```

* Hide bootloader screen
    
    https://forums.raspberrypi.com/viewtopic.php?t=394290#p2351439  

* Install Raspi's Firefox
	
    `sudo apt install --no-install-recommends firefox rpi-firefox-mods`

* Firefox and static ip
	
	https://hotnuma.github.io/docpages/linux/11-network.html  
	
	Disable hardware acceleration.

* Mpv Configuration
	
	https://forums.raspberrypi.com/viewtopic.php?t=360902  
	
	```
    ytdl-format=bestvideo[height<=?480]+bestaudio/best
    vo=gpu
    gpu-api=opengl
    gpu-dumb-mode=yes
    hwdec=drm-copy
	```

* Uninstall programs
    
    `sudo apt purge cloud-init cups* netplan.io network-manager rpicam-apps-lite`

* Xfce Configuration
    
    https://wiki.archlinux.org/title/Xfwm  
    
    `xfconf-query -c xfce4-panel -p /force-all-internal -t bool -s true --create`


#### System Startup

* Lightdm config

    https://wiki.archlinux.org/title/LightDM  
    
    `cat /etc/lightdm/lightdm.conf`
    
    ```
	[Seat:*]
	autologin-guest=false
	autologin-user=hotnuma
	autologin-user-timeout=0
	#autologin-session=lightdm-xsession
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

* EEPROM settings
    
    [https://www.raspberrypi.com/doc...bootloader-configuration](https://www.raspberrypi.com/documentation/computers/raspberry-pi.html#raspberry-pi-bootloader-configuration)  
    
    `sudo rpi-eeprom-config -e`
    
    POWER_OFF_ON_HALT=1
    
* Fix swap file
    
    https://forums.raspberrypi.com/viewtopic.php?t=314530  

* Fix Xorg black screen
    
    `sudo apt install gldriver-test`

* Get board version

    https://forums.raspberrypi.com/viewtopic.php?t=34678  
    https://forums.raspberrypi.com/viewtopic.php?t=200059  

    ```
    ARCH=$(uname -m)
    VERSION=$(cat /etc/debian_version)
    cat /proc/cpuinfo
    cat /etc/*-release
    cat /proc/device-tree/model
    cat /sys/firmware/devicetree/base/model
    ```

* GPIO
    
    https://pinout.xyz/  
    https://forums.raspberrypi.com/viewtopic.php?t=394138  

* Kernel 6.18
    
    https://forums.raspberrypi.com/viewtopic.php?t=394580  

* Mouse lag
    
    https://github.com/labwc/labwc/discussions/1810  
    https://github.com/raspberrypi/bookworm-feedback/issues/65  

* Oak Raspberry Pi Case
    
    [https://www.instructables.com/Oak-Raspberry-Pi...](https://www.instructables.com/Oak-Raspberry-Pi-case-for-under-10/)  

* Read system infos

    ```
    uname -a
    rpi-eeprom-config
    vcgencmd bootloader_config
    vcgencmd bootloader_version
    vcgencmd measure_clock arm
    vcgencmd measure_temp
    vcgencmd version
    ```

* Set resolution to 1366
    
    prepend in labwc/autostart :
    
    `wlr-randr --output HDMI-A-1 --custom-mode 1360x768 &`
    
* Test CPU load
    
    `sysbench cpu --threads=4 --time=30 run`
    
    `stress-ng --cpu 0 --cpu-method fft`

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
    
* XL4016E1 Buck converter
    
    [https://www.az-delivery.de/fr/products/xh-m401-dc-dc-step-do](https://www.az-delivery.de/fr/products/xh-m401-dc-dc-step-down-xl4016e1-poti)  

<br/>

