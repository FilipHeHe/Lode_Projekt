
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

void random_placement() {
    int i, j, k = 0, y, x, pomoc_zn = 0, win = 0, lod_l[5][2], lod_b[4][2], lod_t[3][2], lod_p[2][2];
    char pole_h1[10][10], pole_h1v[10][10], pole_ai[10][10], pole_aiv[10][10], orientace[2], tempstr[10], pomoc_zn2;

    for (;;)
    {
        if (rand() % 2 == 1)
            strcpy_s(orientace, "h");
        else
            strcpy_s(orientace, "v");
        y = rand() % 10;
        x = rand() % 10;
        if (strcmp(orientace, "h") == 0 || strcmp(orientace, "H") == 0)
        {
            if (x > 5 || x < 0 || y>9 || y < 0)
            {
                continue;
            }
            else
            {
                for (i = x; i < x + 5; i++)
                    pole_h1[y][i] = 'L';
                break;
            }
        }
        if (strcmp(orientace, "v") == 0 || strcmp(orientace, "V") == 0)
        {
            if (y > 5 || y < 0 || x>9 || x < 0)
            {
                continue;
            }
            else
            {
                for (i = y; i < y + 5; i++)
                    pole_h1[i][x] = 'L';
                break;
            }
        }
    }

    /*Bitevni lod CPU*/

    for (;;)
    {
        pomoc_zn = 0;
        if (rand() % 2 == 1)
            strcpy_s(orientace, "h");
        else
            strcpy_s(orientace, "v");
        y = rand() % 10;
        x = rand() % 10;
        if (strcmp(orientace, "h") == 0 || strcmp(orientace, "H") == 0)
        {
            if (x > 6 || x < 0 || y>9 || y < 0)
                continue;
            else
            {
                for (i = x; i < x + 4; i++)
                {
                    if (pole_h1[y][i] != '.')
                    {
                        pomoc_zn = 1;
                        break;
                    }
                }
                if (pomoc_zn == 1)
                    continue;
                else
                {
                    for (i = x; i < x + 4; i++)
                        pole_h1[y][i] = 'B';
                    break;
                }
            }
        }
        if (strcmp(orientace, "v") == 0 || strcmp(orientace, "V") == 0)
        {
            if (y > 6 || y < 0 || x>9 || x < 0)
            {
                continue;
            }
            else
            {
                for (i = y; i < y + 4; i++)
                {
                    if (pole_h1[i][x] != '.')
                    {
                        pomoc_zn = 1;
                        break;
                    }
                }
                if (pomoc_zn == 1)
                    continue;
                else
                {
                    for (i = y; i < y + 4; i++)
                        pole_h1[i][x] = 'B';
                    break;
                }
            }
        }
    }

    /*Torpedoborec CPU*/

    for (;;)
    {

        pomoc_zn = 0;
        if (rand() % 2 == 1)
            strcpy_s(orientace, "h");
        else
            strcpy_s(orientace, "v");
        y = rand() % 10;
        x = rand() % 10;
        if (strcmp(orientace, "h") == 0 || strcmp(orientace, "H") == 0)
        {
            if (x > 7 || x < 0 || y>9 || y < 0)
            {
                continue;
            }
            else
            {
                for (i = x; i < x + 3; i++)
                {
                    if (pole_h1[y][i] != '.')
                    {
                        pomoc_zn = 1;
                        break;
                    }
                }
                if (pomoc_zn == 1)
                    continue;
                else
                {
                    for (i = x; i < x + 3; i++)
                        pole_h1[y][i] = 'T';
                    break;
                }
            }
        }
        if (strcmp(orientace, "v") == 0 || strcmp(orientace, "V") == 0)
        {
            if (y > 7 || y < 0 || x>9 || x < 0)
            {
                continue;
            }
            else
            {
                for (i = y; i < y + 3; i++)
                {
                    if (pole_h1[i][x] != '.')
                    {
                        pomoc_zn = 1;
                        break;
                    }
                }
                if (pomoc_zn == 1)
                    continue;
                else
                {
                    for (i = y; i < y + 3; i++)
                        pole_h1[i][x] = 'T';
                    break;
                }
            }
        }
    }

    /*Ponorka CPU*/

    for (;;)
    {
        pomoc_zn = 0;
        if (rand() % 2 == 1)
            strcpy_s(orientace, "h");
        else
            strcpy_s(orientace, "v");
        y = rand() % 10;
        x = rand() % 10;
        if (strcmp(orientace, "h") == 0 || strcmp(orientace, "H") == 0)
        {
            if (x > 8 || x < 0 || y>9 || y < 0)
            {
                continue;
            }
            else
            {
                for (i = x; i < x + 2; i++)
                {
                    if (pole_h1[y][i] != '.')
                    {
                        pomoc_zn = 1;
                        break;
                    }
                }
                if (pomoc_zn == 1)
                    continue;
                else
                {
                    for (i = x; i < x + 2; i++)
                        pole_h1[y][i] = 'P';
                    break;
                }
            }
        }
        if (strcmp(orientace, "v") == 0 || strcmp(orientace, "V") == 0)
        {
            if (y > 8 || y < 0 || x>9 || x < 0)
            {
                continue;
            }
            else
            {
                for (i = y; i < y + 2; i++)
                {
                    if (pole_h1[i][x] != '.')
                    {
                        pomoc_zn = 1;
                        break;
                    }
                }
                if (pomoc_zn == 1)
                    continue;
                else
                {
                    for (i = y; i < y + 2; i++)
                        pole_h1[i][x] = 'P';
                    break;
                }
            }
        }
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
            pole_h1[i][j] = pole_h1[i][j];
    }
    for (;;)
    {
        if (rand() % 2 == 1)
            strcpy_s(orientace, "h");
        else
            strcpy_s(orientace, "v");
        y = rand() % 10;
        x = rand() % 10;
        if (strcmp(orientace, "h") == 0 || strcmp(orientace, "H") == 0)
        {
            if (x > 5 || x < 0 || y>9 || y < 0)
            {
                continue;
            }
            else
            {
                for (i = x; i < x + 5; i++)
                    pole_ai[y][i] = 'A';
                break;
            }
        }
        if (strcmp(orientace, "v") == 0 || strcmp(orientace, "V") == 0)
        {
            if (y > 5 || y < 0 || x>9 || x < 0)
            {
                continue;
            }
            else
            {
                for (i = y; i < y + 5; i++)
                    pole_ai[i][x] = 'A';
                break;
            }
        }
    }   

    /*Bitevni lod CPU*/

    for (;;)
    {
        pomoc_zn = 0;
        if (rand() % 2 == 1)
            strcpy_s(orientace, "h");
        else
            strcpy_s(orientace, "v");
        y = rand() % 10;
        x = rand() % 10;
        if (strcmp(orientace, "h") == 0 || strcmp(orientace, "H") == 0)
        {
            if (x > 6 || x < 0 || y>9 || y < 0)
                continue;
            else
            {
                for (i = x; i < x + 4; i++)
                {
                    if (pole_ai[y][i] != '.')
                    {
                        pomoc_zn = 1;
                        break;
                    }
                }
                if (pomoc_zn == 1)
                    continue;
                else
                {
                    for (i = x; i < x + 4; i++)
                        pole_ai[y][i] = 'B';
                    break;
                }
            }
        }
        if (strcmp(orientace, "v") == 0 || strcmp(orientace, "V") == 0)
        {
            if (y > 6 || y < 0 || x>9 || x < 0)
            {
                continue;
            }
            else
            {
                for (i = y; i < y + 4; i++)
                {
                    if (pole_ai[i][x] != '.')
                    {
                        pomoc_zn = 1;
                        break;
                    }
                }
                if (pomoc_zn == 1)
                    continue;
                else
                {
                    for (i = y; i < y + 4; i++)
                        pole_ai[i][x] = 'B';
                    break;
                }
            }
        }
    }

    /*Torpedoborec CPU*/

    for (;;)
    {
        pomoc_zn = 0;
        if (rand() % 2 == 1)
            strcpy_s(orientace, "h");
        else
            strcpy_s(orientace, "v");
        y = rand() % 10;
        x = rand() % 10;
        if (strcmp(orientace, "h") == 0 || strcmp(orientace, "H") == 0)
        {
            if (x > 7 || x < 0 || y>9 || y < 0)
            {
                continue;
            }
            else
            {
                for (i = x; i < x + 3; i++)
                {
                    if (pole_ai[y][i] != '.')
                    {
                        pomoc_zn = 1;
                        break;
                    }
                }
                if (pomoc_zn == 1)
                    continue;
                else
                {
                    for (i = x; i < x + 3; i++)
                        pole_ai[y][i] = 'T';
                    break;
                }
            }
        }
        if (strcmp(orientace, "v") == 0 || strcmp(orientace, "V") == 0)
        {
            if (y > 7 || y < 0 || x>9 || x < 0)
            {
                continue;
            }
            else
            {
                for (i = y; i < y + 3; i++)
                {
                    if (pole_ai[i][x] != '.')
                    {
                        pomoc_zn = 1;
                        break;
                    }
                }
                if (pomoc_zn == 1)
                    continue;
                else
                {
                    for (i = y; i < y + 3; i++)
                        pole_ai[i][x] = 'T';
                    break;
                }
            }
        }
    }

    /*Ponorka CPU*/

    for (;;)
    {
        pomoc_zn = 0;
        if (rand() % 2 == 1)
            strcpy_s(orientace, "h");
        else strcpy_s(orientace, "v");
        y = rand() % 10;
        x = rand() % 10;
        if (strcmp(orientace, "h") == 0 || strcmp(orientace, "H") == 0)
        {
            if (x > 8 || x < 0 || y>9 || y < 0)
            {
                continue;
            }
            else
            {
                for (i = x; i < x + 2; i++)
                {
                    if (pole_ai[y][i] != '.')
                    {
                        pomoc_zn = 1;
                        break;
                    }
                }
                if (pomoc_zn == 1)
                    continue;
                else
                {
                    for (i = x; i < x + 2; i++)
                        pole_ai[y][i] = 'P';
                    break;
                }
            }
        }
        if (strcmp(orientace, "v") == 0 || strcmp(orientace, "V") == 0)
        {
            if (y > 8 || y < 0 || x>9 || x < 0)
            {
                continue;
            }
            else
            {
                for (i = y; i < y + 2; i++)
                {
                    if (pole_ai[i][x] != '.')
                    {
                        pomoc_zn = 1;
                        break;
                    }
                }
                if (pomoc_zn == 1)
                    continue;
                else
                {
                    for (i = y; i < y + 2; i++)
                        pole_ai[i][x] = 'P';
                    break;
                }
            }
        }
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
            pole_h1v[i][j] = pole_h1[i][j];
    }

    for (;;)
    {
        system("cls");
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 30; j++)
                printf(" ");
            if (i == 0)
            {
                printf("  ");
                for (j = 0; j < 10; j++)
                    printf("%d ", j);
                printf("\n");
                for (j = 0; j < 30; j++)
                    printf(" ");
            }
            printf("%d ", i);
            for (j = 0; j < 10; j++)
                printf("%c ", pole_aiv[i][j]);
            printf("\n");
        }
        printf("\n");
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 30; j++)
                printf(" ");
            if (i == 0)
            {
                printf("  ");
                for (j = 0; j < 10; j++)
                    printf("%d ", j);
                printf("\n");
                for (j = 0; j < 30; j++)
                    printf(" ");
            }
            printf("%d ", i);
            for (j = 0; j < 10; j++)
                printf("%c ", pole_h1v[i][j]);
            printf("\n");
        }

        for (;;)
        {
            printf("Zadejte x a y: ");
            scanf("%d %d", &x, &y);
            if (y > 9 || y < 0 || x>9 || x < 0 || pole_aiv[y][x] == 'X' || pole_aiv[y][x] == '0')
            {
                printf("Spatny vstup. Zkuste znovu!\n");
                continue;
            }
            else
            {
                if (pole_ai[y][x] == 'L' || pole_ai[y][x] == 'B' || pole_ai[y][x] == 'T' || pole_ai[y][x] == 'P')
                {
                    if (pole_aiv[y][x] != 'X')
                    {
                        pole_aiv[y][x] = 'X';
                        system("cls");
                        for (i = 0; i < 10; i++)
                        {
                            for (j = 0; j < 30; j++)
                                printf(" ");
                            if (i == 0)
                            {
                                printf("  ");
                                for (j = 0; j < 10; j++)
                                    printf("%d ", j);
                                printf("\n");
                                for (j = 0; j < 30; j++)
                                    printf(" ");
                            }
                            printf("%d ", i);
                            for (j = 0; j < 10; j++)
                                printf("%c ", pole_aiv[i][j]);
                            printf("\n");
                        }
                        printf("\n");
                        for (i = 0; i < 10; i++)
                        {
                            for (j = 0; j < 30; j++)
                                printf(" ");
                            if (i == 0)
                            {
                                printf("  ");
                                for (j = 0; j < 10; j++)
                                    printf("%d ", j);
                                printf("\n");
                                for (j = 0; j < 30; j++)
                                    printf(" ");
                            }
                            printf("%d ", i);
                            for (j = 0; j < 10; j++)
                                printf("%c ", pole_h1v[i][j]);
                            printf("\n");
                        }
                        for (i = 0; i < 10; i++)
                        {
                            for (j = 0; j < 10; j++)
                            {
                                if (pole_aiv[i][j] == 'X')
                                    win++;
                            }
                        }
                        if (win == 14)
                        {
                            printf("\nZvitezil jsi!\n");
                            break;
                        }
                        win = 0;
                        continue;
                    }
                    else
                    {
                        printf("Spatny vstup. Zkuste znovu!\n");
                        continue;
                    }
                }
                else
                {
                    pole_aiv[y][x] = '0';
                    break;
                }
            }
        }

        for (;;)
        {
            y = rand() % 10;
            x = rand() % 10;

            if (y > 9 || y < 0 || x>9 || x < 0 || pole_h1v[y][x] == 'X' || pole_h1v[y][x] == '0')
            {
                continue;
            }
            else
            {
                if (pole_h1[y][x] == 'L' || pole_h1[y][x] == 'B' || pole_h1[y][x] == 'T' || pole_h1[y][x] == 'P')
                {
                    if (pole_h1v[y][x] != 'X')
                    {
                        pole_h1v[y][x] = 'X';
                        system("cls");
                        for (i = 0; i < 10; i++)
                        {
                            for (j = 0; j < 30; j++)
                                printf(" ");
                            if (i == 0)
                            {
                                printf("  ");
                                for (j = 0; j < 10; j++)
                                    printf("%d ", j);
                                printf("\n");
                                for (j = 0; j < 30; j++)
                                    printf(" ");
                            }
                            printf("%d ", i);
                            for (j = 0; j < 10; j++)
                                printf("%c ", pole_aiv[i][j]);
                            printf("\n");
                        }
                        printf("\n");
                        for (i = 0; i < 10; i++)
                        {
                            for (j = 0; j < 30; j++)
                                printf(" ");
                            if (i == 0)
                            {
                                printf("  ");
                                for (j = 0; j < 10; j++)
                                    printf("%d ", j);
                                printf("\n");
                                for (j = 0; j < 30; j++)
                                    printf(" ");
                            }
                            printf("%d ", i);
                            for (j = 0; j < 10; j++)
                                printf("%c ", pole_h1v[i][j]);
                            printf("\n");
                        }
                        //delay(1000);
                        continue;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    pole_h1v[y][x] = '0';
                    break;
                }
            }

        }

        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                if (pole_aiv[i][j] == 'X')
                    win++;
            }
        }

        if (win == 14)
        {
            printf("\n Zvitezil jsi!\n");
            break;
        }
        win = 0;

        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                if (pole_h1v[i][j] == 'X')
                    win++;
            }
        }

        if (win == 14)
        {
            printf("\n Prohral jsi!\n");
            break;
        }
        win = 0;
    }

}
