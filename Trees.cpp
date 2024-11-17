#include <iostream>

using namespace std;

class graph
{

private:
    int cost[10][10];
    int tcities;

public:
    graph()
    {

        tcities = 0;
        cout << "Enter no of cities " << endl;
        cin >> tcities;

        for (int i = 0; i < tcities; i++)
        {
            for (int j = 0; j < tcities; j++)
            {

                cost[i][j] = 999; // default cost set to 999
            }
        }
    }
    void create();
    void display();
    void prims();
};

void graph ::create()
{
    char ch;

    for (int i = 0; i < tcities; i++)
    {
        for (int j = i + 1; j < tcities; j++)
        {
            cout << "IS THERE A CONNECTION BETWEEN " << i << " and " << j << "? (y/n)" << endl;
            cin >> ch;
            if (ch == 'y' || ch == 'Y')
            {

                cout << "Enter the cost: ";
                cin >> cost[i][j];
                cost[j][i] = cost[i][j]; // Update symmetric value
            }
        }
    }
}

void graph ::display()
{

    cout << "\nThe adjacency matrix is  " << endl;
    for (int i = 0; i < tcities; i++)
    {
        for (int j = 0; j < tcities; j++)
        {
            cout << cost[i][j] << "\t";
        }
        cout << endl;
    }
}

void graph ::prims()
{

    int start[tcities][2];
    int i, j, k;

    int r = 0;
    int min;
    int final = 0;
    int nearest[tcities];

    cout << "Enter starting vertex: ";
    cin >> start[0][0];

    nearest[start[0][0]] = -1;

    for (int i = 0; i < tcities - 1; i++)
    {

        if (i != start[0][0])
        {

            nearest[i] = start[0][0];
        }
    }

    for (i = 1; i < tcities; i++)
    {
        min = 999;

        for (k = 0; k < tcities; k++)
        {
            if ((nearest[k] != -1) && (cost[k][nearest[k]] < min))
            {

                j = k;
                min = cost[k][nearest[k]];
            }
        }

        start[r][0] = j;
        start[r][1] = nearest[j];
        r = r + 1;
        final = final + cost[j][nearest[j]];
        nearest[j] = -1;
        for (k = 0; k < tcities; k++)
        {
            if ((nearest[k] != -1) && (cost[k][nearest[k]] > cost[k][j]))
            {
                nearest[k] = j;
            }
        }
    }

    cout << "The spanning tree is as follows: \n";
    for (i = 0; i < tcities - 1; i++)
    {
        for(int j = 0;j< 2;j++){
                   cout <<start[i][j];
        }
        cout<<endl;
       
    }
    cout << "\nTotal cost of spanning tree: " << final << endl;
}

int main()
{

    graph g;

    g.create();
    g.display();
    g.prims();

    return 0;
}