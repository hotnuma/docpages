<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | Raspi ]**

## Raspi

---

#### References

* Raspi
    
    https://www.raspberrypi.com/documentation/  
    
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

    `sudo raspi-config`
    
    change locale and timezone
    
    if we don't need a camera : `sudo apt purge rpicam-apps-lite libpisp1`

    ```
    sudo apt update && sudo apt full-upgrade
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
    sudo systemctl set-default graphical.target
    sudo apt purge plymouth
    sync
    reboot
    ```


#### Manual configuration

* Common settings

    https://hotnuma.github.io/docpages/other/05-install.html#common  

* RPI Firefox
	
    `sudo apt install --no-install-recommends firefox rpi-firefox-mods`

* Firefox and static ip
	
	https://hotnuma.github.io/docpages/linux/11-network.html  
	
	Disable hardware acceleration.

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
    
* Board model
    
    `cat /sys/firmware/devicetree/base/model`

* List Packages not in unstable
    
    `apt list --installed | grep -v /unstable`

* List Raspi Packages
    
    `grep -h ^Package: /var/lib/apt/lists/archive.raspberrypi.com*arm64_Packages | grep -v -- -dbgsym$ | grep -v -- -dbg$ | cut -d ' ' -f 2`

* Need to run as sudo
    
    https://forums.raspberrypi.com/viewtopic.php?t=384959  

* Oak Raspberry Pi Case
    
    [https://www.instructables.com/Oak-Raspberry-Pi...](https://www.instructables.com/Oak-Raspberry-Pi-case-for-under-10/)  

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

* Set resolution to 1366
    
    prepend in labwc/autostart :
    
    `wlr-randr --output HDMI-A-1 --custom-mode 1360x768 &`
    
* Test CPU load
    
    `sysbench cpu --threads=4 --time=30 run`
    
    `stress-ng --cpu 0 --cpu-method fft`

* Test CPU temperature

    `vcgencmd measure_temp`

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

<!--
* Rpi

    https://github.com/orgs/raspberrypi-ui/repositories  
    https://github.com/orgs/RPi-Distro/repositories  
    https://github.com/orgs/raspberrypi/repositories  
    https://github.com/raspberrypi/bookworm-feedback/issues  
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

* Thorium Wrapper Script
    
    ```
    #!/usr/bin/bash

    if [[ "$XDG_SESSION_TYPE" == "wayland" ]]; then
        /opt/thorium/thorium --enable-features=UseOzonePlatform --ozone-platform=wayland 2>/dev/null &
    else
        /opt/thorium/thorium 2>/dev/null &
    fi
    ```

* raspi-config/raspi-config at bookworm
    
    [https://github.com/RPi-Distro/raspi-config/blob/bookworm/ras](https://github.com/RPi-Distro/raspi-config/blob/bookworm/raspi-config)  

* What are the installed defaults and configuration settings?
    
    https://raspi.debian.net/defaults-and-settings/  

#### Raspi Debian Trixie

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
-->


