#include "files_funcs.h"


FILE *FileComb (FILE *fname, char *name, char work_type, char op_type) {
    FILE *linker = NULL;

    if (work_type == 'o') {
        if ((linker = FileOpen (fname, name , op_type)) == NULL) {
            assert(linker != NULL);
        }
        return linker;
    }
    else if (work_type == 'c') {
        if (FileClose (fname) == ERROR) {
            assert(!"File didn't close");
        }
    }
    else {
        assert(NULL);
    }

    return NULL;
}
 FILE *FileOpen (FILE *fname, char *name, char op_type) {
    char operation[2] = "r";

    if (op_type == 'r' || op_type == 'w' || op_type == 'a') {
        operation[0] = op_type;
        fname = fopen (name, operation);
        return fname;
    }
    else {
        return NULL;
    }
}

int FileClose (FILE *fname) {
    assert(!fclose(fname));
    return 0;
}

void CopyNPaste() {
    FILE *fget = NULL;
    char name_get[] = "C:/Users/gavri/CLionProjects/onegin/get.txt";
    if ((fget = FileComb (fget, name_get, 'o', 'r')) == NULL) {
        printf("Error in opening file with text. \n");
    }

    FILE *fwrite = NULL;
    char name_write[] = "C:/Users/gavri/CLionProjects/onegin/write.txt";
    if ((fwrite = FileComb (fwrite, name_write, 'o', 'w')) == NULL) {
        printf("Error in opening file with text. \n");
    }

    if (InputToOutput(fget, fwrite) == ERROR) {
        printf("Error in running program.\n");
    }

    FileComb (fget, name_get, 'c', 'r');
    FileComb (fwrite, name_write, 'c', 'r');
}

int InputToOutput (FILE *input, FILE *output) {
    int is_eof = FALSE;

    while (is_eof != TRUE) {
        char buffer[MAX_LEN] = {0};

        is_eof = fget_string(input, buffer, MAX_LEN);
        if (is_eof == ERROR) {
            return ERROR;
        }

        fprintf(output, "%s\n", buffer);

    }

    return 0;
}
int fget_string (FILE* stream, char *buf, size_t length) {
    int i = 0;
    char symb = NULL;

    while((symb = fgetc(stream)) != '\n' && symb != EOF) {
        buf[i] = symb;

        i++;
        if (i > length) {
            return ERROR;
        }
    }

    if (symb == EOF) {
        return TRUE;
    }

    return FALSE;
}