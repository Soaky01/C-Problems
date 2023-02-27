#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
using namespace std;

void incepator();
void avansat();
void expert();
void tipar();
int verificare();
void tipar_linie(int x);
int  linie();
int diagonala_1();
void tipar_diagonala_1();
int diagonala_2();
void tipar_diagonala_2();
int coloana();
void tipar_coloana(int x);
int egalitate();
int verificare_linie();
int verificare_coloana();
int verificare_diagonala1();
int verificare_diagonala2();
void random();
void pozitie(int x, int& x1, int& x2);
void instructiuni();
void space();
int verificare_linie_5();
int verificare_coloana_5();
int draw();
void tipar5();
int verificare_diag2_5();
int verificare_diag1_5();
void tipar_linie_5(int x);
void tipar_coloana_5(int x);
void tipar_diag1_5(int x);
void tipar_diag2_5(int x);
int verificare_5();
void date_intrare(int& i);
char player1, player2;

char simbol_player, simbol_pc, m[6][6];
int nivel, pozitie_actuala, joc;
bool terminare = false;

HANDLE  hConsole;


int main()
{

    FlushConsoleInputBuffer(hConsole);
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);

    int i = 1;
    while (i <= 10)
    {
        cout << endl;
        i++;
    }
    space();
    cout << "|============================|";
    cout << endl;
    space();
    cout << "|                            |";
    cout << endl;
    space();
    cout << "|            Play            |";
    cout << endl;
    space();
    cout << "|                            |";
    cout << endl;
    space();
    cout << "|============================|";
    cout << endl;
    space();
    cout << "Press any key to continue...";
    cout << endl;
    getch();
    system("cls");

    cout << "Alegeti jocul dorit: " << endl;

    cout << "Tastati 1-X si 0 Clasic" << endl;
    cout << "Tastati 2-X si 0 de 5x5" << endl;
    cout << "Tastati 3-X si 0 3D" << endl;

    cin >> joc;
    system("cls");

    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            m[i][j] = '#';

    if (joc == 1)
    {
        cout << "1-Nivel:Incepator" << endl;
        cout << "2-Nivel:Avansat" << endl;
        cout << "3-Nivel:Expert" << endl;
        cout << "Alege Nivelul de dificultate" << endl;
        cin >> nivel;

        system("cls");

        cout << "Alege-ti simbolul X sau 0" << endl;
        cin >> simbol_player;
        cout << endl;

        system("cls");

        if (simbol_player == 'X')simbol_pc = '0';
        else
        {
            if (simbol_player == '0')simbol_pc = 'X';
            else
            {
                cout << "Am spus X sau 0,nu " << simbol_player;
                return 0;
            }
        }

        if (nivel == 1)
        {

            while (verificare() && !egalitate())
            {
                if (terminare)break;
                int i, j;
                tipar();
                cout << endl;
                cout << endl;
                instructiuni();
                cout << endl;
                cout << endl;
                cout << "Alege pozitia la care doresti sa pui " << simbol_player << endl;
                cin >> pozitie_actuala;
                pozitie(pozitie_actuala, i, j);
                if (m[i][j] != '#')
                {
                    cout << "Pozitie ocupata" << endl;
                    cout << "Jucatorul cu simbolul " << simbol_pc << " a facut mutarea in locul tau!" << endl;
                    getch();
                    incepator();
                }
                else m[i][j] = simbol_player;
                incepator();
                system("cls");

            }


        }
        if (nivel == 2)
        {

            while (verificare() && !egalitate())
            {
                if (terminare)break;
                int i, j;
                tipar();
                cout << endl;
                cout << endl;
                instructiuni();
                cout << endl;
                cout << endl;
                cout << "Alege pozitia la care doresti sa pui " << simbol_player << endl;
                cin >> pozitie_actuala;
                pozitie(pozitie_actuala, i, j);
                if (m[i][j] != '#')
                {
                    cout << "Pozitie ocupata" << endl;
                    cout << "Jucatorul cu simbolul " << simbol_pc << " a facut mutarea in locul tau!" << endl;
                    getch();
                    avansat();
                }
                else m[i][j] = simbol_player;
                avansat();
                system("cls");

            }

        }
        if (nivel == 3)
        {
            while (verificare() && !egalitate())
            {
                if (terminare)break;
                int i, j;
                tipar();
                cout << endl;
                cout << endl;
                instructiuni();
                cout << endl;
                cout << endl;
                cout << "Alege pozitia la care doresti sa pui " << simbol_player << endl;
                cin >> pozitie_actuala;
                pozitie(pozitie_actuala, i, j);
                if (m[i][j] != '#')
                {
                    cout << "Pozitie ocupata" << endl;
                    cout << "Jucatorul cu simbolul " << simbol_pc << " a facut mutarea in locul tau!" << endl;
                    getch();
                    expert();
                }
                else m[i][j] = simbol_player;
                expert();
                system("cls");

            }

        }
    }

    if (joc == 2)
    {

        player1 = 'X';
        player2 = '0';
        int i = 0;
        bool final = true;
        while (verificare_5() && final)
        {
            tipar5();
            date_intrare(i);
            system("cls");
        }

    }

    if (joc == 3)
    {
        STARTUPINFO startInfo = {0};

        PROCESS_INFORMATION processInfo = {0};

       bool bSucces = CreateProcess(TEXT("D:\\Games\\X si 0\\X si 0.exe"),NULL,NULL,NULL,FALSE,NULL,NULL,
            NULL,&startInfo,&processInfo);

    if (bSucces)
    {
        cout<<"Process Started"<<endl;
        cout<<"Process ID:\t"<<processInfo.dwProcessId<<endl;
    }
    else
    {
        cout<<"ERROR to start the process:"<<GetLastError()<<endl;
    }

    cin.get();

    return 0;
    }
}

