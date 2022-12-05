//Multiplayer

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include "Multiplayer.h"

void multiplayer() {

    int i, j, k = 0, n = 2, y, x, pomoc_zn = 0, win = 0, lod_l[5][2], lod_b[4][2], lod_t[3][2], lod_p[2][2], lod_l2[5][2], lod_b2[4][2], lod_t2[3][2], lod_p2[2][2], a = 0, b = 0, c = 0, d = 0, probab, obti;
    char pole_h1[10][10], pole_h1v[10][10], pole_h2[10][10], pole_h2v[10][10], orientace[2], tempstr[10], str[20] = "Battleship", pomoc_zn2;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            pole_h2[i][j] = '.';
            pole_h1[i][j] = '.';
            pole_h2v[i][j] = '.';
        }
    }

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
            printf("%c ", pole_h1[i][j]);
        printf("\n");
    }

    /*Letadlova lod*/
    for (;;)
    {
        printf("Hrac 1:\n");
        printf("Letadlova lod:\n");
        printf("Orientace (Horizontalni: H / Vertikalni: V): ");
        scanf("%s", &orientace);
        printf("x a y souradnice (0-9): ");
        scanf("%d %d", &x, &y);
        if (strcmp(orientace, "h") == 0 || strcmp(orientace, "H") == 0)
        {
            if (x > 5 || x < 0 || y > 9 || y < 0)
            {
                printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                continue;
            }
            else
            {
                for (i = x; i < x + 5; i++)
                {
                    pole_h1[y][i] = 'L';
                    lod_l[k][0] = y;
                    lod_l[k][1] = i;
                    k++;
                }
                break;
            }
        }
        else
            printf("Zrejme jste nezadali spravny znak!\n");
        if (strcmp(orientace, "v") == 0 || strcmp(orientace, "V") == 0)
        {
            if (y > 5 || y < 0 || x > 9 || x < 0)
            {
                printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                continue;
            }
            else
            {
                for (i = y; i < y + 5; i++)
                {
                    pole_h1[i][x] = 'L';
                    lod_l[k][0] = i;
                    lod_l[k][1] = x;
                    k++;
                }
                break;
            }
        }
    }
    k = 0;
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
            printf("%c ", pole_h1[i][j]);
        printf("\n");
    }

    /*B:Bitevni lod*/

    for (;;)
    {
        pomoc_zn = 0;
        printf("Hrac 1:\n");
        printf("Bitevni lod:\n");
        printf("Orientace (Horizontalni: H / Vertikalni: V): ");
        scanf("%s", &orientace);
        printf("x a y souradnice (0-9): ");
        scanf("%d %d", &x, &y);
        if (strcmp(orientace, "h") == 0 || strcmp(orientace, "H") == 0)
        {
            if (x > 6 || x < 0 || y>9 || y < 0)
            {
                printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                continue;
            }
            else
            {

                for (i = x; i < x + 4; i++)
                {
                    if (pole_h1[y][i] != '.')
                    {
                        printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                        pomoc_zn = 1;
                        break;
                    }
                }
                if (pomoc_zn == 1)
                    continue;
                else
                {
                    for (i = x; i < x + 4; i++)
                    {
                        pole_h1[y][i] = 'B';
                        lod_b[k][0] = y;
                        lod_b[k][1] = i;
                        k++;
                    }
                    break;
                }
            }
        }
        if (strcmp(orientace, "v") == 0 || strcmp(orientace, "V") == 0)
        {
            if (y > 6 || y < 0 || x>9 || x < 0)
            {
                printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                continue;
            }
            else
            {
                for (i = y; i < y + 4; i++)
                {
                    if (pole_h1[i][x] != '.')
                    {
                        printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                        pomoc_zn = 1;
                        break;
                    }
                }
                if (pomoc_zn == 1)
                    continue;
                else
                {
                    for (i = y; i < y + 4; i++)
                    {
                        pole_h1[i][x] = 'B';
                        lod_b[k][0] = i;
                        lod_b[k][1] = x;
                        k++;
                    }
                    break;
                }
            }
        }
    }
    k = 0;
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
            printf("%c ", pole_h1[i][j]);
        printf("\n");
    }

    /*Torpedoborec*/
    for (;;)
    {
        pomoc_zn = 0;
        printf("Hrac 1:\n");
        printf("Torpedoborec:\n");
        printf("Orientace (Horizontalni: H / Vertikalni: V): ");
        scanf("%s", &orientace);
        printf("x a y souradnice (0-9): ");
        scanf("%d %d", &x, &y);
        if (strcmp(orientace, "h") == 0 || strcmp(orientace, "H") == 0)
        {
            if (x > 7 || x < 0 || y>9 || y < 0)
            {
                printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                continue;
            }
            else
            {
                for (i = x; i < x + 3; i++)
                {
                    if (pole_h1[y][i] != '.')
                    {
                        printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                        pomoc_zn = 1;
                        break;
                    }
                }
                if (pomoc_zn == 1)
                    continue;
                else
                {
                    for (i = x; i < x + 3; i++)
                    {
                        pole_h1[y][i] = 'T';
                        lod_t[k][0] = y;
                        lod_t[k][1] = i;
                        k++;
                    }
                    break;
                }
            }
        }
        if (strcmp(orientace, "v") == 0 || strcmp(orientace, "V") == 0)
        {
            if (y > 7 || y < 0 || x>9 || x < 0)
            {
                printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                continue;
            }
            else
            {
                for (i = y; i < y + 3; i++)
                {
                    if (pole_h1[i][x] != '.')
                    {
                        printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                        pomoc_zn = 1;
                        break;
                    }
                }
                if (pomoc_zn == 1)
                    continue;
                else
                {
                    for (i = y; i < y + 3; i++)
                    {
                        pole_h1[i][x] = 'T';
                        lod_t[k][0] = i;
                        lod_t[k][1] = x;
                        k++;
                    }
                    break;
                }
            }
        }
    }
    k = 0;
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
            printf("%c ", pole_h1[i][j]);
        printf("\n");
    }

    /*Ponorka*/

    for (;;)
    {
        pomoc_zn = 0;
        printf("Hrac 1:\n");
        printf("Ponorka:\n");
        printf("Orientace (Horizontalni: H / Vertikalni: V): ");
        scanf("%s", &orientace);
        printf("x a y souradnice (0-9): ");
        scanf("%d %d", &x, &y);
        if (strcmp(orientace, "h") == 0 || strcmp(orientace, "H") == 0)
        {
            if (x > 8 || x < 0 || y>9 || y < 0)
            {
                printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                continue;
            }
            else
            {
                for (i = x; i < x + 2; i++)
                {
                    if (pole_h1[y][i] != '.')
                    {
                        printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                        pomoc_zn = 1;
                        break;
                    }
                }
                if (pomoc_zn == 1)
                    continue;
                else
                {
                    for (i = x; i < x + 2; i++)
                    {
                        pole_h1[y][i] = 'P';
                        lod_p[k][0] = y;
                        lod_p[k][1] = i;
                        k++;
                    }
                    break;
                }
            }
        }

        if (strcmp(orientace, "v") == 0 || strcmp(orientace, "V") == 0)
        {
            if (y > 8 || y < 0 || x>9 || x < 0)
            {
                printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                continue;
            }
            else
            {
                for (i = y; i < y + 2; i++)
                {
                    if (pole_h1[i][x] != '.')
                    {
                        printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                        pomoc_zn = 1;
                        break;
                    }
                }
                if (pomoc_zn == 1)
                    continue;
                else
                {
                    for (i = y; i < y + 2; i++)
                    {
                        pole_h1[i][x] = 'P';
                        lod_p[k][0] = i;
                        lod_p[k][1] = x;
                        k++;
                    }
                    break;
                }
            }
        }
    }
    system("cls");
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            pole_h2[i][j] = '.';
            pole_h1[i][j] = '.';
            pole_h2v[i][j] = '.';
        }
    }

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
            printf("%c ", pole_h1[i][j]);
        printf("\n");
    }

    /*Letadlova lod*/
    for (;;)
    {
        printf("Hrac 2:\n");
        printf("Letadlova lod:\n");
        printf("Orientace (Horizontalni: H / Vertikalni: V): ");
        scanf("%s", &orientace);
        printf("x a y souradnice (0-9): ");
        scanf("%d %d", &x, &y);
        if (strcmp(orientace, "h") == 0 || strcmp(orientace, "H") == 0)
        {
            if (x > 5 || x < 0 || y > 9 || y < 0)
            {
                printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                continue;
            }
            else
            {
                for (i = x; i < x + 5; i++)
                {
                    pole_h2[y][i] = 'A';
                    lod_l2[k][0] = y;
                    lod_l2[k][1] = i;
                    k++;
                }
                break;
            }
        }
        else
            printf("Zrejme jste nezadali spravny znak!\n");
        if (strcmp(orientace, "v") == 0 || strcmp(orientace, "V") == 0)
        {
            if (y > 5 || y < 0 || x > 9 || x < 0)
            {
                printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                continue;
            }
            else
            {
                for (i = y; i < y + 5; i++)
                {
                    pole_h2[i][x] = 'A';
                    lod_l2[k][0] = i;
                    lod_l2[k][1] = x;
                    k++;
                }
                break;
            }
        }
    }

    k = 0;
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
            printf("%c ", pole_h2[i][j]);
        printf("\n");
    }

    /*B:Bitevni lod*/

    for (;;)
    {
        pomoc_zn = 0;
        printf("Hrac 2:\n");
        printf("Bitevni lod:\n");
        printf("Orientace (Horizontalni: H / Vertikalni: V): ");
        scanf("%s", &orientace);
        printf("x a y souradnice (0-9): ");
        scanf("%d %d", &x, &y);
        if (strcmp(orientace, "h") == 0 || strcmp(orientace, "H") == 0)
        {
            if (x > 6 || x < 0 || y>9 || y < 0)
            {
                printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                continue;
            }
            else
            {

                for (i = x; i < x + 4; i++)
                {
                    if (pole_h2[y][i] != '.')
                    {
                        printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                        pomoc_zn = 1;
                        break;
                    }
                }
                if (pomoc_zn == 1)
                    continue;
                else
                {
                    for (i = x; i < x + 4; i++)
                    {
                        pole_h2[y][i] = 'B';
                        lod_b2[k][0] = y;
                        lod_b2[k][1] = i;
                        k++;
                    }
                    break;
                }
            }
        }
        if (strcmp(orientace, "v") == 0 || strcmp(orientace, "V") == 0)
        {
            if (y > 6 || y < 0 || x>9 || x < 0)
            {
                printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                continue;
            }
            else
            {
                for (i = y; i < y + 4; i++)
                {
                    if (pole_h2[i][x] != '.')
                    {
                        printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                        pomoc_zn = 1;
                        break;
                    }
                }
                if (pomoc_zn == 1)
                    continue;
                else
                {
                    for (i = y; i < y + 4; i++)
                    {
                        pole_h2[i][x] = 'B';
                        lod_b2[k][0] = i;
                        lod_b2[k][1] = x;
                        k++;
                    }
                    break;
                }
            }
        }
    }
        k = 0;
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
                printf("%c ", pole_h2[i][j]);
            printf("\n");
        }

        /*Torpedoborec*/
        for (;;)
        {
            pomoc_zn = 0;
            printf("Hrac 2:\n");
            printf("Torpedoborec:\n");
            printf("Orientace (Horizontalni: H / Vertikalni: V): ");
            scanf("%s", &orientace);
            printf("x a y souradnice (0-9): ");
            scanf("%d %d", &x, &y);
            if (strcmp(orientace, "h") == 0 || strcmp(orientace, "H") == 0)
            {
                if (x > 7 || x < 0 || y>9 || y < 0)
                {
                    printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                    continue;
                }
                else
                {
                    for (i = x; i < x + 3; i++)
                    {
                        if (pole_h2[y][i] != '.')
                        {
                            printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                            pomoc_zn = 1;
                            break;
                        }
                    }
                    if (pomoc_zn == 1)
                        continue;
                    else
                    {
                        for (i = x; i < x + 3; i++)
                        {
                            pole_h2[y][i] = 'T';
                            lod_t2[k][0] = y;
                            lod_t2[k][1] = i;
                            k++;
                        }
                        break;
                    }
                }
            }
            if (strcmp(orientace, "v") == 0 || strcmp(orientace, "V") == 0)
            {
                if (y > 7 || y < 0 || x>9 || x < 0)
                {
                    printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                    continue;
                }
                else
                {
                    for (i = y; i < y + 3; i++)
                    {
                        if (pole_h2[i][x] != '.')
                        {
                            printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                            pomoc_zn = 1;
                            break;
                        }
                    }
                    if (pomoc_zn == 1)
                        continue;
                    else
                    {
                        for (i = y; i < y + 3; i++)
                        {
                            pole_h2[i][x] = 'T';
                            lod_t2[k][0] = i;
                            lod_t2[k][1] = x;
                            k++;
                        }
                        break;
                    }
                }
            }
        }
        k = 0;
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
                printf("%c ", pole_h2[i][j]);
            printf("\n");
        }

        /*Ponorka*/

        for (;;)
        {
            pomoc_zn = 0;
            printf("Hrac 2:\n");
            printf("Ponorka:\n");
            printf("Orientace (Horizontalni: H / Vertikalni: V): ");
            scanf("%s", &orientace);
            printf("x a y souradnice (0-9): ");
            scanf("%d %d", &x, &y);
            if (strcmp(orientace, "h") == 0 || strcmp(orientace, "H") == 0)
            {
                if (x > 8 || x < 0 || y>9 || y < 0)
                {
                    printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                    continue;
                }
                else
                {
                    for (i = x; i < x + 2; i++)
                    {
                        if (pole_h2[y][i] != '.')
                        {
                            printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                            pomoc_zn = 1;
                            break;
                        }
                    }
                    if (pomoc_zn == 1)
                        continue;
                    else
                    {
                        for (i = x; i < x + 2; i++)
                        {
                            pole_h2[y][i] = 'P';
                            lod_p2[k][0] = y;
                            lod_p2[k][1] = i;
                            k++;
                        }
                        break;
                    }
                }
            }
            if (strcmp(orientace, "v") == 0 || strcmp(orientace, "V") == 0)
            {
                if (y > 8 || y < 0 || x>9 || x < 0)
                {
                    printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                    continue;
                }
                else
                {
                    for (i = y; i < y + 2; i++)
                    {
                        if (pole_h2[i][x] != '.')
                        {
                            printf("Zde nemuzete polozit lod! Zkuste znovu!\n");
                            pomoc_zn = 1;
                            break;
                        }
                    }
                    if (pomoc_zn == 1)
                        continue;
                    else
                    {
                        for (i = y; i < y + 2; i++)
                        {
                            pole_h2[i][x] = 'P';
                            lod_p2[k][0] = i;
                            lod_p2[k][1] = x;
                            k++;
                        }
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
                    printf("%c ", pole_h2v[i][j]);
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
                printf("Hraje hrac 1!\n");
                printf("Zadejte x a y: ");
                scanf("%d %d", &x, &y);
                if (y > 9 || y < 0 || x>9 || x < 0 || pole_h2v[y][x] == 'X' || pole_h2v[y][x] == '0')
                {
                    printf("Spatny vstup. Zkuste znovu!\n");
                    continue;
                }
                else
                {
                    if (pole_h2[y][x] == 'L' || pole_h2[y][x] == 'B' || pole_h2[y][x] == 'T' || pole_h2[y][x] == 'P')
                    {
                        if (pole_h2v[y][x] != 'X')
                        {
                            pole_h2v[y][x] = 'X';
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
                                    printf("%c ", pole_h2v[i][j]);
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
                                    if (pole_h2v[i][j] == 'X')
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
                        pole_h2v[y][x] = '0';
                        break;
                    }
                }
            }

            for (;;)
            {
                printf("Hraje hrac 2!\n");
                printf("Zadejte x a y: ");
                scanf("%d %d", &x, &y);
                if (y > 9 || y < 0 || x>9 || x < 0 || pole_h1v[y][x] == 'X' || pole_h1v[y][x] == '0')
                {
                    printf("Spatny vstup. Zkuste znovu!\n");
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
                                    printf("%c ", pole_h1v[i][j]);
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
                                    printf("%c ", pole_h2v[i][j]);
                                printf("\n");
                            }
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
                        pole_h1v[y][x] = '0';
                        break;
                    }
                }
            }
        }
}