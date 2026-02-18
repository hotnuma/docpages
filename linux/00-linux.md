<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | Linux | [Xfce](05-xfce.html) | [AVideo](10-avideo.html) | [Network](11-network.html) | [Systemd](20-systemd.html) | [Bugs](25-bugs.html) | [Other](99-other.html) ]**

## Docs Linux

---

#### References

https://wiki.debian.org/FrontPage  
https://wiki.debian.org/HardwareVideoAcceleration  


#### System

* Aliases
    
    list aliases : `alias`  
    aliases file : `~/.bash_aliases`  
    example : `alias cgrep='grep -rni --include=*.{h,c,cpp,cxx}'`  

* Alternatives
    
    https://wiki.debian.org/DebianAlternatives  
    
    list alternatives : `update-alternatives --get-selections`  
    list choices : `update-alternatives --list x-cursor-theme`  
    
    default session : `sudo update-alternatives --config x-session-manager`  
    default terminal : `sudo update-alternatives --config x-terminal-emulator`  
    
* Boot target

    ```
    sudo systemctl get-default
    sudo systemctl set-default graphical.target
    ```

* Environment variables
    
    https://wiki.archlinux.org/title/environment_variables  
    https://askubuntu.com/questions/866161/  
    https://askubuntu.com/questions/60218/  
    
    ```
    /etc/environment
    $HOME/.profile
    /etc/profile
    ```

* grub.conf
    
    https://askubuntu.com/questions/575651/  
    
    edit config : `/etc/default/grub`  
    update : `sudo update-grub`  

* Locale
    
    https://wiki.archlinux.org/title/locale
    
    `/etc/default/locale`
    
* pkexec
    
    https://unix.stackexchange.com/questions/203136/  
    https://askubuntu.com/questions/608419/  
    
* Reboot / Halt System
    
    ```
    systemctl reboot
    systemctl poweroff
    ```

* System Infos

    `inxi -b`  
    `glxinfo | egrep "OpenGL vendor|OpenGL renderer"`  
    `vainfo`

* System CPU usage
    
    `top -n2`
      
    `ps -Ao user,uid,comm,pid,pcpu --sort=-pcpu | head -n 11`

* System memory usage
    
    `top -n 2 -o %MEM`
    
* User's groups
    
    `groups username`


#### Install

* Source list
    
    `/etc/apt/sources.list`

* Check if reboot is needed
    
    https://askubuntu.com/questions/164/  

* Check which packages can be uodated
    
    `sudo apt update && apt list --upgradable`

