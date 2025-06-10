<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | [Build](15-build.html) ]**

## Labwc

---

* libsfdo
    
    https://gitlab.freedesktop.org/vyivel/libsfdo  
    
    ```
    git clone https://gitlab.freedesktop.org/vyivel/libsfdo.git
    cd libsfdo
    git checkout v0.1.3
    meson setup build -Dbuildtype=release -Dexamples=false -Dtests=false
    meson compile -C build
    sudo meson install -C build
    ```

* wlroots
    
    https://gitlab.freedesktop.org/wlroots  
    
    ```
    cdeps libwlroots-0.18

    sudo apt install \
    dpkg-dev glslang-tools hwdata libcap-dev libcairo2-dev \
    libdisplay-info-dev libdrm-dev libegl1-mesa-dev libegl-dev libgbm-dev \
    libgles2-mesa-dev libinput-dev liblcms2-dev libliftoff-dev \
    libpixman-1-dev libpng-dev libseat-dev libsystemd-dev libvulkan-dev \
    libwayland-dev pkgconf wayland-protocols
    ```

    ```
    git clone https://gitlab.freedesktop.org/wlroots/wlroots.git
    cd wlroots
    git checkout 0.18
    meson setup build -Dbuildtype=release \
    -Dxcb-errors=disabled -Dxwayland=disabled -Dexamples=false
    ```
    
    ```
    wlroots 0.18.2

    drm-backend     : YES
    x11-backend     : NO
    libinput-backend: YES
    xwayland        : NO
    gles2-renderer  : YES
    vulkan-renderer : YES
    gbm-allocator   : YES
    session         : YES
    color-management: YES
    xcb-errors      : NO
    egl             : YES
    libliftoff      : YES

  User defined options
    buildtype       : release
    examples        : false
    xcb-errors      : disabled
    xwayland        : disabled
    ```
    
    ```
    meson compile -C build
    sudo meson install -C build
    ```
    
* labwc

    https://github.com/labwc/labwc?tab=readme-ov-file#2-build-and-installation  
    (depends on wlroots-0.18)

    ```
    git clone https://github.com/labwc/labwc.git
    cd labwc
    meson setup build --wrap-mode=nodownload -Dbuildtype=release \
    -Dxwayland=disabled
    meson compile -C build
    sudo meson install -C build
    ```
    
    `sudo /sbin/ldconfig -v`

* labwc-tweaks-gtk

    ```
    git clone https://github.com/labwc/labwc-tweaks-gtk.git
    cd labwc-tweaks-gtk
    meson setup build -Dbuildtype=release
    meson compile -C build
    sudo meson install -C build
    ```

<br/>


