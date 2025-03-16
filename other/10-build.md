<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | Build ]**

## Build

---

* labwc

    https://github.com/labwc/labwc?tab=readme-ov-file#2-build-and-installation  
    (depends on wlroots-0.18)

    ```
    builddep libwlroots-0.18

    sudo apt install \
    dpkg-dev \
    glslang-tools \
    hwdata \
    libcap-dev \
    libcairo2-dev \
    libdisplay-info-dev \
    libdrm-dev \
    libegl1-mesa-dev \
    libegl-dev \
    libgbm-dev \
    libgles2-mesa-dev \
    libinput-dev \
    liblcms2-dev \
    libliftoff-dev \
    libpixman-1-dev \
    libpng-dev \
    libseat-dev \
    libsystemd-dev \
    libvulkan-dev \
    libwayland-dev \
    pkgconf \
    wayland-protocols \
    ```

    ```
    git clone https://github.com/labwc/labwc.git && cd labwc
    meson setup build -Dxwayland=disabled
    meson compile -C build
    sudo meson install -C build
    ```
    
    wlroots 0.19.0-dev

    ```
        drm-backend      : YES
        x11-backend      : NO
        libinput-backend : YES
        xwayland         : NO
        gles2-renderer   : YES
        vulkan-renderer  : YES
        gbm-allocator    : YES
        udmabuf-allocator: YES
        session          : YES
        color-management : YES
        xcb-errors       : NO
        egl              : YES
        libliftoff       : YES

      User defined options
        examples         : false
        xwayland         : disabled
    ```

<!--

* libsfdo

    https://gitlab.freedesktop.org/vyivel/libsfdo  
    
    ```
    git clone https://gitlab.freedesktop.org/vyivel/libsfdo.git
    cd libsfdo
    meson setup build
    meson compile -C build
    sudo meson install -C build
    ```

* wlroots

    https://gitlab.freedesktop.org/wlroots/wlroots  
    https://packages.debian.org/trixie/libwlroots-0.18  

    ```
    git clone https://gitlab.freedesktop.org/wlroots/wlroots.git && cd wlroots
    meson setup build -Dexamples=false -Dxwayland=disabled
    ```

    ```
    meson compile -C build
    sudo meson install -C build
    ```
-->

<br/>


