<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | [Linux](00-linux.html) | [Xfce](05-xfce.html) | [Network](10-network.html) | [FFmpeg](15-ffmpeg.html) | [Systemd](20-systemd.html) | [Bugs](25-bugs.html) | Other ]**

## Other

---

#### Benchmarks

* N100

    https://www.cpubenchmark.net/cpu.php?cpu=Intel+N100&id=5157  

* Athlon 200GE

    https://www.cpubenchmark.net/cpu.php?cpu=AMD+Athlon+200GE&id=3325  

* BCM2712
    
    https://www.cpubenchmark.net/cpu.php?cpu=BCM2712&id=6054  

* i3-6006U
    
    https://www.cpubenchmark.net/cpu.php?cpu=Intel+Core+i3-6006U+%40+2.00GHz  

* BCM2711
    
    https://www.cpubenchmark.net/cpu.php?cpu=BCM2711&id=4297  

    
#### System Processes on Debian 12

https://debian-facile.org/viewtopic.php?pid=254022#p254022  

* agetty
    
    https://man.archlinux.org/man/agetty.8.en  
    
    Ctrl+Alt+F1 terminal started by getty@tty1 service :
    
    `systemctl status getty@tty1`
    
    mem : 358

* dbus-daemon
    
    System bus, two processes.
    
    mem : 2378

* gvfsd gvfsd-metadata gvfsd-trash
    
    Virtual file system.
    
    mem : 3623 + 3011 + 4035

* gvfs-udisks2-volume-monitor
    
    mem : 5571

* init
    
    mem : 3831

* polkitd polkit-gnome-authentication-agent-1
    
    https://www.freedesktop.org/software/polkit/docs/latest/polkit.8.html  
    https://wiki.archlinux.org/title/Polkit  
    
    Polkit is used for controlling system-wide privileges. It provides an organized way for non-privileged processes to communicate with privileged ones. In contrast to systems such as sudo, it does not grant root permission to an entire process, but rather allows a finer level of control of centralized system policy.
    
    mem : 2884 + 5509

* rtkit-daemon
    
    Realtime Kit enables realtime scheduling for the PulseAudio daemon.
    
    mem : 511

* (sd-pam)
    
    https://www.reddit.com/r/linuxquestions/comments/n6akxv/  
    
    The sole purpose of this process is to wait for the service to terminate and to perform the "close PAM session" operations when that occurs.
    
    mem : 2239

* ssh-agent
    
    https://docs.xfce.org/xfce/xfce4-session/advanced#ssh_and_gpg_agents  
    
    mem : 1074

* systemd
    
    mem : 3760

* systemd-journald
    
    mem : 13752

* systemd-logind
    
    https://www.freedesktop.org/software/systemd/man/systemd-logind.service.html  
    
    A system service that manages user logins.
    
    mem : 2584

* systemd-timesyncd
    
    mem : 1826

* systemd-udevd
    
    https://linuxembedded.fr/2018/03/kernel-udev-et-systemd-la-gestion-du-hotplug  
    
    `systemd-udevd` listens to kernel uevents. For every event, systemd-udevd executes matching instructions specified in udev rules.
    
    mem : 4150

* udisksd
    
    https://wiki.archlinux.org/title/udisks  
    
    udisks provides a daemon udisksd, that implements D-Bus interfaces used to query and manipulate storage devices, and a command-line tool udisksctl, used to query and use the daemon.
    
    mem : 10203

* upowerd
    
    https://upower.freedesktop.org/  
    https://www.cyberciti.biz/faq/linux-upower-command-examples-and-syntax/  
    
    UPower is an abstraction for enumerating power devices, listening to device events and querying history and statistics. Any application or service on the system can access the org.freedesktop.UPower service via the system message bus.
    
    mem : 3546


#### More System Processes on Ubuntu

* accounts-daemon
    
    https://www.freedesktop.org/wiki/Software/AccountsService/  
    
    AccountsService is a D-Bus service for accessing the list of user accounts and information attached to those accounts.
    
    mem : 1604

* acpid
    
    https://wiki.archlinux.org/title/acpid  
    
    A flexible and extensible daemon for delivering ACPI events. When an event occurs, it executes programs to handle the event.
    
    mem : 261

* gnome-keyring-daemon
    
    https://wiki.archlinux.org/title/GNOME/Keyring  
    https://docs.xfce.org/xfce/xfce4-session/advanced#ssh_and_gpg_agents  
    
    GNOME Keyring is a collection of components that store secrets, passwords, keys, certificates and make them available to applications.
    
    directory : `~/.local/share/keyrings`
    
    mem : 2637

* irqbalance
    
    https://linux.die.net/man/1/irqbalance  
    
    Distribute hardware interrupts across processors on a multiprocessor system.
    
    mem : 563

<br/>


