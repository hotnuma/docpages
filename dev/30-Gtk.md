<link href="style.css" rel="stylesheet"></link>

**[ [Home](00-Home.html) | [Build](05-Build.html) | [Git](10-Git.html) | [Bash](15-Bash.html) | [Py](20-Python.html) | [Cpp](25-Cpp.html) | Gtk | [Other](99-Other.html) ]**

## Gtk

---

#### Reference

* Docs

    <form action="https://google.com/search" method="get">
        <input type="hidden" name="sitesearch" value="www.manpagez.com" />
        <input type="text" placeholder="Search Gtk..." name="q" />
        <button>Search</button>
    </form>
    
    https://www.manpagez.com/html/glib/glib-2.56.0/index.php)  
    https://www.manpagez.com/html/gio/gio-2.56.0/index.php)  
    [https://specifications.freedesktop.org/icon-naming-spec...](https://specifications.freedesktop.org/icon-naming-spec/latest/ar01s04.html)  
    
* Tutorial
    
    https://zetcode.com/gui/gtk2/  
    [https://github.com/RainMark/gtk3-tutorial...](https://github.com/RainMark/gtk3-tutorial/tree/master/_examples)  
    [https://python-gtk-3-tutorial](https://python-gtk-3-tutorial.readthedocs.io/en/latest/gallery.html)  
    [https://www.cc.gatech.edu/data_files/public/doc/gtk...](https://www.cc.gatech.edu/data_files/public/doc/gtk/tutorial/gtk_tut.html)  
    [https://toshiocp.github.io/Gtk4-tutorial/](https://toshiocp.github.io/Gtk4-tutorial/)  

* Build simple program
    
    `gcc -o simple simple.c $(pkg-config --cflags --libs gtk+-3.0)`

* Gtk/Glib version
    
    https://askubuntu.com/questions/78377/  
    
    `dpkg -l libglib2.0-0 libgtk-3-0 | grep ^ii`  


#### Articles

* GObject
    
    [gobject-tutorial](https://docs.gtk.org/gobject/tutorial.html)  
    [gobject-new-unref](https://stackoverflow.com/questions/2848273/)  
    https://docs.gtk.org/gobject/floating-refs.html  
    [gobject-construction](https://blogs.gnome.org/desrt/2012/02/26/a-gentle-introduction-to-gobject-construction/)  
    [check-if-freed](https://stackoverflow.com/questions/24453266/)  
    [object-unref](https://discourse.gnome.org/t/when-should-i-use-g-object-unref/3834/6)  
    [object-unref](https://stackoverflow.com/questions/2848273/)  
    
    https://discourse.gnome.org/t/memory-leak-dispose-and-finalize-what-are-the-good-practices/11415/2  
    
* GTK+ par l'exemple.
    
    [https://nicolasj.developpez.com/gtk/cours/?page=les-raccourc](https://nicolasj.developpez.com/gtk/cours/?page=les-raccourcis-clavier)  

* Toolbar
    
    [add-gtkwidget](https://stackoverflow.com/questions/10740967/how-to-add-gtkwidget-to-gtktoolbar)  

* How to properly add images to buttons
    
    [add-images-to-buttons](https://discourse.gnome.org/t/how-to-properly-add-images-to-buttons/1185/2)  

* TreeView

    [gtk3-treeview-tutorial](https://docs.gtk.org/gtk3/treeview-tutorial.html)  
    [zetcode-gtk2-treeview](https://zetcode.com/gui/gtk2/gtktreeview/)  
    [wikibooks-gtk-treeview](https://en.wikibooks.org/wiki/GTK%2B_By_Example/Tree_View/Tree_Models)  
    
* GtkBox vs GtkGrid
    
    https://www.manpagez.com/html/gtk3/gtk3-3.24.31/ch30s02.php  

* Alternative to deprecated gtk_alignment_new
    
    https://stackoverflow.com/questions/58746046/  


#### Gtk custom widgets

* Examples

    [old-tutorial](https://www.cc.gatech.edu/data_files/public/doc/gtk/tutorial/gtk_tut-20.html)  
    [examples](https://wiki.gnome.org/HowDoI/CustomWidgets)  
    [examples](http://www.peteronion.org.uk/GtkExamples/GladeTutorials.html)  
    [create-object](https://stackoverflow.com/questions/57699050/)  


#### Drag and Drop

* Reference
    
    https://wiki.gnome.org/Newcomers/OldDragNDropTutorial  
    [https://wiki.gnome.org/HowDoI/DragAndDrop](https://wiki.gnome.org/HowDoI/DragAndDrop?action=AttachFile&do=get&target=dnd-overview.png)  
    https://www.freedesktop.org/wiki/Specifications/direct-save/  
    
    <table>
        
        <tr>
            <th style="width:50%">Source</th>
            
            <th style="width:50%">Destination</th>
        </tr>

        <tr>
            <td>
                <b>Setup source</b><br>
                <br>
                <ul class="lidisc">
                    <li>
                    define a source target list using <b>GtkTargetEntry</b>
                    </li><br>
                    
                    <li>
                    call <b>gtk_drag_source_set()</b>
                    </li><br>
                    
                    <li>
                    connect handlers or use vfuncs or use default handlers<br>
                    </li><br>
                    
                    <li>
                    it's also possible to start a drag manually using
                    a <b>GtkTargetList</b> and calling
                    <b>gtk_drag_begin_with_coordinates()</b>
                    </li>
                </ul> 
            </td>
            
            <td>
                <b>Setup destination</b><br>
                <br>
                <ul class="lidisc">
                    <li>
                    define a destination target list using <b>GtkTargetEntry</b>
                    </li><br>
                    
                    <li>
                    call <b>gtk_drag_dest_set()</b><br>
                    </li><br>
                    
                    <li>
                    connect handlers or use vfuncs or use default handlers<br>
                    </li>
                </ul> 
            </td>
        </tr>
        
        <tr>
            <td>
                <b>1 - "drag-begin"</b><br>
                <br>
                <i>Drag operation triggered</i><br>
                <br>
                <ul class="lidisc">
                    <li>
                    set the drag icon<br>
                    </li><br>
                    
                    <li>
                    setup of the current drag<br>
                    </li>
                </ul> 
            </td>
            
            <td>
                <b>2 - "drag-motion"</b><br>
                <br>
                <i>Cursor moves over the drop target, the handler is called for each
                cursor movement</i><br>
                <br>
                <ul class="lidisc">
                    <li>
                    hightlight the drop zone
                    </li><br>
                    
                    <li>
                    <div class="txgreen">can examine drag format and drag action :<br>
                    <br>
                    call <b>gtk_drag_dest_find_target()</b><br>
                    <br>
                    <b><-- "drag-data-get</b>"</div>
                    </li><br>
                    
                    <li>
                    drop impossible :<br>
                    <br>
                    call <b>gtk_drag_status(context, 0, time)</b><br>
                    <br>
                    return <b>false</b>
                    </li><br>
                    
                    <li>
                    <div class="txgreen">drop possible :<br><br>
                    call <b>gtk_drag_status(context, action, time)</b><br>
                    <br>
                    return <b>true</b></div>
                    </li>
                </ul> 
            </td>
        </tr>
        
        <tr>
            <td>
                <b>4 - "drag-data-get"</b><br>
                <br>
                <i>Data requested from a drop destination</i><br>
                <br>
                <ul class="lidisc">
                    <li>
                    prepare data depending on the target<br>
                    </li><br>
                    
                    <li>
                    <div class="txgreen">send data to the selection object :<br>
                    <br>
                    call <b>gtk_selection_data_set()</b><br>
                    <br>
                    <b>--> "drag-data-received"</b></div><br>
                    </li>
                </ul> 
            </td>
            
            <td>
                <b>3 - "drag-drop"</b><br>
                <br>
                <i>Button released over destination</i><br>
                <br>
                <ul class="lidisc">
                    <li>
                    check for a correct sub-drop zone
                    </li><br>
                    
                    <li>
                    examine drag format and drag action
                    </li><br>
                    
                    <li>
                    drop rejected : return <b>false</b>
                    </li><br>
                    
                    <li>
                    <div class="txgreen">- drop accepted : <b>gtk_drag_get_data()</b><br>
                    <br>
                    <b><-- "drag-data-get"</b><br>
                    <br>
                    return <b>true</b></div>
                    </li>
                </ul> 
            </td>
        </tr>
        
        <tr>
            <td>
                <b>"drag-failed"</b><br>
                <br>
                <ul class="lidisc">
                    <li>
                    end the DnD operation
                    </li><br>
                    
                    <li>
                    free resources<br>
                    <br>
                    <b>--> "drag-end"</b></div>
                    </li>
                </ul> 
            </td>
            
            <td rowspan="3">
                <b>5 - "drag-data-received"</b><br>
                <br>
                <i>Button release over destination</i><br>
                <br>
                <ul class="lidisc">
                    <li>
                    get the data received :
                    <b>gtk_selection_data_get()</b><br>
                    </li><br>
                    
                    <li>
                    <div class="txgreen">data rejected :<br>
                    <br>
                    call <b>gtk_drag_data_finish(false)</b><br>
                    <br>
                    <b><-- "drag-failed"</b></div><br>
                    </li><br>
                    
                    <li>
                    <div class="txgreen">data accepted :<br>
                    <br>
                    copy data<br>
                    <br>
                    free destination resources<br>
                    <br>
                    call <b>gtk_drag_data_finish(true, delete)</b><br>
                    <br>
                    <b><-- "drag-data-delete"</b><br>
                    <br>
                    <b><-- "drag-end"</b></div>
                    </li>
                </ul> 
            </td>
        </tr>
        
        <tr>
            <td>
                <b>"drag-data-delete"</b><br>
                <br>
                <ul class="lidisc">
                    <li>
                    delete the moved data<br>
                    <br>
                    <b>--> "drag-end"</b></div>
                    </li>
                </ul> 
            </td>
        </tr>
        
        <tr>
            <td>
                <b>"drag-end"</b><br>
                <br>
                <ul class="lidisc">
                    <li>
                    end the DnD operation
                    </li><br>
                    
                    <li>
                    free resources
                    </li>
                </ul> 
            </td>
        </tr>
        
        <tr>
            <td>
            </td>
            <td>
                <b>"drag-leave"</b><br>
                <br>
                <ul class="lidisc">
                    <li>
                    un-highlight the drop zone
                    </li>
                </ul> 
            </td>
        </tr>
    </table>
    

#### Other

* Drop down menu to Toolbar Item
    
    [https://stackoverflow.com/questions/9132440/gtk-drop-down-me](https://stackoverflow.com/questions/9132440/gtk-drop-down-menu-to-toolbar-item)  

* GTK3 and multithreading
    
    https://stackoverflow.com/questions/30607429/  

* Redirect stdout in a text window
    
    [https://stackoverflow.com/questions/48478615/how-to-rediredt](https://stackoverflow.com/questions/48478615/how-to-rediredt-the-stdout-in-a-text-window-c-programming)  
    [https://mail.gnome.org/archives/gtk-list/2006-February/msg00](https://mail.gnome.org/archives/gtk-list/2006-February/msg00040.html)  


