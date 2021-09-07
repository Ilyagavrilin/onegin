
#ifndef ONEGIN_FILES_FUNCS_H
#define ONEGIN_FILES_FUNCS_H

#include <stdio.h>
#include <assert.h>


#include "globals.h"

//---------------------------------------
FILE *FileComb (FILE *fname = NULL, char *name = NULL, char work_type = 'c', char op_type = 'r');
FILE *FileOpen (FILE *fname = NULL, char *name = NULL, char op_type = 'r');
int FileClose (FILE *fname = NULL);
void CopyNPaste ();
int InputToOutput (FILE *input, FILE *output);
int fget_string (FILE* stream, char *buf, size_t length);
//---------------------------------------

#endif //ONEGIN_FILES_FUNCS_H
