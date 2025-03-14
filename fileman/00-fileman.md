<link href="style.css" rel="stylesheet"></link>

**[ Home | [Core](01-Core.html) | [Dialog](02-Dialog.html) | [Job](03-Job.html) | [Libext](04-Libext.html) | [Misc](05-Misc.html) | [Side](06-Side.html) | [View](07-View.html) | [Widget](08-Widget.html) | [Other](99-Other.html) ]**

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
    **application_process_filenames**, **_application_process_files**,
    **browser_poke_file**, **_application_process_files_finish**,
    **th_file_launch**.
    
    Then **application_open_window** is called with the current directory
    to parse. The AppWindow is created and **window_set_current_directory**
    is called.

* Interfaces
    
    FileInfo : base class for ThunarFile
    
    ThunarBrowser : base class to browse, file, device and location
    
    ThunarComponent : handles selected files
    
    ThunarNavigator : handles the current directory
    
    SidePane : base class to handle show/hide property
    
    BaseView : base class for the StandardView
    

#### Main

* Description

    The main function sets the application name, initializes libnotify and
    runs the application.


#### Application
    
* Description

    Application object is a GtkApplication, it contains functions to
    execute file operations.
    
    ```
    
        application_process_filenames
        
        application_mkdir
        application_creat
        
        application_copy_into
        application_link_into
        application_move_into
        
        application_unlink_files
        application_trash
        application_restore_files
        application_empty_trash
    
    ```
    
    For example, LAUNCHER_ACTION_CREATE_FOLDER menu item calls
    _launcher_action_create_folder then calls application_mkdir.
    

#### AppWindow

* Description

    A GtkWindow.
    
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
    
    A GObject used to execute actions from particular widgets. Window,
    and TreeView have a ThunarLauncher.


#### AppMenu

* Description
    
    https://alexxcons.github.io/blogpost_1.html  

    AppMenu is a GtkMenu used as a popup menu in the TreeView and the
    StandardView. It's created using g_object_new and filled with
    appmenu_add_sections. First, the Launcher informations are filled,
    then the popup is created, then selecting an item will call a launcher
    function on the corresponding Launcher object.

* TreeView
    
    The menu is created from the widget's popup handler which calls the
    treeview_popup_menu function and then **_treeview_context_menu**.
    
* StandardView

    The widget creates its popup in response to a button-release-event signal,
    it calls the _standard_view_button_release_event function and then it
    calls **standard_view_context_menu**.


<br>