void incepator()
{
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
        {
            if (m[i][j] == '#')
            {
                m[i][j] = simbol_pc;
                i = j = 4;
            }

        }
}

void tipar()
{
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            if (j == 1)
            {
                cout << "|";
                cout << ' ';
            }
            if (m[i][j] == '#')SetConsoleTextAttribute(hConsole, 0);
            cout << m[i][j] << ' ';
            SetConsoleTextAttribute(hConsole, 15);
            cout << "| ";
        }
        cout << endl;
    }
}


int linie()
{

    for (int i = 1; i <= 3; i++)
    {

        if (m[i][1] == m[i][2] && m[i][1] == m[i][3] && m[i][1] != '#')
        {
            tipar_linie(i);
            return 1;
        }

    }
    return 0;
}
void tipar_linie(int x)
{
    char a;
    a = m[x][1];
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            if (i == x)
            {
                if (j == 1)cout << "|";
                SetConsoleTextAttribute(hConsole, 10);
                cout << "---";
                SetConsoleTextAttribute(hConsole, 15);
                cout << "|";

            }
            else
            {
                if (j == 1)cout << "|";
                cout << ' ';
                if (m[i][j] != '#')cout << m[i][j];
                else cout << " ";
                cout << ' ' << "|";

            }
        }

        cout << endl;
    }
    cout << "Jucatorul cu simbolul " << a << " a castigat!" << endl;
}
int diagonala_1()
{


    if (m[1][1] == m[2][2] && m[3][3] == m[1][1] && m[1][1] != '#')
    {
        tipar_diagonala_1();
        return 1;
    }
    return 0;

}
void tipar_diagonala_1()
{

    char a;
    a = m[1][1];
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            if (i == j)
            {
                if (j == 1)cout << "|";
                SetConsoleTextAttribute(hConsole, 10);
                cout << " \\ ";
                SetConsoleTextAttribute(hConsole, 15);
                cout << "| ";

            }
            else
            {
                if (j == 1)cout << "|";
                if (m[i][j] != '#')cout << ' ' << m[i][j] << ' ' << "| ";
                else cout << ' ' << " " << ' ' << "| ";
            }
        }

        cout << endl;
    }
    cout << "Jucatorul cu simbolul " << a << " a castigat!" << endl;


}
void tipar_diagonala_2()
{

    char a;
    a = m[1][3];
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            if (j == 3 - i + 1)
            {
                if (j == 1)cout << "|";
                SetConsoleTextAttribute(hConsole, 10);
                cout << " / ";
                SetConsoleTextAttribute(hConsole, 15);
                cout << "| ";

            }
            else
            {
                if (j == 1)cout << "|";
                if (m[i][j] != '#')cout << ' ' << m[i][j] << ' ' << "| ";
                else cout << " " << " " << " " << "| ";
            }
        }

        cout << endl;
    }
    cout << "Jucatorul cu simbolul " << a << " a castigat!" << endl;


}
int diagonala_2()
{


    int i = 1;
    if (m[1][3] == m[2][2] && m[2][2] == m[3][1] && m[2][2] != '#')
    {
        tipar_diagonala_2();
        return 1;
    }

    return 0;

}
int coloana()
{

    for (int i = 1; i <= 3; i++)
    {

        if (m[1][i] == m[2][i] && m[2][i] == m[3][i] && m[1][i] != '#')
        {
            tipar_coloana(i);
            return 1;
        }

    }
    return 0;

}
void tipar_coloana(int x)
{

    char a;
    a = m[x][x];
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            if (j == x)
            {
                if (j == 1)cout << "|";
                SetConsoleTextAttribute(hConsole, 10);
                cout << " | ";
                SetConsoleTextAttribute(hConsole, 15);
                cout << "|";

            }
            else
            {
                if (j == 1)cout << "|";
                if (m[i][j] != '#')cout << ' ' << m[i][j] << ' ' << "|";
                else cout << ' ' << ' ' << ' ' << "|";
            }
        }

        cout << endl;
    }
    cout << "Jucatorul cu simbolul " << a << " a castigat!" << endl;


}

