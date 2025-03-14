<link href="style.css" rel="stylesheet"></link>

**[ Home | [Build](05-Build.html) | [Git](10-Git.html) | [Bash](15-Bash.html) | [Py](20-Python.html) | [Cpp](25-Cpp.html) | [Gtk](30-Gtk.html) | [Other](99-Other.html) ]**

## Docs Dev

---

#### References

* Freedesktop
    
    [freedesktop-desktop-entry](https://specifications.freedesktop.org/desktop-entry-spec/desktop-entry-spec-latest.html)  
    [freedesktop-icon-naming](https://specifications.freedesktop.org/icon-naming-spec/latest/ar01s04.html)  


#### Code Formatting

* astyle
    
    One file : `astyle -n --style=allman thunar-window.c`

    Recursive : `astyle -nr --style=allman "test/*.h" "test/*.c"`

* clang-format
    
    https://clang.llvm.org/docs/ClangFormatStyleOptions.html  
    
    dump config : `clang-format -style=llvm -dump-config > _clang-format`  
    in current dir : `clang-format -i -style=WebKit *.c *.h`  
    
* Find lines longer than n chars
    
    `grep -ni '.\{80\}' window.c`


#### Geany

* Generating tags
    
    https://www.geany.org/manual/current/index.html#symbols-and-tags-files  
    
    `CFLAGS=$(pkg-config --cflags tinyc) geany -g tinyc.c.tags /usr/local/include/tinyc/*.h`


#### Markdown

* Markdown
    
    https://www.markdownguide.org/basic-syntax/  
    [https://github.com/adam-p/markdown-here...](https://github.com/adam-p/markdown-here/wiki/Markdown-Here-Cheatsheet)  
    https://www.codecademy.com/resources/docs/markdown/tables  
    [https://docs.github.com/en/github/writing-on-github/](https://docs.github.com/en/github/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)  

* Named anchor in markdown
    
    https://stackoverflow.com/questions/5319754/  

    `#### <a name="tith"></a>This is the Heading`


#### Patches

* patch
    
    try : `patch -p 1 -i '../dir/my_file.patch' --dry-run`  
    
    do  : `patch -p 1 -i '../dir/my_file.patch'`  


