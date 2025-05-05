<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | [Build](15-build.html) ]**

## XFCE

---

```
sudo apt install \
gettext libexif-dev libexo-2-dev libgtk-3-dev \
libgudev-1.0-dev libjpeg-dev libnotify-dev libpcre2-dev \
libxfce4panel-2.0-dev libxfce4ui-2-dev libxfce4util-dev libxfconf-0-dev \
xfce4-dev-tools gtk-doc-tools
```

#### Thunar

* xfce4ui

    https://gitlab.xfce.org/xfce/libxfce4ui  
    
    ```
    git clone https://gitlab.xfce.org/xfce/libxfce4ui.git
    cd libxfce4ui
    meson setup build -Dbuildtype=release \
    -Dintrospection=false -Dvisibility=false
    meson compile -C build
    sudo meson install -C build
    ```
    
    `thunar: symbol lookup error: thunar: undefined symbol: xfce_icon_view_new`

* thunar
    
    https://gitlab.xfce.org/xfce/thunar  

    ```
    git clone https://gitlab.xfce.org/xfce/thunar
    cd thunar
    git checkout <branch|tag>
    ```
    
    ```
    meson setup build -Dbuildtype=release \
    -Dintrospection=false -Dvisibility=false
    meson compile -C build
    sudo meson install -C build
    ```


#### libxfce4windowing

* wlr-protocols

    https://gitlab.freedesktop.org/wlroots/wlr-protocols  

    ```
    git clone https://gitlab.freedesktop.org/wlroots/wlr-protocols.git
    cd wlr-protocols
    make && sudo make install
    ```

* libxfce4windowing

    https://gitlab.xfce.org/xfce/libxfce4windowing  

    ```
    git clone https://gitlab.xfce.org/xfce/libxfce4windowing.git
    cd libxfce4windowing
    meson setup build -Dbuildtype=release \
    -Dintrospection=false -Dvisibility=false -Dtests=false
    meson compile -C build
    sudo meson install -C build
    ```

    `sudo /sbin/ldconfig -v`

<br/>