int verificare()
{

    if (linie() || coloana() || diagonala_1() || diagonala_2()) return 0;
    return 1;
}


void avansat()
{

    random();
}

int egalitate()
{
    int ok = 0;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
            if (m[i][j] == '#')ok++;

    }

    if (ok == 1)
    {
        int i, j;
        tipar();
        cout << endl;
        cout << endl;
        instructiuni();
        cout << endl;
        cout << endl;
        cout << "Alege pozitia la care doresti sa pui " << simbol_player << endl;
        cin >> pozitie_actuala;
        pozitie(pozitie_actuala, i, j);
        if (m[i][j] != '#')
        {
            cout << "Pozitie ocupata" << endl;
            cout << "Jucatorul cu simbolul " << simbol_pc << " a facut mutarea in locul tau!" << endl;
            getch();
            if (nivel == 1)incepator();
            else
            {
                if (nivel == 2)avansat();
                else if (nivel == 3)expert();
            }
        }
        else m[i][j] = simbol_player;
        system("cls");
        if (verificare())
        {
            system("cls");
            tipar();
            cout << endl;
            cout << "Egalitate!" << endl;
            return 1;
        }
        else terminare = true;
    }
    if (ok == 0)
    {
        return 1;
    }
    return 0;
}

int mutare = 1;
void expert()
{
    mutare++;
    if (mutare == 1)
    {
        if (m[1][1] == simbol_player || m[1][3] == simbol_player || m[3][1] == simbol_player || m[3][3] == simbol_player)
        {
            m[2][2] = simbol_pc;
        }
        else
        {
            random();
        }
        mutare++;
    }
    else
    {
        if (verificare_linie() || verificare_coloana() || verificare_diagonala1() || verificare_diagonala2()) {}
        else
        {
            random();

        }
    }
}

