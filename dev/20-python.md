<link href="../style.css" rel="stylesheet"></link>

**[ [Home](00-home.html) | [Build](05-build.html) | [Git](10-git.html) | [Bash](15-bash.html) | Py | [Cpp](25-cpp.html) | [Gtk](30-gtk.html) | [Other](99-other.html) ]**

## Python

---

#### Howto

* Get script name
    
    `appname = os.path.basename(__file__)`

* Error messages
    
    ```
    def error_exit(msg):
        if msg == "": msg = "an error occurred"
        print("*** %s\nabort..." % msg)
        exit(1)
    
    def usage_exit():
        print("*** usage :")
        print("%s -opt1" % appname)
        print("%s -opt2 bla" % appname)
        print("abort...")
        exit(1)
    ```

* Read args
    
    ```
    import os, sys
    
    args = sys.argv
    size = len(args)
    if size < 2: exit(1)

    opt_val = ""
    i = 1
    while i < size:
        if args[i] == "-opt":
            i += 1
            if i >= size: exit(1)
            opt_val = args[i]
        else:
            exit(1)
        i += 1

    print(opt_val)
    ```

* Execute process

    ```
    import os, sys, subprocess

    def runcmd(cmd):
        ret = subprocess.run(cmd, shell=True, capture_output=True)
        result = ret.stdout.decode()
        return (result, ret.returncode)
    
    cmd = "ls -la"
    result, ret = runcmd(cmd)
    ```


