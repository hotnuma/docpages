<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | [Linux](00-linux.html) | [Xfce](05-xfce.html) | [AVideo](10-avideo.html) | Network | [Systemd](20-systemd.html) | [Bugs](25-bugs.html) | [Other](99-other.html) ]**

## Network

---

#### Firefox

* References
    
    https://wiki.debian.org/Firefox  
    https://wiki.archlinux.org/title/Firefox  
    https://wiki.archlinux.org/title/Firefox/Tweaks  
    
    https://www.mozilla.org/en-US/firefox/releases/  
    [https://support.mozilla.org/en-US/kb/install-firefox-linux](https://support.mozilla.org/en-US/kb/install-firefox-linux#w_system-firefox-installation-for-advanced-users)  
    
* Install from mozilla
    
    https://ftp.mozilla.org/pub/firefox/releases/  
    
    might require dbus-glib : `sudo apt install libdbus-glib-1-2`
    
    ```
    tar xvf firefox-*.tar.xz && sudo mv firefox /opt/
    sudo ln -s /opt/firefox/firefox /usr/local/bin/firefox
    wget https://hotnuma.github.io/docpages/linux/firefox.desktop
    sudo mv ./firefox.desktop /usr/local/share/applications/
    ```
    
    Set new tab and home to a blank page.

* Install icon under Wayland
    
    ```
    sudo mkdir -p /usr/local/share/icons/hicolor/128x128/apps/
    sudo cp /opt/firefox/browser/chrome/icons/default/default128.png \
    /usr/local/share/icons/hicolor/128x128/apps/firefox.png
    sudo update-icon-caches /usr/local/share/icons/*
    sudo sed -i -e 's,/opt/firefox/browser/chrome/icons/default/default128.png,firefox,g' \
    /usr/local/share/applications/firefox.desktop
    ```

* Firefox Fonts
    
    ```
    DejaVu 16 / 15 / 15
    Don't allow web pages...
    Zoom 110 %
    ```
    
* Test Videos
    
    https://www.youtube.com/watch?v=pcSv22DTDUI  
    https://www.youtube.com/watch?v=cuXsupMuik4  
    https://www.youtube.com/watch?v=TVtoxUohG5E  

* Google Web Search
    
    https://www.reddit.com/r/firefox/comments/1kpqv5r/  
    
    ```
    GoogleWeb
    https://www.google.com/search?udm=14&q=%s
    https://suggestqueries.google.com/complete/search?client=firefox&q=%s
    ```

* User Profiles

    https://support.mozilla.org/en-US/kb/profiles-where-firefox-stores-user-data  

    Type `about:profiles` in the address bar.
    
    ```
    ~/.mozilla/firefox/
    ~/.cache/mozilla/firefox/
    ```
    
* Safe Mode
    
    In a terminal : `firefox --safe-mode`

* Turn off ambient mode
    
    https://www.popsci.com/diy/youtube-ambient-mode-off-on/  
    
* Turn off updates
    
    Create a `policies.json` file in `firefox/distribution/` :
    
    ```
    {
        "policies":
        {
            "DisableAppUpdate": true,
            "ManualAppUpdateOnly": true
        }
    }
    ```
    
    ```
    sudo mkdir -p /opt/firefox115esr/distribution/
    sudo cp ./policies.json /opt/firefox115esr/distribution/
    ```


#### Network

* Reference
    
    https://wiki.debian.org/NetworkConfiguration  
    https://wiki.debian.org/NetworkManager  

* Read DNS servers
    
    ```
    cat /etc/resolv.conf
    ls /etc/resolv.conf
    ```

* Change DNS

    https://serverfault.com/questions/810636/  
    
    Get network connection name : `nmcli con`
    
    ```
    nmcli con mod "Wired connection 1" ipv4.dns "8.8.8.8 8.8.4.4"
    nmcli con mod "Wired connection 1" ipv4.ignore-auto-dns yes
    service NetworkManager restart
    cat /etc/resolv.conf
    ```

* Read hostname and domain name
    
    ```
    hostname
    hostname -d
    ```

* Read network configuration
    
    ```
    ip a show eth0
    ip route show default
    networkctl
    networkctl status
    ```
    
    List interfaces : `ls /sys/class/net`
    
* Restart network
    
    ```
    sudo ifdown eth0
    sudo ifup eth0
    ip a show eth0
    ```

    ```
    sudo ip link set dev eth0 down
    sudo ip link set dev eth0 up
    ```
    
    `sudo systemctl restart networking`

* Predictable Network Interface Names
    
    [https://www.freedesktop.org/.../PredictableNetworkInterfaceNames](https://www.freedesktop.org/wiki/Software/systemd/PredictableNetworkInterfaceNames/)  
    
    Switch back to eth0 :
    
    Add `GRUB_CMDLINE_LINUX="net.ifnames=0"` in `/etc/default/grub`
    
    Execute `sudo update-grub`
    
* Set BBox name in hosts file

    `sudo nano /etc/hosts`
    
    append : `192.168.1.254   mabbox.bytel.fr`


#### Switch to /etc/network/interfaces

* Network Interfaces

    check interfaces names : `ifconfig`

    `sudo mv /etc/network/interfaces /etc/network/interfaces.bak`
    
    `sudo nano /etc/network/interfaces`
    
    ```
    auto lo
    iface lo inet loopback

    auto eth0
    iface eth0 inet static
        address 192.168.1.132/24
        netmask 255.255.255.0
        broadcast 192.168.1.255
        gateway 192.168.1.254
        dns-nameservers 8.8.8.8 8.8.4.4
    ```

* Install ifupdown
    
    `sudo apt install ifupdown resolvconf`

* Disable NetworkManager

    ```
    sudo systemctl stop NetworkManager
    sudo systemctl disable NetworkManager
    ```

* Disable systemd-networkd

    check service : `sudo systemctl status systemd-networkd`
    
    ```
    sudo systemctl stop systemd-networkd
    sudo systemctl disable systemd-networkd
    sudo rm /etc/systemd/network/00-eth0.network
    ```

* Enable eth0

    check links : `ls -la /etc/systemd/network/`
    
    `sudo ln -s /dev/null /etc/systemd/network/99-default.link`

* Configure eth0 using ifup :

    `sudo ifup eth0`

* Uninstall network manager

    `sudo apt purge network-manager`


#### Use systemd-networkd

* Use systemd-networkd
    
    [https://linux.fernandocejas.com/docs/...systemd-networkd](https://linux.fernandocejas.com/docs/how-to/switch-from-network-manager-to-systemd-networkd)  
    
    Create a configuration file :
    
    `/etc/systemd/network/00-eth0.network`

    ```
    [Match]
    Name=eth0

    [Network]
    Address=192.168.1.100/24
    Gateway=192.168.1.254
    DNS=8.8.8.8
    DNS=8.8.4.4
    ```
    
    Start services :
    
    ```
    sudo apt install systemd-resolved

    sudo systemctl stop NetworkManager
    sudo systemctl disable NetworkManager

    sudo systemctl enable systemd-networkd

    sudo systemctl enable systemd-resolved
    sudo systemctl start systemd-resolved

    networkctl
    ```

<br/>

