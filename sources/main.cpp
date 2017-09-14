#include "game.h"


void    display_callback()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

int     main(int argc, char **argv)
{
    void    *lib_handle;
    void    *fn;

    lib_handle = dlopen("/goinfre/ymukmar/Desktop/Murk/Nibbler-Glut/Nibbler/libs/lib_check.so", RTLD_LAZY);
    fn = dlsym(lib_handle, "init");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500, 500 );
    glutCreateWindow("NIBBLER");
    glutDisplayFunc(display_callback);
    ((void*(*)(void))fn)();
    glutMainLoop();
    return 0;
}