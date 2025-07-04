<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | [Linux](00-linux.html) | [Xfce](05-xfce.html) | [AVideo](10-avideo.html) | [Network](11-network.html) | [Systemd](20-systemd.html) | Bugs | [Other](99-other.html) ]**

## Bugs

---

#### Firefox

* DMZ Cursor bug
    
    https://forums.linuxmint.com/viewtopic.php?t=414360  
    https://forums.linuxmint.com/viewtopic.php?t=414671  
    
    change cursor to DMZ White if needed :
    
    `sudo update-alternatives --config x-cursor-theme`
    
    https://gitlab.com/donut2/notwaita-cursor-theme  

* Video stuttering regression
    
    https://bugzilla.mozilla.org/show_bug.cgi?id=1939685  
    https://hg.mozilla.org/integration/autoland/pushloghtml?startdate=2023-07-13&enddate=2023-07-16  
    https://hg.mozilla.org/integration/autoland/rev/e1c387461f1491b8b63445d4505d5617392ed527  
    
    fix : `user_pref("gfx.x11.glx_sgi_video_sync", true);`


#### Mpv

* Fullscreen freeze
    
    add `gpu-api=opengl` in `mpv.conf`


#### Wayland
    
* Chromium geometry

    https://github.com/labwc/labwc/issues/2327  

* Dialog position

    https://gitlab.xfce.org/xfce/thunar/-/issues/1439  
    
* Popup menu don't close
    
    https://github.com/linuxmint/nemo/issues/3218  
    [https://github.com/linuxmint/nemo/.../eel-gtk-extensions.c](https://github.com/linuxmint/nemo/blob/bfdeba323a63fe3e217b22ca6f4580c785fbe92a/eel/eel-gtk-extensions.c#L255)  
    

#### XFCE

* /usr/share appears twice in XDG_DATA_DIRS
    
    https://gitlab.xfce.org/xfce/xfce4-session/-/issues/111  
    https://gitlab.xfce.org/xfce/xfce4-session/-/issues/50  

* Thunar Leak ThunarFile objects
    
    https://gitlab.xfce.org/xfce/thunar/-/issues/573  

* Xfwm4 Unmaximize
    
    https://gitlab.xfce.org/xfce/xfwm4/-/issues/190  


#### Other

* clang-format
    
    https://github.com/llvm/llvm-project/issues/58300  

* Firmwares warnings

    Warning :
    update-initramfs: Generating /boot/initrd.img-6.1.0-28-amd64
    W: Possible missing firmware

* Nouveau
    
    `nouveau 0000:01:00.0: bus: MMIO read of 00000000 FAULT`
    
    https://bbs.archlinux.org/viewtopic.php?id=288769  
    
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
    
    `sudo update-initramfs -u`

<br/>

