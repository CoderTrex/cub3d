#include "../../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_RELEASE 3
#define X_EVENT_KEY_EXIT 17

#define KEY_ESC 53
#define KEY_Q 12
#define KEY_W 13
#define KEY_E 14
#define KEY_R 15
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

#define mapWidth 24
#define mapHeight 24

#define screenWidth 640
#define screenHeight 480

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

#define IMG_WIDTH 400
#define IMG_HEIGHT 300

typedef struct s_img
{
    void    *img_ptr;
    int     *data;
    int     size_l;
    int     bpp;
    int     endian;
} t_img;


typedef struct s_mlx
{
    void *mlx_ptr;
    void *win;
} t_mlx;



typedef struct s_param{
    int x;
    int y;
    char str[3];
} t_param;

typedef struct s_game
{
    void *mlx;
    void **win;
    t_img img;
    int buf[screenHeight][screenWidth];
    int **texture;

    double posX;
    double posY;
    double dirX;
    double dirY;
    double planeX;
    double planeY;

    double moveSpeed;
    double rotSpeed;
} t_game;


void init_game(t_game *game)
{
    game->posX = 22.0;
    game->posY = 11.5;
    game->dirX = -1.0;
    game->dirY = 0.0;
    game->planeX = 0;
    game->planeY = 0.66;
    game->moveSpeed = 0.05;
    game->rotSpeed = 0.05;
}

int main()
{
    t_game game;

    init_game(&game);
    window_init();
    for (int i = 0; i < screenHeight; i++){
        for (int j = 0; j < screenWidth; j++){
            game.buf[i][j] = 0;
        }
    }
    if (!(game.texture = (int**)malloc(sizeof(int*) * 8)))
        return -1;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < tex)
    }
}





























