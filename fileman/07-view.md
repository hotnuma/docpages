<link href="style.css" rel="stylesheet"></link>

**[ [Home](00-Home.html) | [Core](01-Core.html) | [Dialog](02-Dialog.html) | [Job](03-Job.html) | [Libext](04-Libext.html) | [Misc](05-Misc.html) | [Side](06-Side.html) | View | [Widget](08-Widget.html) | [Other](99-Other.html) ]**

## View

---

#### Files

```
    + view/baseview.c
    + view/standardview.c
    + view/exotreeview.c
    + view/detailview.c
    + view/listmodel.c
    + view/columnmodel.c
```


#### BaseView

* Description

    A GTypeInterface to implement a base list view.


#### StandardView

* Description

    A GtkScrolledWindow which implements a Navigator, Component
    and BaseView interface. It contains a DetailView, it can create
    a select by pattern dialog box.


#### ExoTreeView

* Description

    A GtkTreeView with extended rubber banding and single click activate.


#### DetailView

* Description

    A StandardView containing an ExoTreeView.


#### ListModel

* Description

    A GObject which implements GtkTreeModel, GtkTreeDragDest,
    and GtkTreeSortable. It's the model used by the ExoTreeView
    to display files.


#### ColumnModel

* Description

    A GObject which implements GtkTreeModel.

<br>
<br>
<br>


