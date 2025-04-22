<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | ImgView | [Uni](10-uni.html) | [Dialog](20-dialog.html) ]**

## ImgView

---

#### Files

```

    + main.c
    + window.c
    + list.c
      file.c
      vnr-tools.c

```

#### Main

* Description
    
    Parse options and create the application window.
    

#### VnrWindow

* Description
    
    `VnrWindow` is a `GtkWindow`. It contains a `UniScrollView` which contains
    an `UniAnimView` to display the current image.
    
    `UniAnimView` is a `UniImageView` widget, it can display a
    `GdkPixbufAnimation` or a static `GdkPixbuf`.
    
    `UniImageView` contains a `UniDragger` to move the current image,
    `UniDragger` contains a `UniPixbufDrawCache`.

    ```
    
        VnrWindow (GtkWindow)
            GtkBox
            -------------------------------------------------------------------
                VnrMessageArea
            -------------------------------------------------------------------
                UniScrollView (GtkGrid)
                    UniAnimView (UniImageView)
                        GdkPixbufAnimation, GdkPixbuf, UniDragger
            -------------------------------------------------------------------
            
    ```

#### vnr_list
    
    `vnr_list_*` methods uses a `GList` to create and store `VnrFile` objects.


#### VnrFile


#### message-view


#### preferences


#### tools


<br>


