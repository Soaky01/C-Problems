#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
using namespace std;

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
void date_intrare(int &i);
char player1, player2, m[6][6];

HANDLE  hConsole;

int main()
{
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            m[i][j] = '#';

    FlushConsoleInputBuffer(hConsole);
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);

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

    return 0;
}

void date_intrare(int &i)
{

    int j1, j2;
    if (i % 2 == 0)
    {
        cout << "Player1:";
        cin >> j1 >> j2;
        if(m[j1][j2]=='#')m[j1][j2] = player1;
        else
        {
            cout<<"Poziie ocupata";
            date_intrare(i);
            i++;
        }
    }
    else
    {
        cout << "Player2:";
        cin >> j1 >> j2;
        if(m[j1][j2]=='#')m[j1][j2] = player2;
        else
        {
            cout<<"Poziie ocupata";
            date_intrare(i);
            i++;
        }
    }
    i++;
}
int verificare_5()
{

    if (verificare_linie_5() || verificare_coloana_5() || verificare_diag1_5() || verificare_diag2_5())return 0;
    else return 1;
}

int verificare_linie_5()
{

    for (int i = 1; i <= 5; i++)
    {
        if (m[i][2] == m[i][3] && m[i][2] == m[i][4] && (m[i][1] == m[i][2] || m[i][5] == m[i][2]) && m[i][2] != '#')
        {
            tipar_linie_5(i);
            return 1;
        }

    }
    return 0;
}
int verificare_coloana_5()
{

    for (int i = 1; i <= 5; i++)
    {
        if (m[2][i] == m[3][i] && m[2][i] == m[4][i] && (m[1][i] == m[2][i] || m[5][i] == m[2][i]) && m[2][i] != '#')
        {
            tipar_coloana_5(i);
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
    }
}
void tipar_diag1_5(int x)
{

    if(x==1)
    {
        for(int i=1; i<=5; i++)
        {
            for(int j=1; j<=5; j++)
            {
                if(m[1][1]==m[2][2])
                {
                    if(j==1)cout<<"|";
                    cout<<" ";
                    if(i==j && i!=5)
                    {
                        SetConsoleTextAttribute(hConsole, 10);
                        cout<<"\\";
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
                    if(j==1)cout<<"|";
                    cout<<" ";
                    if(i==j && i!=1)
                    {
                        SetConsoleTextAttribute(hConsole, 10);
                        cout<<"\\";
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
            cout<<endl;
        }
    }

    if (x == 2)
    {
        for(int i=1; i<=5; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                int ok=0;
                if (j == 1)cout << "|";
                cout << ' ';
                if((i==2 && j==3)||(i==3 && j==4)||(i==4 && j==5)||(i==1 && j==2))
                {
                    SetConsoleTextAttribute(hConsole, 10);
                    cout<<"\\";
                    ok=1;
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else
                {

                    if (m[i][j] != '#' && ok==0)cout << m[i][j];
                    else cout << " ";
                }
                cout << ' ' << "|";
            }
            cout<<endl;
        }
    }
    if(x==3)
    {

        for(int i=1; i<=5; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                int ok=0;
                if (j == 1)cout << "|";
                cout << ' ';
                if((i==3 && j==2)||(i==4 && j==3)||(i==5 && j==4)||(i==2 && j==1))
                {
                    SetConsoleTextAttribute(hConsole, 10);
                    cout<<"\\";
                    ok=1;
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else
                {

                    if (m[i][j] != '#' && ok==0)cout << m[i][j];
                    else cout << " ";
                }
                cout << ' ' << "|";
            }
            cout<<endl;
        }

    }
}
void tipar_diag2_5(int x)
{

    if(x==1)
    {
        for(int i=1; i<=5; i++)
        {
            for(int j=1; j<=5; j++)
            {
                if(m[1][5]==m[2][4])
                {
                    if(j==1)cout<<"|";
                    cout<<" ";
                    if(((i==1 && j==5)||(i==2 && j==4)||(i==3 && j==3)||(i==4 && j==2)) && !(i==5 && j==1))
                    {
                        SetConsoleTextAttribute(hConsole, 10);
                        cout<<"/";
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
                    if(j==1)cout<<"|";
                    cout<<" ";
                    if(((i==5 && j==1)||(i==2 && j==4)||(i==3 && j==3)||(i==4 && j==2)) && !(i==1 && j==5))
                    {
                        SetConsoleTextAttribute(hConsole, 10);
                        cout<<"/";
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
            cout<<endl;
        }
    }

    if (x == 2)
    {
        for(int i=1; i<=5; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                int ok=0;
                if (j == 1)cout << "|";
                cout << ' ';
                if((i==1 && j==4)||(i==4 && j==1)||(i==2 && j==3)||(i==3 && j==2))
                {
                    SetConsoleTextAttribute(hConsole, 10);
                    cout<<"/";
                    ok=1;
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else
                {

                    if (m[i][j] != '#' && ok==0)cout << m[i][j];
                    else cout << " ";
                }
                cout << ' ' << "|";
            }
            cout<<endl;
        }
    }
    if(x==3)
    {

        for(int i=1; i<=5; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                int ok=0;
                if (j == 1)cout << "|";
                cout << ' ';
                if((i==5 && j==2)||(i==2 && j==5)||(i==4 && j==3)||(i==3 && j==4))
                {
                    SetConsoleTextAttribute(hConsole, 10);
                    cout<<"/";
                    ok=1;
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else
                {

                    if (m[i][j] != '#' && ok==0)cout << m[i][j];
                    else cout << " ";
                }
                cout << ' ' << "|";
            }
            cout<<endl;
        }

    }
}
