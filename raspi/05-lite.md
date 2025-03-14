<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | Lite ]**

### Raspi OS Lite

---

#### Install XFCE

* Copy image

    *replace sdX with the corresponding device, for example sdc*

    ```
    unxz ./raspios64-lite.img.xz
    lsblk
    umount /dev/sdX?
    rpimg ./raspios64-lite.img /dev/sdX
    ```

    configure and upgrade :

    ```
    sudo raspi-config
    (change locale and timezone)
    sudo apt update && sudo apt upgrade
    reboot
    ```