* Enable non-free-firmware
    
    [https://www.linuxtricks.fr/wiki](https://www.linuxtricks.fr/wiki/debian-configurer-les-sources-activer-non-free-et-contrib)  

* Find the package that provides a file
    
    https://askubuntu.com/questions/481/  
    
    `dpkg -S /bin/ls`

* Get package version

    `dpkg -l libgtk-3-0 | grep ^ii`

* Get source of package
    
    [https://www.cyberciti.biz/faq/how-to-get-source...](https://www.cyberciti.biz/faq/how-to-get-source-code-of-package-using-the-apt-command-on-debian-or-ubuntu/)  
    
    check if `deb-src` is enabled : `cat /etc/apt/sources.list`
    
    ```
    sudo apt update
    apt source <package>
    ```

* List broken packages
    
    https://askubuntu.com/questions/772653/  
    
    `dpkg -l | grep ^..r `

* List dependencies
    
    https://askubuntu.com/questions/80655/  
    
    `apt-cache depends <package>`

    `apt-cache rdepends <package>`
    
    `apt-cache rdepends --installed <package>`

* List files from a package
    
    https://serverfault.com/questions/96964/  
    https://askubuntu.com/questions/32507/  
    
    `dpkg -L <package>`
    
    `dpkg-query -L <package_name>`

* List installed packages
    
    `dpkg -l`
    
    `dpkg -l | grep thunar`
    
    `apt list thunar`
    
    `apt list --installed | grep glib`
    
* List obsolete packages
    
    https://www.guyrutenberg.com/2022/03/19/list-obsolete-packages-using-apt/  
    
    `apt list ?obsolete`

* Purge Apt Cache

    `sudo apt clean; sudo apt autoclean`

* Remove useless packages

    `sudo apt autopurge`

* Search package name

    `apt search thunar`

* System upgrade

    `sudo apt update && sudo apt upgrade`
    
    or
    
    `sudo apt update && sudo apt full-upgrade`


#### Drives

* Check drive spin down

    https://superuser.com/questions/173622/  
    
    `hdparm -C /dev/sdX`

* Eject USB drives
    
    https://unix.stackexchange.com/questions/35508/  
    
    `sudo eject /dev/sdX`

* Power Off Drive
    
    https://askubuntu.com/questions/671683/  
    https://forum.manjaro.org/t/eject-external-hard-drive-option-gone/61895/6  
    
    `udisksctl power-off -b /dev/sdX`

* Read smart infos

    `sudo smartctl -s on -a /dev/sdX`
    
* I/O test
    
    [https://www.cyberciti.biz/howto-test-disk-performance...](https://www.cyberciti.biz/faq/howto-linux-unix-test-disk-performance-with-dd-command/)  
    
    `dd if=/dev/zero of=/tmp/test1.img bs=1G count=1 oflag=dsync`
    
* Write an img file to a drive using systools

    https://github.com/hotnuma/systools  
    
    ```
    lsblk -p
    sudo umount /dev/sdX?
    rpimg "file.img" /dev/sdX
    ```

* Write Debian Iso
    
    ```
    lsblk -p
    sudo umount /dev/sdX?
    sudo cp "debian.iso" /dev/sdX
    sync
    ```

#### Drives Partitions

* Delete all partitions

    https://serverfault.com/questions/250839/  
    
    `sudo dd if=/dev/zero of=/dev/sdX bs=512 count=1 conv=notrunc`

* Fix NTFS partition
    
    `sudo ntfsfix /dev/sdX1`

* Format `/dev/sdX1` in Ext4

    ```
    lsblk -p
    sudo umount /dev/sdX1
    sudo mkfs.ext4 -L "Backup" /dev/sdX1
    sudo chown $USER:$USER /media/$USER/Backup
    ```
    
* Format `/dev/sdX1` in NTFS

    ```
    lsblk -p
    sudo umount /dev/sdX1
    sudo mkfs.ntfs -f -L "Backup" /dev/sdX1
    ```

* Read UUID

    `sudo blkid`

* Rename NTFS partition
    
    `sudo ntfslabel -f /dev/sdX1 Backup1`

* Unmount all

    `umount /dev/sdX?`
    

#### Directories

* Top Directories
    
    [https://www.cyberciti.biz/faq/how-do-i-find-the-largest-file](https://www.cyberciti.biz/faq/how-do-i-find-the-largest-filesdirectories-on-a-linuxunixbsd-filesystem/)  
    
    `sudo du / -xam --max-depth=2 2>/dev/null | sort -nr | head -20`  
    `sudo du / -ham 2>/dev/null | sort -nr | head -n 20`  
    
* Compress a directory with 7zip

    `7z a example.7z example/`
    
    without compression :

    `7z a -mx=0 example.7z example/`
    
* Delete empty directories
    
    https://unix.stackexchange.com/questions/46322/  
    
    To check : `find . -type d -empty -print`

    To delete : `find . -type d -empty -delete`

* Recursive grep

    https://stackoverflow.com/questions/12516937/
    
    `grep -r "texthere" .`
    
    `grep -rni --include=*.{h,c,cpp,cxx} "texthere"`
    

#### Files

* Change file owner
    
    `sudo chown $USER:$USER <filepath>`

* Check opened files
    
    https://linuxhint.com/check-open-files-in-linux/  

* Create a symbolic link

    `ln -s target_path link_name`

* Find and convert files to unix eol
    
    `find . -type f -print0 | xargs -0 dos2unix`

* Find biggest files in directory
    
    `find . -type f -printf "%s\t%p\n" | sort -nr | head -10`

* Find files not own by user

    `find ~ ! -user $USER -o ! -group $USER`
    
* Find ignore errors
    
    `find / -name *.html 2>/dev/null`
    
* Find last modified files

    `find ~ -cmin -5`

* Find multiple pattern
    
    `find . -type f -name "*.h" -o -name "*.c"`
    
* Remove execute flag
    
    `find . -type f -exec chmod -x {} \;`

* Remove presentation mode in PDFs
    
    https://unix.stackexchange.com/questions/754414/  


#### Edit files

* Edit config files
    
    https://unix.stackexchange.com/questions/642578/  
    
    `sed 's/^GRUB_TIMEOUT=.*/GRUB_TIMEOUT=0/' input.txt > output.txt`

* Extract lines
    
    ```
    sed -n \
    -e '/^\[Desktop Entry\]/p' \
    -e '/^Name=/p' \
    -e '/^Exec=/p' \
    -e '/^Type=/p' \
    /usr/share/applications/firefox.desktop
    ```

* Format text file to a specific line length
    
    https://unix.stackexchange.com/questions/146089/  
    
    `fmt --width=120 input.txt > output.txt`

* Merge text files
    
    https://unix.stackexchange.com/questions/3770/  
    
    `cat ./* > ../result.txt`
    
* Replace end of lines
    
    https://stackoverflow.com/questions/1251999/  
    
    `sed -z 's/\n\n/\n/g' input.txt > output.txt`  
    `sed -z 's/\n\n*/\n/g' input.txt > output.txt`  
    `sed -z -e 's/\n\n*/\n/g' -e 's/ \n/\n/g' input.txt > output.txt`

* Replace multiple spaces
    
    https://superuser.com/questions/241018/  
    
    <code>sed 's/&nbsp;&nbsp;&#42;/ /g' input.txt > output.txt</code>  
    <code>sed 's/&nbsp;&nbsp;&#42;/\t/g' input.txt > output.txt</code>  


#### Programs

* Additional programs

    ```
    aria2
    datamash
    evince
    exiv2
    freefilesync
    gnuplot
    greybird-gtk-theme
    libgd-dev
    lz4json
    mupdf
    plotutils
    sigil
    uchardet
    vainfo
    xfce4-screenshooter
    ```

* bash
    
    https://ss64.com/bash/syntax-keyboard.html  

* batocera
    
    https://www.reddit.com/r/batocera/comments/14kii1n/batocera_keyboard_hotkey_list/  

* libreoffice

    convert csv to odt : `soffice --convert-to ods example.csv --headless`  
    go to page : `Shift+Ctrl+F5`

* mpv
    
    https://mpv.io/manual/master/  

* rofi
    
    delete entry : type shift+delete on the entry

* zathura

    https://www.maketecheasier.com/cheatsheet/zathura-keyboard-shortcuts/  
    https://unix.stackexchange.com/questions/497737/  

    copy to clipboard : https://unix.stackexchange.com/questions/339487/  
    
    go to page 10 : `10GG`  
    got to previous : `Ctrl+O`  
    got to next : `Ctrl+I`  


#### Misc

* Copy to clipboard
    
    https://stackoverflow.com/questions/5130968/  

* Datamash examples
    
    https://linuxcommandlibrary.com/man/datamash  
    
    alias : `alias datamash='LC_ALL=C datamash'`
    
    `datamash -R 2 mean 1 mean 2 mean 3 < ff_138_4.txt`
    
* Delete thumbnails older than 30 days

    `find ~/.cache/thumbnails/ -type f -iname \*.png -mtime +30 -delete`

* Get installation date
    
    `stat -c %w /`

* Output command without localization

    `LC_ALL=C free -h`
    
* Switch to non-graphical
    
    https://superuser.com/questions/100693/  

    console : `Ctrl+Alt+F1`  
    graphical : `Ctrl+Alt+F7`  

* Using Wget with Cookies
    
    [https://www.apharmony.com/software-sagacity/](https://www.apharmony.com/software-sagacity/2014/10/using-wget-with-cookies/)  

<br/>

