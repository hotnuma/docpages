<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | ImgView | [Dlg](10-dlg.html) | [Uni](15-uni.html) ]**

## ImgView

---

#### Files

```

    + main.c
      window.c
      message-area.c
      list.c
      file.c
      preferences.c
      vnr-tools.c

```


#### Main

* Description
    
    Parse options and create the application window.
    

#### VnrWindow

* Description
    
    `VnrWindow` is a `GtkWindow`. 

    ```
    
        VnrWindow (GtkWindow)
            GtkBox
                ------------------------------------------------
                VnrMessageArea
                ------------------------------------------------
                UniScrollView (GtkGrid)
                    UniAnimView (derives from UniImageView)
            
    ```

<br>

