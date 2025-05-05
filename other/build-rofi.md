<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | [Build](15-build.html) ]**

## Rofi

---

* rofi

    ```
    git clone https://github.com/lbonn/rofi.git && cd rofi
    meson setup build -Dcheck=disabled -Dxcb=disabled
    meson compile -C build
    sudo meson install -C build
    ```

<br/>