int verificare_linie()
{

    char verificator = simbol_pc;
    for (int i = 1; i <= 3; i++)
    {
        if (m[i][1] == m[i][2] && m[i][3] == '#' && m[i][1] == verificator)
        {
            m[i][3] = simbol_pc;
            return 1;
        }
        else
        {
            if (m[i][1] == m[i][3] && m[i][2] == '#' && m[i][1] == verificator)
            {
                m[i][2] = simbol_pc;
                return 1;
            }
            else
            {
                if (m[i][2] == m[i][3] && m[i][1] == '#' && m[i][2] == verificator)
                {
                    m[i][1] = simbol_pc;
                    return 1;
                }
            }
        }
    }

    verificator = simbol_player;

    for (int i = 1; i <= 3; i++)
    {
        if (m[i][1] == m[i][2] && m[i][3] == '#' && m[i][1] == verificator)
        {
            m[i][3] = simbol_pc;
            return 1;
        }
        else
        {
            if (m[i][1] == m[i][3] && m[i][2] == '#' && m[i][1] == verificator)
            {
                m[i][2] = simbol_pc;
                return 1;
            }
            else
            {
                if (m[i][2] == m[i][3] && m[i][1] == '#' && m[i][2] == verificator)
                {
                    m[i][1] = simbol_pc;
                    return 1;
                }
            }
        }
    }

    return 0;
}
void random()
{
    int i, j;
    do
    {
        i = rand() % 3 + 1;
        j = rand() % 3 + 1;
    }
    while (m[i][j] != '#');
    m[i][j] = simbol_pc;

}
int verificare_coloana()
{

    char verificator = simbol_pc;
    for (int i = 1; i <= 3; i++)
    {
        if (m[1][i] == m[2][i] && m[3][i] == '#' && m[1][i] == verificator)
        {
            m[3][i] = simbol_pc;
            return 1;
        }
        else
        {
            if (m[1][i] == m[3][i] && m[2][i] == '#' && m[1][i] == verificator)
            {
                m[2][i] = simbol_pc;
                return 1;
            }
            else
            {
                if (m[2][i] == m[3][i] && m[1][i] == '#' && m[2][i] == verificator)
                {
                    m[1][i] = simbol_pc;
                    return 1;
                }
            }
        }
    }

    verificator = simbol_player;

    for (int i = 1; i <= 3; i++)
    {
        if (m[1][i] == m[2][i] && m[3][i] == '#' && m[1][i] == verificator)
        {
            m[3][i] = simbol_pc;
            return 1;
        }
        else
        {
            if (m[1][i] == m[3][i] && m[2][i] == '#' && m[1][i] == verificator)
            {
                m[2][i] = simbol_pc;
                return 1;
            }
            else
            {
                if (m[2][i] == m[3][i] && m[1][i] == '#' && m[2][i] == verificator)
                {
                    m[1][i] = simbol_pc;
                    return 1;
                }
            }
        }
    }

    return 0;
}
int verificare_diagonala1()
{

    char verificator = simbol_pc;

    if (m[3][3] == m[2][2] && m[1][1] == '#' && m[3][3] == verificator)
    {
        m[1][1] = simbol_pc;
        return 1;
    }
    if (m[1][1] == m[3][3] && m[2][2] == '#' && m[1][1] == verificator)
    {
        m[2][2] = simbol_pc;
        return 1;
    }
    if (m[1][1] == m[2][2] && m[3][3] == '#' && m[1][1] == verificator)
    {
        m[3][3] = simbol_pc;
        return 1;
    }

    verificator = simbol_player;

    if (m[3][3] == m[2][2] && m[1][1] == '#' && m[3][3] == verificator)
    {
        m[1][1] = simbol_pc;
        return 1;
    }
    if (m[1][1] == m[3][3] && m[2][2] == '#' && m[1][1] == verificator)
    {
        m[2][2] = simbol_pc;
        return 1;
    }
    if (m[1][1] == m[2][2] && m[3][3] == '#' && m[1][1] == verificator)
    {
        m[3][3] = simbol_pc;
        return 1;
    }

    return 0;

}
int verificare_diagonala2()
{

    char verificator = simbol_pc;

    if (m[3][1] == m[2][2] && m[1][3] == '#' && m[3][1] != '#')
    {
        m[1][3] = simbol_pc;
        return 1;
    }
    if (m[1][3] == m[3][1] && m[2][2] == '#' && m[1][3] != '#')
    {
        m[2][2] = simbol_pc;
        return 1;
    }
    if (m[1][3] == m[2][2] && m[3][1] == '#' && m[1][3] != '#')
    {
        m[3][1] = simbol_pc;
        return 1;
    }

    verificator = simbol_player;

    if (m[3][1] == m[2][2] && m[1][3] == '#' && m[3][1] != '#')
    {
        m[1][3] = simbol_pc;
        return 1;
    }
    if (m[1][3] == m[3][1] && m[2][2] == '#' && m[1][3] != '#')
    {
        m[2][2] = simbol_pc;
        return 1;
    }
    if (m[1][3] == m[2][2] && m[3][1] == '#' && m[1][3] != '#')
    {
        m[3][1] = simbol_pc;
        return 1;
    }

    return 0;
}
void pozitie(int x, int& x1, int& x2)
{

    switch (x)
    {
    case 7:
        x1 = 1;
        x2 = 1;
        return;
    case 8:
        x1 = 1;
        x2 = 2;
        return;
    case 9:
        x1 = 1;
        x2 = 3;
        return;
    case 4:
        x1 = 2;
        x2 = 1;
        return;
    case 5:
        x1 = 2;
        x2 = 2;
        return;
    case 6:
        x1 = 2;
        x2 = 3;
        return;
    case 1:
        x1 = 3;
        x2 = 1;
        return;
    case 2:
        x1 = 3;
        x2 = 2;
        return;
    case 3:
        x1 = 3;
        x2 = 3;
        return;
    }

}
void instructiuni()
{

    cout << "Folositi NUMPad-ul ca INPUT pentru tabla de joc:" << endl;
    cout << "| 7 | 8 | 9 | " << endl;
    cout << "| 4 | 5 | 6 | " << endl;
    cout << "| 1 | 2 | 3 | " << endl;

}

