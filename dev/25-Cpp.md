<link href="style.css" rel="stylesheet"></link>

**[ [Home](00-Home.html) | [Build](05-Build.html) | [Git](10-Git.html) | [Bash](15-Bash.html) | [Py](20-Python.html) | Cpp | [Gtk](30-Gtk.html) | [Other](99-Other.html) ]**

## C/Cpp

---

#### References

* GCC cleanup attribute
    
    [attribute-cleanup](https://blog.fishsoup.net/2015/11/05/attributecleanup-mixed-declarations-and-code-and-goto/)  
    [g_autoptr](https://blogs.gnome.org/desrt/2015/01/30/g_autoptr/)  
    [echorand-cleanup](http://echorand.me/site/notes/articles/c_cleanup/cleanup_attribute_c.html)  

* Feature test macros
    
    [feature_test_macros](https://manpages.ubuntu.com/manpages/xenial/en/man7/feature_test_macros.7.html)  
    
    `#define _GNU_SOURCE`

* error functions
    
    ```
    #define APPNAME "appname"
    
    static void error_exit(const char *msg)
    {
        if (!msg || *msg == '\0')
        {
            msg = "an error occurred";
        }

        printf("*** %s\nabort...\n", msg);

        exit(EXIT_FAILURE);
    }

    static void usage_exit()
    {
        printf("*** usage :\n");
        printf("%s param\n", APPNAME);
        printf("abort...\n");

        exit(EXIT_FAILURE);
    }
    ```

* args parsing
    
    ```
    int n = 1;

    while (n < argc)
    {
        if (strcmp(argv[n], "-opt") == 0)
        {
            return EXIT_SUCCESS;
        }
        else if (strcmp(argv[n], "-arg") == 0)
        {
            if (++n >= argc)
                usage_exit();

            return EXIT_SUCCESS;
        }
        else
        {
            usage_exit();
        }

        ++n;
    }
    ```

* Reporting information using syslog
    
    https://stackoverflow.com/questions/18658429/  

* Current directory in C
    
    https://stackoverflow.com/questions/298510/  
    
    ```
    #include <unistd.h>
    char *getcwd(char *buf, size_t size);
    ```

* Parse html using C
    
    https://stackoverflow.com/questions/1527883/  

* Execution time of C program
    
    https://stackoverflow.com/questions/5248915/  
    https://stackoverflow.com/questions/55344890/  

* Clear the console
    
    https://stackoverflow.com/questions/228617/  

* Polkit applications
    
    https://www.freedesktop.org/software/polkit/docs/0.105/polkit-apps.html  


#### Functions

* string starts with
    
    https://stackoverflow.com/questions/4770985/  

* `_vscprintf`
    
    https://stackoverflow.com/questions/4785381/  

* stat, fstat, lstat

    http://manpages.ubuntu.com/manpages/trusty/fr/man2/stat.2.html  

* open vs fopen
    
    https://stackoverflow.com/questions/1658476/  
    
* fgets
    
    [https://www.tutorialspoint.com/c_standard_library/c_function](https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm)  
    https://koor.fr/C/cstdio/fgets.wp  



#### System

* CPU getusage_c
    
    https://github.com/fho/code_snippets/blob/master/c/getusage.c  

* Audio playing detect
    
    https://stackoverflow.com/questions/22144203/  

* GKeyFile
    
    https://gist.github.com/zdxerr/709169  



#### Process

* Execute program in C
    
    https://stackoverflow.com/questions/5237482/

* popen
    
    https://tldp.org/LDP/lpg/node12.html  

* posix_spawn
    
    https://www.systutorials.com/a-posix_spawn-example-in-c-to-create-child-process-on-linux/  

* Exit status code
    
    https://stackoverflow.com/questions/27306764/  

* select
    
    https://www.blaess.fr/christophe/2013/12/27/comprendre-le-fonctionnement-de-select/  



#### Daemon

* Examples
    
    https://gist.github.com/copyninja/1033862  
    https://www.thegeekstuff.com/2012/02/c-daemon-process/  
    https://www.google.com/search?channel=fs&client=ubuntu&q=daemon+example+in+c  
    http://netzmafia.de/skripten/unix/linux-daemon-howto.html  
    https://lloydrochester.com/post/c/unix-daemon-example/  
    https://github.com/pasce/daemon-skeleton-linux-c  
    https://gitlab.com/sulincix/fork/-/blob/master/src/pfork.c  



#### Redirect IO

* Reading from a pipe
    
    https://stackoverflow.com/questions/1151029/  

* output of process in C
    
    http://www.microhowto.info/howto/capture_the_output_of_a_child_process_in_c.html  

* Redirect pipe dup2
    
    https://linuxfr.org/forums/programmation-c--2/posts/communication-entre-processus-avec-pipe-et-dup2  

* Redirect to buffer or file
    
    https://stackoverflow.com/questions/2605130/  



#### Articles

* QtCreator printf

    https://chowdera.com/2020/12/20201208210320326z.html  

    `setbuf(stdout, NULL);`

* QtCreator per-project tab spacing
    
    [https://forum.qt.io/topic/86319/qt-creator-how-to-do-per-pro](https://forum.qt.io/topic/86319/qt-creator-how-to-do-per-project-tab-spacing/4)

* Memory usage of current process
    
    https://stackoverflow.com/questions/1558402/  

* RAM usage of a process using its ID
    
    https://stackoverflow.com/questions/67224020/  


