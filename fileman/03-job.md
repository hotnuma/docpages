<link href="style.css" rel="stylesheet"></link>

**[ [Home](00-Home.html) | [Core](01-Core.html) | [Dialog](02-Dialog.html) | Job | [Libext](04-Libext.html) | [Misc](05-Misc.html) | [Side](06-Side.html) | [View](07-View.html) | [Widget](08-Widget.html) | [Other](99-Other.html) ]**

## Job

---

#### Files

```
    + job/io_jobs.c
    + job/exo_job.c
    + job/job.c
    + job/transferjob.c
    + job/simplejob.c
    + job/dcount_job.c
    + job/io_scandir.c
    + job/jobutils.c
```

* Description

    An action runs typically from Clipboard, DnD or Launcher, which will call
    an Application function which will run an io_job function in a ThunarJob
    thread.
    
    For example, the _launcher_action_delete will call
    application_unlink_files which calls the following :
    
    ```
    _launcher_action_delete
        application_unlink_files
            _application_launch
                io_unlink_files
                    simple_job
                        _io_unlink
                            _io_delete_file
                                g_file_delete
    ```


#### io_jobs

* Description

    Functions to execute IO jobs.

    ```
    io_list_directory
    io_make_directories
    io_create_files
    io_unlink_files
    io_move_files
    io_copy_files
    io_link_files
    io_trash_files
    io_restore_files
    io_rename_file
    io_change_group
    io_change_mode
    ```


#### ExoJob

* Description

    GObject used to wrap threaded/asynchronous operations in an object
    oriented way. It uses internally a GIOSchedulerJob.


#### ThunarJob

* Description

    An ExoJob used in dialogs and in file operations.


#### TransferJob

* Description

    A ThunarJob to perform Copy, Link, Move or Trash operations.


#### SimpleJob

* Description

    A ThunarJob for the following simple tasks :

    ```
    io_jobs     _io_ls
    io_jobs     _io_mkdir
    io_jobs     _io_create
    io_jobs     _io_unlink
    io_jobs     _io_link
    io_jobs     _io_trash
    io_jobs     _io_rename
    io_jobs     _io_chown
    io_jobs     _io_chmod
    ```


#### DeepCountJob

* Description

    A ThunarJob to count the number of file and total size in
    a directory.


#### io_scandir

* Description

    A io_scan_directory function to parse the content of a directory, recursively or not.


#### jobutils

* Description

    jobutil_next_duplicate_file and jobutil_next_renamed_file functions.

<br>
<br>
<br>


