<link href="style.css" rel="stylesheet"></link>

**[ [Home](00-Home.html) | Build | [Git](10-Git.html) | [Bash](15-Bash.html) | [Py](20-Python.html) | [Cpp](25-Cpp.html) | [Gtk](30-Gtk.html) | [Other](99-Other.html) ]**

## Build

---

#### References

https://wiki.debian.org/BuildingTutorial  


#### Gcc

* simple commands

    https://ioflood.com/blog/gcc-linux-command/  
    
    `gcc -o simple simple.c $(pkg-config --cflags --libs gtk+-3.0)`  
    
    using systools : `cbuild simple simple.c gtk+-3.0`  


#### Autotools
    
* Install release version
    
    https://stackoverflow.com/questions/4553735/  
    
    `./autogen.sh --prefix=/usr/local --enable-debug=no`
    
    or
    
    `./configure --prefix=/usr/local --enable-debug=no`
    
    and
    
    `make -j 4`
    
    `sudo make install-strip`


#### Meson

* Basics
    
    https://mesonbuild.com/IndepthTutorial.html  
    https://mesonbuild.com/Fs-module.html  

* Include a pre-compiled library
    
    https://stackoverflow.com/questions/67925406/  

* Resolve home directory
    
    [https://github.com/mesonbuild/meson/issues/6318](https://github.com/mesonbuild/meson/issues/6318#issuecomment-563965061)  
    
    ```
    fs = import('fs')
    config_dir = fs.expanduser('~/.config')
    install_subdir('assets', install_dir: config_dir)
    ```

* Porting projects
    
    [porting-from-autotools](https://mesonbuild.com/Porting-from-autotools.html)  
    [convert-autotools](https://nibblestew.blogspot.com/2016/09/how-to-convert-autotools-project-to.html)  
    [meson-tools](https://github.com/mesonbuild/meson/tree/master/tools)  

* Examples
    
    [viewnior](https://github.com/hellosiyan/Viewnior)  
    [desktop-files-creator](https://github.com/alexkdeveloper/desktop-files-creator)  
    [krishenriksen-pibright](https://github.com/krishenriksen/pibright/blob/master/meson.build)  
    [gsettings-schema](https://discourse.gnome.org/t/installing-gsettings-schema-with-meson/13373)  


#### Dependencies

* Find build dependencies

    https://askubuntu.com/questions/172367/  
    https://askubuntu.com/questions/481/  
    https://www.cyberciti.biz/faq/equivalent-of-rpm-qf-command/  
    [https://www.linuxuprising.com/2018/11/](https://www.linuxuprising.com/2018/11/how-to-find-package-that-provides-file.html)  
    
    installed : `apt-cache showsrc xfwm4 | grep '^Build-Depends'`  
    
    not installed : `apt-file search a_file.pc`  
    
    `apt build-dep --dry-run xfwm4`  
    
    `apt search xfwm4`  
    
* Find linked libraries

    https://unix.stackexchange.com/questions/120015/  
    
* Fix library error

    `sudo /sbin/ldconfig -v`

* pkg-config

    `pkg-config --cflags --libs gtk+-3.0`
    
    version : `pkg-config --modversion glib-2.0`

* Common Dev Packages

    | Package Name            | PkgConfig               |
    | :---------------------- | :---------------------- |
    | gettext                 |                         |
    | libdbus-1-dev           | dbus-1                  |
    | libexo-2-dev            | exo-2                   |
    | libexpat1-dev           | expat                   |
    | libgdk-pixbuf-2.0-dev   | gdk-pixbuf-2.0          |
    | libglib2.0-dev          | glib-2.0                |
    | libgtk2.0-dev           | gtk+-2.0                |
    | libgtk-3-dev            | gtk+-3.0                |
    | libgumbo-dev            | gumbo                   |
    | libmount-dev            | mount                   |
    | libnotify-dev           | libnotify               |
    | libpcre3-dev (pcre)     | libpcre                 |
    | libpcre2-dev (pcre2)    | libpcre2-8              |
    | libpng-dev              | libpng                  |
    | libpolkit-gobject-1-dev | polkit-gobject-1        |
    | libtinyxml-dev          | tinyxml                 |
    | libusb-dev              | libusb                  |
    | libwnck-3-dev           | libwnck-3.0             |
    | libx11-dev              | x11                     |
    | libxfce4ui-2-dev        | libxfce4ui-2            |
    | libxfce4util-dev        | libxfce4util-1.0        |
    | libxfconf-0-dev         | libxfconf-0             |
    | libxml2-dev             | libxml-2.0              |
    | libz3-dev               | z3                      |
    | libzen-dev              | libzen                  |

<br/>

