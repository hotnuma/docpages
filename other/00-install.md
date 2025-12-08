<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | Install | [Raspi](05-raspi.html) | [Build](10-build.html) ]**

## Install

---

#### System Install

* Install Debian

    https://www.debian.org/distrib/  
    https://www.debian.org/releases/stable/amd64/ch04s03.fr.html  
    
    Download an ISO file and copy it to a USB drive :
    
    `sudo dd if=<file> of=<device> bs=16M status=progress oflag=sync`
    
    or
    
    `sudo cp <file> <device> && sudo sync`
    
    where <device> is the all device such as `/dev/sdc`, not a partition.
    
    https://www.youtube.com/watch?v=gddlhr9ST9Y  
    
    choose `Install` for the text based installer  
    let the domain name blank or enter a local domain such as : `mydomain.local`  
    let the root password blank in order to use `sudo`.  

* Upgrade packages
    
    `sudo apt update && sudo apt full-upgrade`
    

#### <a name="common"></a> Common settings

* Firefox and static ip
	
	https://hotnuma.github.io/docpages/linux/11-network.html  
	
* Configure Terminal
    
    font : DejaVu Sans Mono Book 11  
    colors : Select custom colors  

* Mount internal drives
    
    `sudo nano /usr/share/polkit-1/actions/org.freedesktop.UDisks2.policy`
    
    In the excerpt <action id=“org.freedesktop.udisks2.filesystem-mount-system”> in the defaults tag replace `allow_active` with yes :  

    `<allow_active>yes</allow_active>`

* USB keys access rights

    If needed, set user right to the drive mount point :
    
    `sudo chown -R $USER:$USER /media/$USER/Data/`

* Disable log messages

    https://github.com/hotnuma/doclinux/blob/master/01-Systemd.md#disable  

* Progams settings
    
    install hyphenation : `sudo apt install hyphen-fr`

* Install QtCreator

    https://unix.stackexchange.com/questions/752145/  
    https://packages.debian.org/bookworm/qtcreator  
    https://packages.debian.org/source/bookworm/qt6-base  

    `./sysconfig qtcreator`  
    
    additional packages : `qtchooser qt6-tools-dev`

    Disable unneeded plugins :
    
    ```
    QbsProjectManager
    Help
    Welcome
    Android
    Qnx
    RemoteLinux
    Modeling
    GLSLEditor
    Qt Quick
    FakeVim
    Version Control
    ```
    
    In `Edit/Preferences/Kits`.
    
    In `Qt Version`, browse to qmake path, such as :  
    `/usr/lib/qt6/bin/qmake`
    
    In the `Kits` tab, select the previously detected `Qt Version`.
    
    In the preferences of the editor, `Fonts and Colors`, set font
    size to 11 and select the `Default Classic` color scheme.

* Install yt-dlp

    https://github.com/yt-dlp/yt-dlp  
    https://github.com/yt-dlp/yt-dlp/issues/14404  
    
    deno :
    
    ```
    wget -O /tmp/install.sh \
    https://deno.land/install.sh
    chmod +x /tmp/install.sh
    /tmp/install.sh -y --no-modify-path
    sudo ln -s ~/.deno/bin/deno /usr/local/bin/deno
    ```
    
    x86_64 :
    
    ```
    sudo wget -O /usr/local/bin/yt-dlp \
    https://github.com/yt-dlp/yt-dlp/releases/latest/download/yt-dlp_linux
    sudo chmod +x /usr/local/bin/yt-dlp
    ```
    
    aarch64 :
    
    ```
    sudo wget -O /usr/local/bin/yt-dlp \
    https://github.com/yt-dlp/yt-dlp/releases/latest/download/yt-dlp_linux_aarch64
    sudo chmod +x /usr/local/bin/yt-dlp
    ```
    
    switch to nightly : `sudo yt-dlp --update-to nightly`
    
    update : `sudo yt-dlp -U`  

* Repack gvfs-backends
    
    https://unix.stackexchange.com/questions/138188/  

    download : `apt download gvfs-backends`
    
    raw extract :
    
    `dpkg-deb -R gvfs-backends_1.57.2-2_arm64.deb gvfs-backends`
    
    file list :
    
    ```
    usr/libexec/gvfsd-mtp
    usr/libexec/gvfs-mtp-volume-monitor
    usr/lib/gvfs/gvfsd-mtp
    usr/lib/gvfs/gvfs-mtp-volume-monitor
    usr/lib/systemd/user/gvfs-mtp-volume-monitor.service
    usr/share/dbus-1/services/org.gtk.vfs.MTPVolumeMonitor.service
    usr/share/gvfs/mounts/mtp.mount
    usr/share/gvfs/remote-volume-monitors/mtp.monitor
    ```
    
    create archive from list :
    
    ```
    pushd gvfs-backends
    tar cvfz ../gvfs-mtp_1.57.2-2_arm64.tgz -T ../files.txt
    popd
    ```

    install :
    
    ```
    sudo tar xvf gvfs-mtp_1.57.2-2_arm64.tgz -C /
	killall -q /usr/lib/gvfs/gvfsd -HUP
	killall -q /usr/libexec/gvfsd -HUP
    ```

    create list :
    
    `tar tfz gvfs-mtp_1.57.2-2_arm64.tgz \
    | grep -e "[^/]$" | sort > files.txt`

* Uninstall programs

    `sudo apt purge cups*`
    
* Uninstall desktop portals

    `sudo apt purge xdg-desktop-portal*`
    

#### Specific configuration

* XFCE Session
    
    On log out, set don't save session, delete saved sessions.

* Disable grub background
    
    ```
    cat /etc/default/grub

    GRUB_DEFAULT=0
    GRUB_TIMEOUT=0
    GRUB_DISTRIBUTOR=`lsb_release -i -s 2> /dev/null || echo Debian`
    GRUB_CMDLINE_LINUX_DEFAULT="quiet"
    GRUB_CMDLINE_LINUX=""
    GRUB_BACKGROUND=
    ```

* Install Adwaita-xfwm4 theme
    
    ```
    wget https://github.com/hotnuma/Adwaita-xfwm4/archive/refs/heads/master.tar.gz
    tar xzf master.tar.gz
    mkdir $HOME/.themes
    mv ./Adwaita-xfwm4-master $HOME/.themes/Adwaita-xfwm4
    ```

* Panel dark mode

    Run `xfce4-appearance-settings`, select adwata dark and then clair theme to
    have dark panel working.

* Icon theme

    set icon theme  elementary xfce  

* Xfwm4

    Use resistance instead of magnet.
    
    If the panel is on top, disable drop down shasows :
    
    https://stackoverflow.com/questions/53725696/  


#### Graphic card

* Video test

    https://www.youtube.com/watch?v=cuXsupMuik4  

* Device nformations
    
    `sudo lspci -k | grep -EA3 'VGA|3D|Display'`

* Intel GPU
    
    https://wiki.debian.org/Firefox  
    https://wiki.debian.org/HardwareVideoAcceleration  
    https://christitus.com/fix-screen-tearing-linux/  
    https://bugzilla.mozilla.org/show_bug.cgi?id=1710400  
    
    `sudo apt purge xserver-xorg-video-intel`

<br/>

