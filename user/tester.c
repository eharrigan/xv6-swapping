// Do not modify this file. It will be replaced by the grading scripts
// when checking your project.

#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    char blah[4096];

    char blah2[4096];
    *(blah2 + 16000) = 1;
    printf(1, "blah 1 addr: %x\n blah 2 addr: %x\n", blah, blah2);
    exit();
}
