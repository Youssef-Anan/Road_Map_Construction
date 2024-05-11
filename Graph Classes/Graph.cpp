#include "Headers/Graph.h"
#include <stack>
#include <unordered_set>
#include <queue>
#include<sstream>
#include<limits>
City::City() {
        cityname = " ";
    }
    City::City(string cname) {
        cityname = cname;
    }
    string City::getCityname() {
        return cityname;
    }
    string City:: setCityname(string cname) {
        cityname = cname;
        return cityname;
    }
  /*  void City ::update_cityname(string cityname,string newname) {}*/

    bool graph:: checkedge(string city1, string city2) {
        if (checkcity(city1)) {
            for (auto edge : mymap[city1]) {
                if (edge.first == city2) {
                    return true;
                }
            }
        }
        return false;
    }

    void graph:: addedge(string city1, string city2, int km)
    {
        bool check1 = checkcity(city1);
        bool check2 = checkcity(city2);
        bool check3 = checkedge(city1, city2);
        if (check1 && check2 == true) {
            if (check3 == true) {
                cout << "The Edge between " << city1 << " and " << city2 << " already exists";
            }
            else {
                mymap[city1].push_back(make_pair(city2, km));
                mymap[city2].push_back(make_pair(city1, km));
                cout << "Edge between " << city1 << " and " << city2 << " is added succesfully"<<endl;
            }
        }
        else {
            cout << "Invalid cities entered ";
        }
    }

    void graph:: delete_edge(string city1, string city2) {
        bool check = checkedge(city1, city2);
        if (check == true) {
            for (auto it = mymap[city1].begin(); it != mymap[city1].end(); ) {
                if (it->first == city2) {
                    it = mymap[city1].erase(it);
                }
                else {
                    ++it;
                }
            }
            for (auto it = mymap[city2].begin(); it != mymap[city2].end(); ) {
                if (it->first == city1) {
                    it = mymap[city2].erase(it);
                }
                else {
                    ++it;
                }
            }
            cout << "Edge deleted successfully "<<endl;
        }
        else {
            cout << "One or both cities doesnt exist "<<endl;
        }
    }

    bool graph:: checkcity(string cityname) {
        if (mymap.find(cityname) != mymap.end()) {
            return true;
        }
        else {
            return false;
        }
    }
    void graph ::update_cityname(string cityname ,string newname){
    if(checkcity(cityname)==true){
      if(checkcity(newname)==true){
        cityname==newname;
    }

    }
    }
    void graph ::addcity(string newcity) {
             City ncity;
        ncity .setCityname(newcity);
        bool check = checkcity(ncity.getCityname());
        if (check == true) {
            cout << "City with this name already exists "<<endl;
        }
        else {
            mymap[newcity] = list<pair<string, int>>();
            cout << newcity<<" is added successfully."<<endl;
            citycount++;
        }
    }

    void graph:: deletecity(string cityname) {
        if (checkcity(cityname)) {
            mymap.erase(cityname);
            cout << cityname<<" deleted succesfully "<<endl;
        }
        else {
            cout << "City already doesnt exist "<<endl;
        }
    }

bool graph::checkmap() {
    if(citycount!=0) {
        return true;
    }
    else {
        return false;
    }
}



void graph:: clearmap(){
    if(checkmap())
        mymap.clear();

}

void graph::update_edge(string city1,string city2,int km){

    if (checkedge(city1,city2)) {
        delete_edge(city1, city2);
    }
    mymap[city1].push_back(make_pair(city2, km));
    mymap[city2].push_back(make_pair(city1, km));
}

int graph::number_of_cities(){
return citycount;
}

void graph:: printadjcentlist()
{
    for (auto c : mymap)
    {
        string city = c.first;
        list<pair<string, int>> details = c.second;
        for (auto dis : details)
        {
            cout << " destenation: " << dis.first << endl;
            cout << " distance from " << c.first << " to " << dis.first;
            cout << dis.second << " KM" << endl;
            cout << "-------------------------------" << endl;
        }
    }
}

queue <string> graph::DFS(string start_city)
{
        unordered_set<string> visited;
        stack<string> stack;
        queue<string> queue;
        stack.push(start_city);
        while (!stack.empty()) {
            string current_city = stack.top();
            stack.pop();
            queue.push(current_city);

            if (visited.find(current_city) == visited.end()) {
                visited.insert(current_city);


                for (auto neighbor : mymap[current_city]) {
                    if (visited.find(neighbor.first) == visited.end()) {
                        stack.push(neighbor.first);
                    }
                }
            }
        }
        return queue;
    }

    queue <string> graph :: BFS_algo( graph g,string startcity)
    {
        queue<string>store;
        unordered_map<string,bool>visted;
        queue<string>q;
        visted[startcity]=true;
        q.push(startcity);
        while(! q.empty()){
            string currentcity=q.front();
            q.pop();
            store.push(currentcity);
            for(auto neighbor : g.mymap[currentcity])
            {
                string neighborcity=neighbor.first;
                if(!visted[neighborcity])
                {
                    visted[neighborcity]=true;
                    q.push(neighborcity);
                }
            }
        }
        return store;

    }
    string graph :: Dijkstra_algo(graph g,string startcity){
    priority_queue<pair<int,string>,vector<pair<int,string>>, greater<pair<int,string>>> pq;
    unordered_map<string,int>distances;
    for(const auto & city : g.mymap){
    distances[city.first]=numeric_limits<int>::max();
    }
    distances[startcity]=0;
    pq.push(make_pair(0,startcity));
    unordered_set<string>visited;
    while(! pq.empty()){
    pair<int,string> current=pq.top();
    pq.pop();
    if(visited.count(current.second)>0)continue;
    visited.insert(current.second);
    for(const auto & neighbor : g.mymap[current.second]){
    string neighbor_city=neighbor.first;
    int distance_to_neighbor=neighbor.second;
    int total_distance=distances[current.second] +  distance_to_neighbor;
    if(distances[neighbor_city] > total_distance){
    distances[neighbor_city]=total_distance;
    pq.push(make_pair(total_distance,neighbor_city));
    }
    }
    }
    stringstream result;
    for(const auto & city : g.mymap){
    string city_name=city.first;
    int distance=distances[city_name];
    if(distance == numeric_limits<int>::max()){
    result << city_name << " : unreachable" <<endl;
    }else{
     result << city_name << ": "<<distance<<" KM" <<endl;
    }
    }
    return result.str();
    }