void space()
{
    int i = 1;
    while (i <= 45)
    {
        cout << " ";
        i++;
    }
}

void date_intrare(int& i)
{

    int j1, j2;
    if (i % 2 == 0)
    {
        cout << "Player1:";
        cin >> j1 >> j2;
        if (m[j1][j2] == '#')m[j1][j2] = player1;
        else
        {
            cout << "Poziie ocupata";
            date_intrare(i);
            i++;
        }
    }
    else
    {
        cout << "Player2:";
        cin >> j1 >> j2;
        if (m[j1][j2] == '#')m[j1][j2] = player2;
        else
        {
            cout << "Poziie ocupata";
            date_intrare(i);
            i++;
        }
    }
    i++;
}
int verificare_5()
{

    if (verificare_linie_5() || verificare_coloana_5() || verificare_diag1_5() || verificare_diag2_5())return 0;
    return 1;
}

int verificare_linie_5()
{

    for (int j = 1; j <= 5; j++)
    {
        if (m[j][2] == m[j][3] && m[j][2] == m[j][4] && (m[j][1] == m[j][2] || m[j][5] == m[j][2]) && m[j][2] != '#')
        {
            tipar_linie_5(j);
            return 1;
        }

    }
    return 0;
}
int verificare_coloana_5()
{

    for (int j = 1; j <= 5; j++)
    {
        if (m[2][j] == m[3][j] && m[2][j] == m[4][j] && (m[1][j] == m[2][j] || m[5][j] == m[2][j]) && m[2][j] != '#')
        {
            tipar_coloana_5(j);
            return 1;
        }

    }
    return 0;

}

int verificare_diag1_5()
{

    if (m[2][2] == m[3][3] && m[2][2] == m[4][4] && (m[2][2] == m[1][1] || m[2][2] == m[5][5]) && m[2][2] != '#')
    {
        tipar_diag1_5(1);
        return 1;
    }
    else if (m[1][2] == m[2][3] && m[1][2] == m[3][4] && m[1][2] == m[4][5] && m[1][2] != '#')
    {
        tipar_diag1_5(2);
        return 1;
    }
    else if (m[2][1] == m[3][2] && m[2][1] == m[4][3] && m[2][1] == m[5][4] && m[2][1] != '#')
    {
        tipar_diag1_5(3);
        return 1;
    }
    else return 0;

}
int verificare_diag2_5()
{

    if (m[2][4] == m[4][2] && m[3][3] == m[4][2] && (m[1][5] == m[3][3] || m[5][1] == m[3][3]) && m[3][3] != '#')
    {
        tipar_diag2_5(1);
        return 1;
    }
    else if (m[1][4] == m[2][3] && m[4][1] == m[2][3] && m[1][4] == m[4][1] && m[1][4] != '#')
    {
        tipar_diag2_5(2);
        return 1;
    }
    else if (m[2][5] == m[5][2] && m[4][3] == m[3][4] && m[2][5] == m[3][4] && m[3][4] != '#')
    {
        tipar_diag2_5(3);
        return 1;
    }
    else return 0;
}


void tipar5()
{


    for (int i = 1; i <= 5; ++i)
    {
        for (int j = 1; j <= 5; ++j)
        {
            if (j == 1)
            {
                cout << "|";
                cout << ' ';
            }
            if (m[i][j] == '#')SetConsoleTextAttribute(hConsole, 0);
            cout << m[i][j] << ' ';
            SetConsoleTextAttribute(hConsole, 15);
            cout << "| ";
        }
        cout << endl;
    }
}

