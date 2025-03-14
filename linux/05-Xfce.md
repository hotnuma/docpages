<link href="style.css" rel="stylesheet"></link>

**[ [Home](00-Home.html) | Xfce | [Network](10-Network.html) | [FFmpeg](15-FFmpeg.html) | [Systemd](20-Systemd.html) | [Bugs](25-Bugs.html) | [Other](99-Other.html) ]**

## Xfce

---

#### Reference

* Links
    
    https://wiki.xfce.org/start  
    https://wiki.archlinux.org/title/xfce  
    https://wiki.xfce.org/releng/wayland_roadmap  
    
    [https://forum.xfce.org/](https://forum.xfce.org/search.php?action=show_recent)  
    https://gitlab.xfce.org/xfce  
    https://gitlab.xfce.org/apps  
    https://developer.xfce.org/  

* Xfce Dialogs
    
    | Command                   | Description               |
    | :------------------------ | :------------------------ |
    | xfce4-settings-manager    | Configuration Panel       |
    | xfce4-mime-settings       | Default Apps              |
    | xfce4-keyboard-settings   | Keyboard Settings         |
    | xfce4-mouse-settings      | Mouse Settings            |
    | xfce4-notifyd-config      | Notifications Settings    |
    | xfce4-panel --preferences | Panel Preferences         |
    | xfce4-session-settings    | Session Settings          |
    | xfce4-settings-editor     | Xfconf Editor             |
    | xfce4-appearance-settings | Appearance                |
    | xfce4-display-settings    | Display Settings          |
    | xfwm4-settings            | Window Manager Settings   |
    | xfwm4-tweaks-settings     | Window Manager Tweaks     |
    

#### System Startup

* systemd

    ```
    /sbin/ini
        dbus-demon
        lightdm
            /usr/share/xsessions/lightdm-xsession.desktop
                startxfce4
                    Xorg
            lightdm --session-child
                xfce4-session
        agetty
        systemd/systemd --user
    ```

* lightdm

    show config : `lightdm --show-config`
    
    list sessions : `ls /usr/share/xsessions/`

    current session : `cat ~/.dmrc`

    ```
    [Desktop]
    Session=lightdm-xsession
    ```

    session file : `/usr/share/xsessions/lightdm-xsession.desktop`

    ```
    [Desktop Entry]
    Version=1.0
    Name=Default Xsession
    Exec=default
    Icon=
    Type=Application
    ```
    
    `Exec=default` means that the session is defined in alternatives :
    
    `update-alternatives --config x-session-manager`
    
    ```
    ------------------------------------------------------------
    * 0            /usr/bin/startxfce4      50        mode automatique
      1            /usr/bin/startxfce4      50        mode manuel
      2            /usr/bin/xfce4-session   40        mode manuel

    ```
    
* xfce4-session
    
    https://docs.xfce.org/xfce/xfce4-session/advanced  

* Bash Startup Files
    
    [https://www.linuxfromscratch.org/blfs/view/11.0/postlfs/prof](https://www.linuxfromscratch.org/blfs/view/11.0/postlfs/profile.html)  

* Xsession xdg paths
    
    https://askubuntu.com/questions/1179729/  


#### Configuration

* XFCE Config
    
    ```
    $HOME/.config/xfce4/
    /etc/xdg/xfce4/
    ```

    keyboard : `/etc/xdg/xfce4/xfconf/xfce-perchannel-xml/xfce4-keyboard-shortcuts.xml`  
    xfce4-session : `/etc/xdg/xfce4/xfconf/xfce-perchannel-xml/xfce4-session.xml`  
    xsettings : `/etc/xdg/xfce4/xfconf/xfce-perchannel-xml/xsettings.xml`  

* xfconf-query
    
    https://docs.xfce.org/xfce/xfconf/xfconf-query  
    [http://manpages.ubuntu.com/manpages/...](http://manpages.ubuntu.com/manpages/bionic/man1/xfconf-query.1.html)  

* Xdg menu
    
    `/etc/xdg/menus/xfce-applications.menu`

* Disable CSD
    
    https://forum.xfce.org/viewtopic.php?pid=77880#p77880  


#### Applications

* Launchers

    ```
    $HOME/.local/share/applications/
    /usr/local/share/applications/
    /usr/share/applications/
    ```

* File associations
    
    https://wiki.debian.org/MIME  
    https://wiki.debian.org/MimeTypesSupport  
    https://wiki.archlinux.org/title/XDG_MIME_Applications  
    https://unix.stackexchange.com/questions/507943/  
    https://unix.stackexchange.com/questions/114075/  
    https://stackoverflow.com/questions/2227182/  

    mime cache : `/usr/share/applications/mimeinfo.cache`  
    default apps : `$HOME/.config/mimeapps.list`  
    
    regenerate mimeinfo.cache files :
    
    global files : `update-desktop-database`  
    in user dir : `update-desktop-database ~/.local/share/applications`  

* Default applications

    ```
    $HOME/.config/xfce4/helpers.rc
    /etc/xdg/xfce4/helpers.rc
    ```

#### Themes

* Location
    
    `$HOME/.themes/`

* Change desktop background

    Solid color : `hsetroot -solid '#5e5c64'`  
    
    Walpaper : `feh --bg-scale /usr/share/rpd-wallpaper/clouds.jpg`  
    
    Random walpaper : `feh --bg-scale --randomize /usr/share/rpd-wallpaper/`  

* Wallpapers

    system :
    
    ```
    /usr/share/backgrounds/
    ```
    
    xfce :
    
    ```
    $HOME/.local/share/xfce4/backdrops/
    /usr/share/xfce4/backdrops/
    /usr/share/xfce4/backdrops/xfce/
    ```


#### Other

* Center window
    
    https://superuser.com/questions/141032/  
    
    `Alt+F7`

* Thunar Custom Actions
    
    https://docs.xfce.org/xfce/thunar/4.12/custom-actions  
    https://forum.xfce.org/viewtopic.php?id=12633  
    
    `xfce4-terminal -e 'bash -c "extract.sh %f; bash"'`


