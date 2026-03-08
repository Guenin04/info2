#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct options {
    int verbose;    // -v1, -v2, -v3
    int count;      //-c10
    bool happy;     //
    char *filename; //filename.txt
} Options;

#if 0
bool parse_options(int argc, char *argv[], Options *options){
    options->verbose = 0;
    return false;
}
#endif

Options parse_options(int argc, char *argv[]){
    
    Options options = {0, 0, false, NULL};

    for(int i = 1; i < argc; i++){
        if(argv[i][0] == '-'){
            switch (argv[i][1]) {
                case 'v':
                    options.verbose = argv[i][2] - '0';
                    break;
                case 'c':
                    options.count = atoi(argv[i] + 2);
                    break;
                case 'h':
                    options.happy = true;
                    break;
                default:
                    fprintf(stderr, "Unknown option: %s\n", argv[i]);
                    break;
            }
        } else {
            options.filename = argv[i];
        }
    }

    printf("Verbose: %d\n", options.verbose);
    printf("Count: %d\n", options.count);
    printf("Happy: %s\n", options.happy ? "true" : "false");
    printf("Filename: %s\n", options.filename ? options.filename : "None");
    return options;
}
int main(int argc,char *argv[]){
    Options options = parse_options(argc, argv);
    if(options.happy){
        printf("Have a nice day!\n");
    }
}