
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

void delay(clock_t a)
{
    clock_t start;
    start = clock();
    while (clock() - start < a)
    {

    }
}  
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

int main()
{

    //L:Letadlova lod (Aircraft carrier)
    //B:Bitevní loď (Battleship)
    //T:Torpédoborec (Destroyer)
    //P:Ponorka (Corvette)

    int i, j, k = 0, y, x, pomoc_zn = 0, win = 0, lod_l[5][2], lod_b[4][2], lod_t[3][2], lod_p[2][2], a = 0, b = 0, c = 0, d = 0, probab, obti;
    char pole_h1[10][10], pole_h1v[10][10], pole_ai[10][10], pole_aiv[10][10], orientace[2], tempstr[10], str[20] = "Battleship", pomoc_zn2;
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

    graphics();
    
    delay(1500);
    system("cls");

    // Nekonečný ciklus
    for (;;)
    {
        system("cls");

        for (i = 0; i < 10; i++)
            printf("\n");

        for (i = 0; i < 30; i++)
            printf(" ");
        printf("1.Play Battleship!\n");

        for (i = 0; i < 30; i++)
            printf(" ");
        printf("2.Rules\n");
        pomoc_zn2 = getch();

        if (pomoc_zn2 == 49)
            break;

        if (pomoc_zn2 == 50)
        {
            system("cls");
            printf("Pravidla Hry:");
            printf("1. Musíte zničit nepřátelské lodě než soupeř zničí ty vaše.\n");
            printf("2. Lodě můžete položit do pole o velikosti 10x10\n");
            printf("3. Můžete pokládat lodě podle Orientace (Horizontálně či vertikálně)\n");
            printf("4. Můžete také pokládat lodě podle koordinací na poli (x a y) kde x je číslo řádku a y je číslo sloupce\n");
            printf("4. Lodě, které můžete pokládat jsou: Letadlova lod (5 jednotek), Bitevní loď (4 jednotky), Torpédoborec (3 jednotky) a Ponorka (2 jednotky)\n");
            printf("5. After placing your ships, you can attack the enemy area. To attack a area, enter its x y coordinate (separated by a space)\n");
            // Po tom co si vyberete pozici vašich lodí, můžete útočit na nepřátelské źe
            printf("6. Attack hit to the enemy ship is denoted by a 'H' and you get an extra turn\n");
            // 
            printf("7. Attack miss is denoted by a '*' and your turn ends\n");
            printf("Press ENTER to continue!");
            fflush(stdin);
            fgets(tempstr, sizeof(tempstr), stdin);
            continue;
        }
    }

    system("cls");
    for (i = 0; i < 10; i++)
        printf("\n");
    for (i = 0; i < 30; i++)
        printf(" ");
    printf("Select the obtiiculty level:\n");
    for (i = 0; i < 30; i++)
        printf(" ");
    printf("Amateur\n");
    for (i = 0; i < 30; i++)
        printf(" ");
    printf("Professional\n");
    for (i = 0; i < 30; i++)
        printf(" ");
    printf("Legend\n");
    pomoc_zn2 = getch();
    if (pomoc_zn2 == 49)
        obti = 9;
    if (pomoc_zn2 == 50)
        obti = 8;
    if (pomoc_zn2 == 51)
        obti = 6;
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
                    pole_h1[y][i] = 'A';
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
                    pole_h1[i][x] = 'A';
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
        if (strcmp(orientace, "h") == 0)
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
        if (strcmp(orientace, "v") == 0)
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
        if (strcmp(orientace, "h") == 0)
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
        if (strcmp(orientace, "v") == 0)
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
        if (strcmp(orientace, "h") == 0)
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
        if (strcmp(orientace, "v") == 0)
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
    printf("Press ENTER to continue!");
    fflush(stdin);
    fgets(tempstr, sizeof(tempstr), stdin);
    srand(time(NULL));

    /*Letadlova lod CPU*/

    for (;;)
    {
        if (rand() % 2 == 1)
            strcpy_s(orientace, "h");
        else strcpy_s(orientace, "v");
        y = rand() % 10;
        x = rand() % 10;
        if (strcmp(orientace, "h") == 0)
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
        if (strcmp(orientace, "v") == 0)
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
        else strcpy_s(orientace, "v");
        y = rand() % 10;
        x = rand() % 10;
        if (strcmp(orientace, "h") == 0)
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
        if (strcmp(orientace, "v") == 0)
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
        else strcpy_s(orientace, "v");
        y = rand() % 10;
        x = rand() % 10;
        if (strcmp(orientace, "h") == 0)
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
                        pole_ai[y][i] = 'D';
                    break;
                }
            }
        }
        if (strcmp(orientace, "v") == 0)
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
                        pole_ai[i][x] = 'D';
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
        if (strcmp(orientace, "h") == 0)
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
                        pole_ai[y][i] = 'C';
                    break;
                }
            }
        }
        if (strcmp(orientace, "v") == 0)
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
                        pole_ai[i][x] = 'C';
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
            scanf("%d %d", &y, &x);
            if (y > 9 || y < 0 || x>9 || x < 0 || pole_aiv[y][x] == 'H' || pole_aiv[y][x] == '*')
            {
                printf("Spatny vstup. Zkuste znovu!\n");
                continue;
            }
            else
            {
                if (pole_ai[y][x] == 'A' || pole_ai[y][x] == 'B' || pole_ai[y][x] == 'C' || pole_ai[y][x] == 'D')
                {
                    if (pole_aiv[y][x] != 'H')
                    {
                        pole_aiv[y][x] = 'H';
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
                                if (pole_aiv[i][j] == 'H')
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
                    pole_aiv[y][x] = '*';
                    break;
                }
            }
        }

        for (;;)
        {
            probab = rand() % obti;
            if (probab == obti - 3 && a < 5)
            {
                y = lod_l[a][0];
                x = lod_l[a][1];
                a++;
            }
            else if (probab == obti - 2 && b < 4)
            {
                y = lod_b[b][0];
                x = lod_b[b][1];
                b++;
            }
            else if (probab == obti - 5 && d < 3)
            {
                y = lod_t[d][0];
                x = lod_t[d][1];
                d++;
            }
            else if (probab == obti - 6 && c < 2)
            {
                y = lod_p[c][0];
                x = lod_p[c][1];
                c++;
            }
            else
            {
                y = rand() % 10;
                x = rand() % 10;
            }
            if (y > 9 || y < 0 || x>9 || x < 0 || pole_h1v[y][x] == 'H' || pole_h1v[y][x] == '*')
            {
                continue;
            }
            else
            {
                if (pole_h1[y][x] == 'A' || pole_h1[y][x] == 'B' || pole_h1[y][x] == 'C' || pole_h1[y][x] == 'D')
                {
                    if (pole_h1v[y][x] != 'H')
                    {
                        pole_h1v[y][x] = 'H';
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
                        delay(1000);
                        continue;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    pole_h1v[y][x] = '*';
                    break;
                }
            }

        }

        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                if (pole_aiv[i][j] == 'H')
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
                if (pole_h1v[i][j] == 'H')
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
