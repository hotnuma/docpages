// https://www.lirc.org/api-docs/html/group__lirc__client.html
// cbuild test remote.c lirc
// ./test

#include "lirc_client.h"

int main(int argc, char **argv)
{
    // use argv[1] as lircrc config file path
    const char *lircrc_path = (argc == 2 ? argv[1] : NULL);

    if (lirc_init("radio", 1) == -1)
    {
        printf("lirc_init : error\n");
        return EXIT_FAILURE;
    }

    struct lirc_config *config;

    if (lirc_readconfig(lircrc_path, &config, NULL) != 0)
    {
        printf("lirc_readconfig : error\n");
        return EXIT_FAILURE;
    }

    char *code;
    char *s;
    while (lirc_nextcode(&code) == 0)
    {
        if (code == NULL)
            continue;
        
        while (lirc_code2char(config, code, &s) == 0
               && s != NULL)
        {
            //printf("cmd = %s\n", s);
            system(s);
        }
        free(code);
    }
    
    lirc_freeconfig(config);
    lirc_deinit();
    
    return EXIT_SUCCESS;
}