void tipar_linie_5(int x)
{

    if (m[x][1] == m[x][2])
    {
        for (int i = 1; i <= 5; ++i)
        {
            for (int j = 1; j <= 5; ++j)
            {
                if (i == x)
                {
                    if (j == 1)cout << "|";
                    if (j == 5)
                    {
                        if (m[x][5] == '#')cout << "   ";
                        else cout << " " << m[i][j] << " ";
                    }
                    else
                    {
                        SetConsoleTextAttribute(hConsole, 10);
                        cout << "---";
                    }
                    SetConsoleTextAttribute(hConsole, 15);
                    cout << "|";
                }
                else
                {
                    if (j == 1)cout << "|";
                    cout << ' ';
                    if (m[i][j] != '#')cout << m[i][j];
                    else cout << " ";
                    cout << ' ' << "|";
                }

            }
            cout << "\n";
        }
        cout << "Jucatorul cu simbolul " << m[x][2] << " a castigat!";
    }
    else
    {
        for (int i = 1; i <= 5; ++i)
        {
            for (int j = 1; j <= 5; ++j)
            {
                if (i == x)
                {
                    if (j == 1)cout << "|";
                    if (j == 1)
                    {
                        if (m[x][1] == '#')cout << "   ";
                        else cout << " " << m[i][j] << " ";
                    }
                    else
                    {
                        SetConsoleTextAttribute(hConsole, 10);
                        cout << "---";
                    }
                    SetConsoleTextAttribute(hConsole, 15);
                    cout << "|";
                }
                else
                {
                    if (j == 1)cout << "|";
                    cout << ' ';
                    if (m[i][j] != '#')cout << m[i][j];
                    else cout << " ";
                    cout << ' ' << "|";
                }

            }
            cout << "\n";
        }
        cout << "Jucatorul cu simbolul " << m[x][2] << " a castigat!";
    }

}

