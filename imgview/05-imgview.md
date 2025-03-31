<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | ImgView | [Dlg](10-dlg.html) | [Uni](15-uni.html) | [Vnr](20-vnr.html) ]**

## ImgView

---

#### Files

```

    main.c
    window.c
    preferences.c
    list.c
    file.c

```

* Description


#### Main

* Description
    

#### VnrWindow

* Description
    
    The application window is a GtkWindow. 

    ```
    
        GtkWindow
            GtkBox
                ------------------------------------------------
                VnrMessageArea
                ------------------------------------------------
                UniScrollView
                    UniAnimView (derives from UniImageView)
            
    ```

<br>

