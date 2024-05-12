#include"Headers/Graph.h"
#include"Headers/User_Interface.h"

/*
0 fail
1 success
2 the city was existing
*/
int User_Inrerface::AddCity(string nameOfCity , graph myGraph)
{
    // cout << "Enter the name of the city: ";
    //  cin >> nameOfCity;
    if (!(myGraph.checkcity(nameOfCity)))
    {

        myGraph.addcity(nameOfCity);
        return 1;
    }
    else
    {
        return 2;
    }
}
/*
0 fail
1 success
2 city 1 or 2 was not existing
3 the edge was existing
*/
int User_Inrerface::AddEdge(string nameOfCity1,string nameOfCity2,int distance, graph myGraph)
{

    //cout << "Enter the name of city 1: ";
    //cin >> nameOfCity1;
    //cout << "Enter the name of city 2: ";
    // cin >> nameOfCity2;
    //       cout << "Enter the distance (in KM): ";
    //     cin >> distance;
    if (myGraph.checkcity(nameOfCity1) && myGraph.checkcity(nameOfCity2)) {
        if (!(myGraph.checkedge(nameOfCity1, nameOfCity2)))
        {

            myGraph.addedge(nameOfCity1, nameOfCity2, distance);
            return 1;
        }
        else if (myGraph.checkedge(nameOfCity1, nameOfCity2))
        {
            return 3;
        }
        else
            return 0;
    }
    else if(!(myGraph.checkcity(nameOfCity1) && myGraph.checkcity(nameOfCity2)))
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
/*
0 fail
1 success
2 the city was not existing
*/
int User_Inrerface::DeleteCity(string nameCity, graph myGraph)
{
    // cout << "enter the name of city: ";
    //   cin >> nameCity;
    if (myGraph.checkcity(nameCity)) {
        myGraph.deletecity(nameCity);
        return 1;
    }
    else if (!myGraph.checkcity(nameCity))
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
/*
0 fail
1 success
2 city 1 or 2 was not existing
3 the edge was not existing
*/
int User_Inrerface::DeleteEdge(string nameOfCity1, string nameOfCity2, graph myGraph)
{
    //cout << "to delete edge you must enter two city /n";
    //cout << "enter  the city 1:";
    //cin >> cityName1;
    //cout << "enter  the city 2:";
    //cin >> cityName2;
    if (myGraph.checkcity(nameOfCity1) && myGraph.checkcity(nameOfCity2))
    {
        if (myGraph.checkedge(nameOfCity1, nameOfCity2))
        {
            myGraph.delete_edge(nameOfCity1, nameOfCity2);
            return 1;
        }
        else if (!(myGraph.checkedge(nameOfCity1, nameOfCity2)))
        {
            return 3;
        }
        else
        {
            return 0;
        }

    }
    else if (!(myGraph.checkcity(nameOfCity1) && myGraph.checkcity(nameOfCity2)))
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
/*
0 fail
1 success
2 city 1 or 2 was not existing
3 the edge was not existing
*/
int User_Inrerface::EditEdge(string nameOfCity1, string nameOfCity2,int distance, graph myGraph)
{
    if (myGraph.checkcity(nameOfCity1) && myGraph.checkcity(nameOfCity2))
    {
        if (myGraph.checkedge(nameOfCity1, nameOfCity2))
        {
            myGraph.update_edge(nameOfCity1, nameOfCity2,  distance);
            return 1;
        }
        else if (!(myGraph.checkedge(nameOfCity1, nameOfCity2)))
        {
            return 3;
        }
        else
        {
            return 0;
        }

    }
    else if (!(myGraph.checkcity(nameOfCity1) && myGraph.checkcity(nameOfCity2)))
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
/*
0 fail
1 success
2 the city was not existing
3 the new name was taken
*/
int User_Inrerface::UpName(string nameOfCity1, string nameOfCity2, graph myGraph)
{
    if (myGraph.checkcity(nameOfCity1))
    {
        if (!(myGraph.checkcity(nameOfCity2)))
        {
            myGraph.update_cityname(nameOfCity1,nameOfCity2);
            return 1;
        }
        else if (myGraph.checkcity(nameOfCity2))
        {
            return 3;
        }
        else
        {
            return 0;
        }
    }
    else if (!(myGraph.checkcity(nameOfCity1)))
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
/*
0 fail
1 success
*/
int User_Inrerface::ClearMap(graph myGraph)
{
    if (myGraph.checkmap())
    {
        myGraph.clearmap();
        return 1;
    }
    else
        return 0;
}
/*
0 fail
1 success
2 the city was existing
*/
int User_Inrerface::TraverDfs(string nameofcity, graph myGraph)
{
    if (myGraph.checkcity(nameofcity))
    {
        myGraph.DFS(nameofcity);
        return 1;
    }
    else if (!myGraph.checkcity(nameofcity))
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
/*
0 fail
1 success
2 the city was existing
*/
int User_Inrerface::TraverBfs(graph traverGraph,string nameofcity, graph myGraph)
{
    if (myGraph.checkcity(nameofcity))
    {

        myGraph.BFS_algo(traverGraph,nameofcity);
        return 1;
    }
    else if (!myGraph.checkcity(nameofcity))
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
