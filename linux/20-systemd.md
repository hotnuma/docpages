<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | [Linux](00-linux.html) | [Xfce](05-xfce.html) | [AVideo](10-avideo.html) | [Network](11-network.html) | Systemd | [Bugs](25-bugs.html) | [Other](99-other.html) ]**

## Systemd

---

#### References

https://www.freedesktop.org/software/systemd/man/systemctl.html  
[https://access.redhat.com/attachments/12052018_systemd_6.pdf](https://access.redhat.com/sites/default/files/attachments/12052018_systemd_6.pdf)  

* Manage services and units
    
    [https://www.digitalocean.com/community/tutorials/](https://www.digitalocean.com/community/tutorials/how-to-use-systemctl-to-manage-systemd-services-and-units-fr)  
    
    `sudo systemctl status application.service`
    
    ```
    sudo systemctl start application.service
    sudo systemctl stop application.service
    ```
    
    ```
    sudo systemctl enable application.service
    sudo systemctl disable application.service
    ```
    
    ```
    sudo systemctl restart application.service
    sudo systemctl reload application.service
    ```

    `sudo systemctl daemon-reload`

* Modify unit file
    
    https://serverfault.com/questions/840996/  
    
    `systemctl edit <service-name>`

* List services
    
    https://askubuntu.com/questions/795226/  
    
    ```
    systemctl list-unit-files --type=service
    systemctl list-unit-files | grep "enabled "
    systemctl --no-pager list-units
    systemctl | grep running
    ```
    
* List timers
    
    `systemctl --no-pager list-timers`


#### Log files

[https://www.golinuxcloud.com/view-logs-using-journalctl-filt](https://www.golinuxcloud.com/view-logs-using-journalctl-filter-journald/)

* journalctl
    
    last 100 lines : `journalctl -b -f --lines=100`
    
    last errors : `journalctl --no-pager -b -p 4`

    last errors : `journalctl --no-pager -b -p err`
    
* Read shutdown log

    `journalctl -b -1 -e`
    
* Using logrotate
    
    [https://journaldunadminlinux.fr/rotation-des-logs-avec-logro](https://journaldunadminlinux.fr/rotation-des-logs-avec-logrotate/)

* Delete old files

    https://unix.stackexchange.com/questions/139513/  

    delete older than 2 days : `sudo journalctl --vacuum-time=2d`

    check result : `sudo du /var/log  -x | sort -nr | head -10`


#### <a name="disable"></a> Turn off excessive logs

* rtkit-daemon
    
    https://unix.stackexchange.com/questions/684379/  
    
    ```
    sudo mkdir /etc/systemd/system/rtkit-daemon.service.d/
    sudo nano /etc/systemd/system/rtkit-daemon.service.d/log.conf
    ```
    
    Add the following :
    
    ```
    [Service]
    LogLevelMax=4
    ```
    
    Reload the service
    
    ```
    sudo systemctl daemon-reload
    sudo systemctl restart rtkit-daemon.service
    ```

* sudo
    
    https://unix.stackexchange.com/questions/224370/  
    https://unix.stackexchange.com/questions/637227/  
    
    `sudo nano /etc/pam.d/sudo`
    
    add the following with the corresponding user name :

    `session [success=1 default=ignore] pam_succeed_if.so quiet uid = 0 ruser = <username>`
    
    Example of `/etc/pam.d/sudo` file :
    
    ```
    #%PAM-1.0

    # Set up user limits from /etc/security/limits.conf.
    session    required   pam_limits.so
    session [success=1 default=ignore] pam_succeed_if.so quiet uid = 0 ruser = hotnuma

    @include common-auth
    @include common-account
    @include common-session-noninteractive
    ```


#### Other

* Analyze startup

    ```
    systemd-analyze
    systemd-analyze --no-pager blame
    systemd-analyze critical-chain
    ```

* Disable gvfs-backends

    using bak from systools : https://github.com/hotnuma/systools

    ```
    sudo bak /usr/share/gvfs/remote-volume-monitors/afc.monitor
    sudo bak /usr/share/gvfs/remote-volume-monitors/goa.monitor
    sudo bak /usr/share/gvfs/remote-volume-monitors/gphoto2.monitor
    sudo bak /usr/share/gvfs/remote-volume-monitors/mtp.monitor
    ```

<br/>

