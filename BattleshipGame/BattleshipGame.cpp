
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include "random_placement.h"
#include "Multiplayer.h"

//void delay(clock_t a);
void graphics();


int main()
{

    //L:Letadlova lod (Aircraft carrier)
    //B:Bitevní loď (Battleship)
    //T:Torpédoborec (Destroyer)
    //P:Ponorka (Corvette)

    int i, j, k = 0, y, x, pomoc_zn = 0, win = 0, lod_l[5][2], lod_b[4][2], lod_t[3][2], lod_p[2][2];
    char pole_h1[10][10], pole_h1v[10][10], pole_ai[10][10], pole_aiv[10][10], orientace[2], tempstr[10], pomoc_zn2;
    /*
    for (i = 0; i < 10; i++)
    {
        printf("\n");
    }

    for (i = 0; i < 30; i++)
    {
        printf(" ");
    }

    for (i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
        delay(60);
    }

    printf("\n");

    for (i = 0; i < 30; i++)
    {
        printf(" ");
    }
    */
    
    //delay(1500);
    system("cls");

    // Nekonečný ciklus
    for (;;)
    {
        system("cls");

        printf("\n\n");
        graphics();
        printf("\n\n");
        for (i = 0; i < 30; i++)
            printf(" ");
        printf("1.Hrat Singleplayer\n");

        for (i = 0; i < 30; i++)
            printf(" ");
        printf("2.Hrat Multiplayer\n");
        pomoc_zn2 = getch();

        if (pomoc_zn2 == 49)
            break;

        if (pomoc_zn2 == 50)
        {
            system("cls");
            multiplayer();
            return 0;
        }
    }

    system("cls");
    for (i = 0; i < 10; i++)
        printf("\n");
    for (i = 0; i < 30; i++)
        printf(" ");
    printf("Chcete naskladat lode nahodne?:\n");
    for (i = 0; i < 30; i++)
        printf(" ");
    printf("1. Ano\n");
    for (i = 0; i < 30; i++)
        printf(" ");
    printf("2. Ne\n");
    pomoc_zn2 = getch();
    if (pomoc_zn2 == 49) {
        random_placement();
    }
    else
        system("cls");
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            pole_ai[i][j] = '.';
            pole_h1[i][j] = '.';
            pole_aiv[i][j] = '.';
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
    printf("Stisknete ENTER pro pokracovani!");
    fflush(stdin);
    fgets(tempstr, sizeof(tempstr), stdin);
    srand(time(NULL));

    /*Letadlova lod CPU*/
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
    return 0;
}

//void delay(clock_t a)
//{
//    clock_t start;
//    start = clock();
//    while (clock() - start < a)
//    {
//
//    }
//}

void graphics() {

    printf("                                _      _    \n");
    printf("                                \\\\____//    \n");
    printf("                                 \\____/    \n");
    printf(" _        _____     _______      ________    \n");
    printf("| |      |  _  |    |      \\     |   ___|    \n");
    printf("| |      | | | |    | |	 |  \\    |  |____    \n");
    printf("| |      | | | |    | |  |  |    |  ____|    \n");
    printf("| |___   | |_| |    | |__|  /    |  |___     \n");
    printf("|_____|  |_____|    |______/     |______|    \n");
}