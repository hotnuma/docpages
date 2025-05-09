<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | Fileman | [Core](01-core.html) | [Dialog](02-dialog.html) | [Job](03-job.html) | [Libext](04-libext.html) | [Misc](05-misc.html) | [Side](06-side.html) | [View](07-view.html) | [Widget](08-widget.html) | [Other](99-other.html) ]**

## Fileman

---

#### Files

```

    +   main.c
    +   application.c
    +   window.c
    +   appmenu.c
    +   launcher.c
        preferences.c

```

* Description
    
    When the application starts, **application_command_line** si called and
    parses the command line. Then the following are called,
    **_application_process_filenames**, **_application_process_files**,
    **browser_poke_file**, **_application_process_files_finish**,
    **th_file_launch**.
    
    Then **application_open_window** is called with the current directory
    to parse. The `AppWindow` is created and **window_set_current_directory**
    is called.

* Interfaces
    
    `FileInfo` : base class for `ThunarFile`
    
    `ThunarNavigator` : handles the current directory
    
    `ThunarBrowser` : base class to browse, file, device and location
    
    `ThunarComponent` : handles selected files
    
    `SidePane` : base class to handle show/hide property
    
    `BaseView` : base class for the `StandardView`
    

#### Main

* Description

    The main function sets the application name, initializes libnotify and
    runs the application.


#### Application
    
* Description

    `Application` object is a `GtkApplication`, it contains functions to
    execute file operations.
    
    ```
    
        application_process_filenames
        application_launch
    
    ```
    
    **application_launch** is a central function to execute a file operation
    and create a progress dialog box if needed.
    

#### AppWindow

* Description

    A `GtkWindow`.
    
    ```
    
        GtkWindow
            GtkGrid
                ------------------------------------------------
                GtkToolbar
                    GtkToolItem
                        LocationBar (GtkBox)
                            PathEntry (GtkEntry)
                ------------------------------------------------
                GtkPaned
                    pane1
                        SidePane (window_install_sidepane)
                    pane2
                        DetailView (_window_create_detailview)
                ------------------------------------------------
                GtkStatusbar
            
    ```


#### ThunarLauncher

* Description
    
    A `GObject` used to execute actions from particular widgets. `Window`,
    and `TreeView` have a `ThunarLauncher`.


#### AppMenu

* Description
    
    https://alexxcons.github.io/blogpost_1.html  

    `AppMenu` is a `GtkMenu` used as a popup menu in the `TreeView` and the
    `StandardView`. It's created using `g_object_new` and filled with
    **appmenu_add_sections**. First, the Launcher informations are filled,
    then the popup is created, then selecting an item will call a launcher
    function on the corresponding Launcher object.

* TreeView
    
    The menu is created from the widget's **button_press_event** handler
    which calls the **treeview_popup_menu** function and then
    **_treeview_context_menu**.
    
* StandardView

    The widget creates its popup in response to a **button-release-event**
    signal, it calls the **_standard_view_button_release_event** function and
    then it calls **standard_view_context_menu**.

<br>


