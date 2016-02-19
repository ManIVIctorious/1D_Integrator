
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define _MaxLineLength_ 2048

int InputFunction(char *inputfile, double **x, double **V);

//int main(int argc, char **argv){
//
//    double *x, *V;
//    int i, dimension;
//    char *inputfile = argv[1];
//
//    x = malloc(sizeof(double));
//    V = malloc(sizeof(double));
//    dimension = InputFunction(inputfile, &x, &V);
//
//    printf("%d\n", dimension);
//    for(i=0; i<dimension; ++i){
//        printf("% 12.8lf\t% 12.8lf\n", x[i], V[i]);
//    }
//
//    return 0;
//}

int InputFunction(char *inputfile, double **x, double **V){

    char *comment = "#%\n";
    int i, rows, comment_flag, control;
    char *line, buffer[_MaxLineLength_];
    FILE *fd = fopen(inputfile, "r");

    if(inputfile == NULL){  
        fprintf(stderr, "ERROR: Inputfile \"%s\" couldn't be opened.\n", inputfile);
        exit(1);
    } 

    rows = 0;
    while(fgets(buffer, sizeof(buffer), fd) != NULL){

        // check if the first character in buffer is a comment char,
        //  if yes jump to next line
        comment_flag = 0;
        for(i=0; i<strlen(comment); ++i){
            if(buffer[0] == comment[i]){
                comment_flag = 1;
                break;
            }
        }
        if(comment_flag == 1) continue;

        // copy "buffer" with stripped comments to new buffer "line"
        line = strtok(buffer, comment);

        // remove leading white spaces and tabulators
        //  and skip empty lines
        while(isspace(*line)) line++;
        if(*line == 0) continue;

        // At this point the requested input line is stripped of 
        //  comments and blank lines. From here on the parsing starts:
        //printf("%s\n", line);
//-----------------------------------------------------------------------------------

        (*x) = realloc((*x), (rows + 1) * sizeof(double));
        (*V) = realloc((*V), (rows + 1) * sizeof(double));
         
        //(*x)[rows] = (double)rows;
        //(*V)[rows] = 2*(double)rows;

        control = sscanf(line, "%lf  %lf", &(*x)[rows], &(*V)[rows]);
        if(control != 2){
          fprintf(stderr, "ERROR: reading data from input-file \"%s\"\n", inputfile);
          exit(1);
        }

        ++rows;
    }
    fclose(fd);

    //for(i=0; i<rows; ++i){
    //    printf("% 12.8lf\t% 12.8lf\n", (*x)[i], (*V)[i]);
    //}

    return rows;
}