void tipar_coloana_5(int x)
{

    if (m[1][x] == m[2][x])
    {
        for (int i = 1; i <= 5; ++i)
        {
            for (int j = 1; j <= 5; ++j)
            {
                if (j == x)
                {
                    if (j == 1)cout << "|";
                    if (i == 5)
                    {
                        if (m[5][x] == '#')cout << "   ";
                        else cout << " " << m[i][j] << " ";
                    }
                    else
                    {
                        SetConsoleTextAttribute(hConsole, 10);
                        cout << " | ";
                    }
                    SetConsoleTextAttribute(hConsole, 15);
                    cout << "|";
                }
                else
                {
                    if (j == 1)cout << "|";
                    cout << ' ';
                    if (m[i][j] != '#')cout << m[i][j];
                    else cout << " ";
                    cout << ' ' << "|";
                }

            }
            cout << "\n";
        }
        cout << "Jucatorul cu simbolul " << m[2][x] << " a castigat!";
    }
    else
    {
        for (int i = 1; i <= 5; ++i)
        {
            for (int j = 1; j <= 5; ++j)
            {
                if (j == x)
                {
                    if (j == 1)cout << "|";
                    if (i == 1)
                    {
                        if (m[1][x] == '#')cout << "   ";
                        else cout << " " << m[i][j] << " ";
                    }
                    else
                    {
                        SetConsoleTextAttribute(hConsole, 10);
                        cout << " | ";
                    }
                    SetConsoleTextAttribute(hConsole, 15);
                    cout << "|";
                }
                else
                {
                    if (j == 1)cout << "|";
                    cout << ' ';
                    if (m[i][j] != '#')cout << m[i][j];
                    else cout << " ";
                    cout << ' ' << "|";
                }

            }
            cout << "\n";
        }
        cout << "Jucatorul cu simbolul " << m[2][x] << " a castigat!";
    }
}
void tipar_diag1_5(int x)
{

    if (x == 1)
    {
        for (int i = 1; i <= 5; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                if (m[1][1] == m[2][2])
                {
                    if (j == 1)cout << "|";
                    cout << " ";
                    if (i == j && i != 5)
                    {
                        SetConsoleTextAttribute(hConsole, 10);
                        cout << "\\";
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                    else
                    {
                        if (m[i][j] != '#')cout << m[i][j];
                        else cout << " ";
                    }
                    cout << ' ' << "|";
                }
                else
                {
                    if (j == 1)cout << "|";
                    cout << " ";
                    if (i == j && i != 1)
                    {
                        SetConsoleTextAttribute(hConsole, 10);
                        cout << "\\";
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                    else
                    {
                        if (m[i][j] != '#')cout << m[i][j];
                        else cout << " ";
                    }
                    cout << ' ' << "|";

                }

            }
            cout << endl;
        }
        cout << "Jucatorul cu simbolul " << m[2][2] << " a castigat!";
    }

    if (x == 2)
    {
        for (int i = 1; i <= 5; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                int ok = 0;
                if (j == 1)cout << "|";
                cout << ' ';
                if ((i == 2 && j == 3) || (i == 3 && j == 4) || (i == 4 && j == 5) || (i == 1 && j == 2))
                {
                    SetConsoleTextAttribute(hConsole, 10);
                    cout << "\\";
                    ok = 1;
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else
                {

                    if (m[i][j] != '#' && ok == 0)cout << m[i][j];
                    else cout << " ";
                }
                cout << ' ' << "|";
            }
            cout << endl;
        }
        cout << "Jucatorul cu simbolul " << m[2][2] << " a castigat!";
    }
    if (x == 3)
    {

        for (int i = 1; i <= 5; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                int ok = 0;
                if (j == 1)cout << "|";
                cout << ' ';
                if ((i == 3 && j == 2) || (i == 4 && j == 3) || (i == 5 && j == 4) || (i == 2 && j == 1))
                {
                    SetConsoleTextAttribute(hConsole, 10);
                    cout << "\\";
                    ok = 1;
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else
                {

                    if (m[i][j] != '#' && ok == 0)cout << m[i][j];
                    else cout << " ";
                }
                cout << ' ' << "|";
            }
            cout << endl;
        }

    }
}
void tipar_diag2_5(int x)
{

    if (x == 1)
    {
        for (int i = 1; i <= 5; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                if (m[1][5] == m[2][4])
                {
                    if (j == 1)cout << "|";
                    cout << " ";
                    if (((i == 1 && j == 5) || (i == 2 && j == 4) || (i == 3 && j == 3) || (i == 4 && j == 2)) && !(i == 5 && j == 1))
                    {
                        SetConsoleTextAttribute(hConsole, 10);
                        cout << "/";
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                    else
                    {
                        if (m[i][j] != '#')cout << m[i][j];
                        else cout << " ";
                    }
                    cout << ' ' << "|";
                }
                else
                {
                    if (j == 1)cout << "|";
                    cout << " ";
                    if (((i == 5 && j == 1) || (i == 2 && j == 4) || (i == 3 && j == 3) || (i == 4 && j == 2)) && !(i == 1 && j == 5))
                    {
                        SetConsoleTextAttribute(hConsole, 10);
                        cout << "/";
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                    else
                    {
                        if (m[i][j] != '#')cout << m[i][j];
                        else cout << " ";
                    }
                    cout << ' ' << "|";

                }

            }
            cout << endl;
        }
    }

    if (x == 2)
    {
        for (int i = 1; i <= 5; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                int ok = 0;
                if (j == 1)cout << "|";
                cout << ' ';
                if ((i == 1 && j == 4) || (i == 4 && j == 1) || (i == 2 && j == 3) || (i == 3 && j == 2))
                {
                    SetConsoleTextAttribute(hConsole, 10);
                    cout << "/";
                    ok = 1;
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else
                {

                    if (m[i][j] != '#' && ok == 0)cout << m[i][j];
                    else cout << " ";
                }
                cout << ' ' << "|";
            }
            cout << endl;
        }
    }
    if (x == 3)
    {

        for (int i = 1; i <= 5; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                int ok = 0;
                if (j == 1)cout << "|";
                cout << ' ';
                if ((i == 5 && j == 2) || (i == 2 && j == 5) || (i == 4 && j == 3) || (i == 3 && j == 4))
                {
                    SetConsoleTextAttribute(hConsole, 10);
                    cout << "/";
                    ok = 1;
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else
                {

                    if (m[i][j] != '#' && ok == 0)cout << m[i][j];
                    else cout << " ";
                }
                cout << ' ' << "|";
            }
            cout << endl;
        }

    }
}
