<link href="style.css" rel="stylesheet"></link>

**[ [Home](00-Home.html) | Core | [Dialog](02-Dialog.html) | [Job](03-Job.html) | [Libext](04-Libext.html) | [Misc](05-Misc.html) | [Side](06-Side.html) | [View](07-View.html) | [Widget](08-Widget.html) | [Other](99-Other.html) ]**

## Core

---

#### Files

```
    + core/appnotify.c
    + core/clipboard.c
    + core/dnd.c
    + core/user.c
    
    + core/devmonitor.c
    + core/th_device.c
    
    + core/filemonitor.c
    + core/th_folder.c
    + core/th_file.c
    + core/fileinfo.c
```


#### app_notify

* Description
    
    Functions to display notification message, ThunarDevice uses it
    to display unmount and ejects notifications.


#### ClipboardManager

* Description

    A GObject to handle cut, copy, paste clipboard operations on files,
    it uses GtkClipboard internally.


#### DnD

* Description

    dnd_ask
    
    dnd_perform


#### User

* Description

    This module provides three objects, a global UserManager,
    a ThunarGroup and ThunarUser. The PermissionBox uses it.


#### DeviceMonitor

* Description

    A global GObject to handle device events, it uses GVolumeMonitor
    internally. ThunarDevice, TreeModel and Window use it.


#### ThunarDevice

* Description

    A GObject which uses a GVolume, GMount or GDrive to handle devices.


#### FileMonitor

* Description

    A global GObject to handle file events.


#### ThunarFolder

* Description

    A GObject to handle folders which uses a ThunarJob, ThunarFile,
    FileMonitor and GFileMonitor.


#### FileInfo

* Description

    A GTypeInterface to handle file infos using GFile and GFileInfo.


#### ThunarFile

* Description

    An implementation of FileInfo. _th_file_load and _th_file_info_load functions
    load these informations.

* File sorting

    The th_file_compare_by_name function calls g_utf8_collate_key_for_filename
    to compare file names.


<br>
<br>
<br>


