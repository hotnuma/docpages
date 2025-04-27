<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | [Fileman](00-fileman.html) | Core | [Dialog](02-dialog.html) | [Job](03-job.html) | [Libext](04-libext.html) | [Misc](05-misc.html) | [Side](06-side.html) | [View](07-view.html) | [Widget](08-widget.html) | [Other](99-other.html) ]**

## Core

---

#### Files

```
    + core/fileinfo.c
    + core/th_file.c
    + core/th_folder.c
    + core/filemonitor.c
    
    + core/th_device.c
    + core/devmonitor.c
    
    + core/clipboard.c
    + core/dnd.c
    
    + core/appnotify.c
    + core/usermanager.c
```


#### FileInfo

* Description

    A `GTypeInterface` to handle file infos using `GFile` and `GFileInfo`.


#### ThunarFile

* Description

    Implements a `FileInfo` interface. **_th_file_load**
    and **_th_file_info_load** functions load file informations.

* File sorting

    The **th_file_compare_by_name** function calls
    **g_utf8_collate_key_for_filename** to compare file names.


#### ThunarFolder

* Description

    A `GObject` to handle folders, it uses a `ThunarJob`, `ThunarFile`,
    `FileMonitor` and `GFileMonitor`.


#### FileMonitor

* Description

    A global `GObject` to handle file events.


#### ThunarDevice

* Description

    A `GObject` which uses a `GVolume`, `GMount` or `GDrive` to handle devices.


#### DeviceMonitor

* Description

    A global `GObject` to handle device events, it uses `GVolumeMonitor`
    internally. `ThunarDevice`, `TreeModel` and `AppWindow` use it.


#### ClipboardManager

* Description

    A `GObject` to handle cut, copy, paste clipboard operations on files,
    it uses `GtkClipboard` internally.


#### DnD

* Description

    **dnd_ask**
    
    **dnd_perform**


#### app_notify

* Description
    
    Functions to display notification message, `ThunarDevice` uses it
    to display unmount and ejects notifications.


#### UserManager

* Description

    This module provides three objects, a global `UserManager`,
    a `ThunarGroup` and `ThunarUser`. The `PermissionBox` uses it.


<br>


