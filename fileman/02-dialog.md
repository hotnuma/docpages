<link href="style.css" rel="stylesheet"></link>

**[ [Home](00-Home.html) | [Core](01-Core.html) | Dialog | [Job](03-Job.html) | [Libext](04-Libext.html) | [Misc](05-Misc.html) | [Side](06-Side.html) | [View](07-View.html) | [Widget](08-Widget.html) | [Other](99-Other.html) ]**

## Dialog

---

#### Files

```
    + dialog/dialogs.c
    + dialog/progressdlg.c
    + dialog/progressview.c
    + dialog/appchooser.c
    + dialog/appmodel.c
    + dialog/appcombo.c
    + dialog/propsdlg.c
    + dialog/permbox.c
```


#### Dialogs

* Description

    Several application dialogs such as dialog_insecure_program,
    dialog_file_create, dialog_file_rename, dialog_folder_trash, etc...


#### ProgressDialog

* Description

    A GtkWindow for file operation progress dialog.


#### ProgressView

* Description

    A GtkBox for file operation progress.


#### AppChooserDialog

* Description

    A GtkDialog to select an application.


#### AppChooserModel

* Description

    A GtkTreeStore to handle applications. The appmodel_load function
    fills the model using g_app_info_get_all_for_type.


#### AppCombo

* Description

    A GtkComboBox to select an application, it calls
    g_app_info_get_default_for_type and stores infos in a GtkListStore.
    It's used in the properties dialog box.


#### PropertiesDialog

* Description

    A GtkDialog created from the contextual popup menu.


#### PermissionBox

* Description

    A GtkBox to display permission settings in the PropertiesDialog.

<br>
<br>
<br>


