<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | [ImgView](05-imgview.html) | Uni | [Dlg](15-dlg.html) ]**

## Uni

---

#### Files

```

    uni/uni-scroll-win.c
    uni/uni-anim-view.c
    uni/uni-image-view.c
    uni/uni-dragger.c
    uni/uni-cache.c
    uni/uni-exiv2.cpp
    uni/uni-utils.c
    uni/uni-zoom.h

```


#### UniScrollWin

* Description
    
    A `GtkGrid` which contains scrollbars and a `UniAnimView` widget to display
    images.


#### UniAnimView

* Description
    
    An `UniImageView` which can display animated images.


#### UniImageView

* Description
    
    A custom GtkWidget which display an image.
    

#### UniDragger

* Description
    
    A GObject which contains an UniPixbufDrawCache.


#### UniPixbufDrawCache

* Description
    
    


#### Move image

* Description
    
    `widget_motion_notify` handler calls `uni_dragger_motion_notify` which
    calls `uni_image_view_set_offset`.


<br>


