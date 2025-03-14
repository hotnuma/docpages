<link href="style.css" rel="stylesheet"></link>

**[ [Home](00-Home.html) | [Build](05-Build.html) | [Git](10-Git.html) | Bash | [Py](20-Python.html) | [Cpp](25-Cpp.html) | [Gtk](30-Gtk.html) | [Other](99-Other.html) ]**

## Bash

---

#### Reference

* Advance Bash scripting
    
    https://tldp.org/LDP/abs/html/index.html  

* ShellCheck
    
    https://www.shellcheck.net/  


#### Helpers

* Usefull functions
    
    ```
    appname=${0##*/}

    error_exit()
    {
        msg="$1"
        test "$msg" != "" || msg="an error occurred"
        printf "*** $msg\nabort...\n"
        exit 1
    }
    
    usage_exit()
    {
        echo "*** usage :"
        echo "$appname -opt1"
        echo "$appname -opt2 bla"
        echo "abort..."
        exit 1
    }

    ask_confirm()
    {
        while true; do
            read -p "$1" ret
            case $ret in
                [Yy]*)
                    return 0; break
                ;;
                [Nn]*)
                    return 1; break
                ;;
                *)
                    return 0; break
                ;;
            esac
        done
    }
    ```


#### Args

* Check number of arguments
    
    https://stackoverflow.com/questions/18568706/  
    
    `test "$#" -eq 1 || error_exit "Illegal number of parameters"`

* Parsing args
    
    https://stackoverflow.com/questions/192249/  

    ```
    #!/usr/bin/bash

    opt_dev=0
    opt_name=""

    while (($#)); do
        case "$1" in
            -dev)
            opt_dev=1
            ;;
            -o)
                test $# -gt 1 || error_exit "*** missing option"
                shift
                opt_name="$1"
            ;;
            *)
            opt_dev=0
            ;;
        esac
        shift
    done

    if [[ $DEV == 1 ]]; then
        echo ok
    fi
    ```


#### Directories

* Script directory
    
    https://stackoverflow.com/questions/59895/  
    
    `basedir="$(dirname -- "$(readlink -f -- "$0";)")"`

* Parse sub directories

    ```
    #!/usr/bin/bash

    for dir in $PWD/*; do
        if [[ -d $dir ]]; then
            echo $dir
        fi
    done
    ```


#### Files

* Test file extension
    
    https://stackoverflow.com/questions/21425006/  
    
    ```
    #!/bin/bash

    inpath="file.html"

    if [[ "${inpath: -5}" == ".html" ]];then
        echo ok
    fi
    ```

* Change file extension
    
    https://stackoverflow.com/questions/1224766/  

    ```
    inpath=file.md
    outpath=${inpath%.md}.html
    ```

* Heredoc
    
    https://linuxize.com/post/bash-heredoc/  
    
    ```
    dest=~/test.txt
    sudo tee $dest > /dev/null << EOF
    bla
    ble
    blie
    EOF
    ```

* Output to file and stdout
    
    https://stackoverflow.com/questions/418896/  
    
    ```
    program [arguments...] 2>&1 | tee -a "$outfile"
    ```


#### Misc

* Write functions
    
    https://linuxize.com/post/bash-functions/  

* Checking sudo
    
    https://stackoverflow.com/questions/42875809/  
    
    ```
    if [[ "$EUID" = 0 ]]; then
        echo "(1) already root"
    else
        sudo -k # make sure to ask for password on next sudo
        if sudo true; then
            echo "(2) correct password"
        else
            echo "(3) wrong password"
            exit 1
        fi
    fi
    ```

<!--
    `basedir="$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"`  
-->


