<link href="style.css" rel="stylesheet"></link>

**[ [Home](00-Home.html) | [Core](01-Core.html) | [Dialog](02-Dialog.html) | [Job](03-Job.html) | [Libext](04-Libext.html) | [Misc](05-Misc.html) | [Side](06-Side.html) | [View](07-View.html) | [Widget](08-Widget.html) | Other ]**

## Other

---

#### References

* Docs
    
    https://developer.xfce.org/thunar/index.html  
    https://wiki.xfce.org/thunar/dev/build_and_run  
    https://gitlab.xfce.org/xfce/thunar  
    https://docs.xfce.org/xfce/thunar/start  

* Build deps
    
    ```
    libxfce4ui-2-dev
    
    libexo-2-dev
    libgudev-1.0-dev
    libnotify-dev
    libthunarx-3-dev
    libxfce4util-dev
    libxfconf-0-dev
    ```


#### Project files

```
find . -type f -name "*.c" | sort

./core/clipboard.c
./core/devmonitor.c
./core/dnd.c
./core/fileinfo.c
./core/filemonitor.c
./core/th_device.c
./core/th_file.c
./core/th_folder.c
./core/usermanager.c

./dialog/appchooser.c
./dialog/appcombo.c
./dialog/appmodel.c
./dialog/dialogs.c
./dialog/permbox.c
./dialog/progressdlg.c
./dialog/progressview.c
./dialog/propsdlg.c

./job/dcountjob.c
./job/exo_job.c
./job/io_jobs.c
./job/io_scandir.c
./job/job.c
./job/jobutils.c
./job/simplejob.c
./job/transferjob.c

./libext/gdk_ext.c
./libext/gio_ext.c
./libext/gtk_ext.c
./libext/pango_ext.c
./libext/pixbuf_ext.c
./libext/utils.c

./misc/appnotify.c
./misc/browser.c
./misc/component.c
./misc/enumtypes.c
./misc/history.c
./misc/iconfactory.c
./misc/iconrender.c
./misc/navigator.c
./misc/shortrender.c

./side/sidepane.c
./side/treemodel.c
./side/treepane.c
./side/treeview.c

./view/baseview.c
./view/columnmodel.c
./view/detailview.c
./view/exotreeview.c
./view/listmodel.c
./view/standardview.c

./widget/locationbar.c
./widget/locationentry.c
./widget/pathentry.c
./widget/sizelabel.c
./widget/statusbar.c
./widget/th_image.c

./application.c
./appmenu.c
./config.h
./debug.h
./launcher.c
./main.c
./marshal.c
./preferences.c
./window.c
```


#### Biggest files

```
find . -type f -name "*.c" -printf "%s\t%p\n" | sort -nr | head -10

127510	./view/standardview.c
102177	./core/th_file.c
95904	./menu/launcher.c
70707	./view/listmodel.c
70126	./side/treeview.c
68427	./window.c
60747	./side/treemodel.c
60213	./job/transferjob.c
54371	./application.c
50846	./dialog/permbox.c
```


#### Notes

* selection change
    
    `standard_view_selection_changed`

* double clic detail view

    details_view_row_activated

        launcher_activate_selected_files (launcher, THUNAR_LAUNCHER_CHANGE_DIRECTORY, NULL);

* Custom Actions

    xfce_spawn_on_screen_with_child_watch : executes external program

    match patterns : g_pattern_match_simple

<br>
<br>
<br>


