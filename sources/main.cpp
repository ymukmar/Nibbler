#include "game.h"

extern short sDirection;

void    init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0 );
    initGrid(COLUMNS, ROWS);
}

void    display_callback()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    drawSnake();
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

void    timer_callback(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/FPS, timer_callback, 0);
}

void    keyboard_callback(int key, int, int)
{
    switch(key)
    {
        case GLUT_KEY_UP:
            if (sDirection != DOWN)
                sDirection = UP;
            break;

        case GLUT_KEY_DOWN:
            if (sDirection != UP)
                sDirection = DOWN;
            break;

        case GLUT_KEY_LEFT:
            if (sDirection != RIGHT)
                sDirection = LEFT;
            break;

        case GLUT_KEY_RIGHT:
            if (sDirection != LEFT)
                sDirection = RIGHT;
            break;
    }
}

int     main(int argc, char **argv)
{
    void    *lib_handle;
    void    *fn;

    if ((lib_handle = dlopen("./libs/lib_check.so", RTLD_LAZY)))
    {
        fn = dlsym(lib_handle, "ft_init");
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGB);
        glutInitWindowSize(500, 500 );
        glutCreateWindow("NIBBLER");
        glutDisplayFunc(display_callback);
        glutReshapeFunc(reshape_callback);
        glutTimerFunc(0, timer_callback, 0);
        glutSpecialFunc(keyboard_callback);
        ((void*(*)(void))fn)();
        init();
        glutMainLoop();
    }
    else
        std::cout << "Failed to open Library\n";
    return 0;
}