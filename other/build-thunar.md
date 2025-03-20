<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | [Build](10-build.html) ]**

## Thunar

---

* thunar

    ```
    sudo apt install \
    gettext libexif-dev libexo-2-dev libglib2.0-dev libgtk-3-dev \
    libgudev-1.0-dev libjpeg-dev libnotify-dev libpcre2-dev \
    libxfce4panel-2.0-dev libxfce4ui-2-dev libxfce4util-dev libxfconf-0-dev \
    xfce4-dev-tools gtk-doc-tools autopoint
    ```
    ```
    git clone https://gitlab.xfce.org/xfce/thunar && cd thunar
    git checkout <branch|tag>
    ```
    
    with autotools
    
    ```
    ./autogen.sh
    LANG=C make -j 4
    sudo make install
    ```

    with meson
    
    ```
    meson setup build -Dbuildtype=release -Dintrospection=false \
    -Dvisibility=false
    meson compile -C build
    sudo meson install -C build
    ```
    
<br/>

