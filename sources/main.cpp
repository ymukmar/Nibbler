#include "game.h"

void    init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0 );
    initGrid(COLUMNS, ROWS);
}

void    display_callback()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void    reshape_callback(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0 );
    glMatrixMode(GL_MODELVIEW);
}

int     main(int argc, char **argv)
{
    void    *lib_handle;
    void    *fn;

    lib_handle = dlopen("/goinfre/ymukmar/Desktop/Murk/Nibbler-Glut/Nibbler/libs/lib_check.so", RTLD_LAZY);
    fn = dlsym(lib_handle, "ft_init");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500, 500 );
    glutCreateWindow("NIBBLER");
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    ((void*(*)(void))fn)();
    init();
    glutMainLoop();
    return 0;
}