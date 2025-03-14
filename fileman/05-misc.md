<link href="style.css" rel="stylesheet"></link>

**[ [Home](00-Home.html) | [Core](01-Core.html) | [Dialog](02-Dialog.html) | [Job](03-Job.html) | [Libext](04-Libext.html) | Misc | [Side](06-Side.html) | [View](07-View.html) | [Widget](08-Widget.html) | [Other](99-Other.html) ]**

## Misc

---

#### Files

```
    + misc/navigator.c
    + misc/history.c
    + misc/component.c
    + misc/browser.c
    + misc/iconfactory.c
    + misc/iconrender.c
    + misc/shortrender.c
    + misc/enumtypes.c
```


#### ThunarNavigator

* Description

    GTypeInterface to handle current directory. Launcher, History, TreePane
    TreeView, StandardView, LocationBar and LocationEntry, implement it.


#### ThunarHistory

* Description

    A GObject to handle back, forward browse history. ThunarHistory
    implements a ThunarNavigator interface.


#### ThunarComponent

* Description

    A GInterface to store selected files. Launcher, TreePane and StandardView
    implement it.


#### ThunarBrowser

* Description

    A GInterface used by Application, LocationEntry and Launcher to
    resolve a file before launching it. For example, Application calls
    browser_poke_file to resolve a file given on the command line and
    then launch it in a callback using th_file_launch.


#### IconFactory

* Description
    
    A GObject to cache icons and thumbnails.


#### IconRenderer

* Description

    A GtkCellRenderer to display TreeView and ListView icons.

* Shortcut arrow in Thunar
    
    Thunar renders shortcut arrows the same way as emblems.
    thunar_icon_renderer_render calls thunar_file_get_emblem_names which
    adds a symbolic link emblem name.
    
    ```
    thunar_icon_renderer_render :
        if (G_LIKELY (icon_renderer->emblems))
            emblems = thunar_file_get_emblem_names (icon_renderer->file);

    thunar_file_get_emblem_names :
        if (thunar_file_is_symlink(file))
            emblems = g_list_prepend(emblems, THUNAR_FILE_EMBLEM_NAME_SYMBOLIC_LINK);
    ```

#### ShortcutRenderer

* Description

    An IconRenderer used in the TreeView.


#### enumtypes

* Description
    
    Application's enums.

    ```
    ThunarColumn
    ThunarDateStyle
    ThunarFileMode
    ThunarJobResponse
    ParallelCopyMode
    ThunarRecursivePermissionsMode
    ThunarIconSize
    ThunarZoomLevel
    ThunarThumbnailMode
    ThunarThumbnailSize
    ```

<br>
<br>
<br>


