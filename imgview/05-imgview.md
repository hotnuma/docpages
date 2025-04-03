<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | ImgView | [Uni](10-uni.html) | [Dlg](15-dlg.html) ]**

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

