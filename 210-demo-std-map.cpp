// COMSC-210 | Lab 27 | Daniel Santisteban
// IDE used: VS Code

#include <iostream>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int,string,string>> Villager;
  

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
   
    Villager["Audie"] = {5, "Alligator", "Snap to it!"};
    Villager["Raymond"] = {10, "Wolf", "cyaat but im a dog"};
    Villager.insert({"Marshal", {8, "Cat", "cyaat"}});


    // access the map using a range-based for loop
    cout << "Villagers details:" << endl;
    for (auto[pair,villagerdeets] : Villager ) {
        auto[happiness,species,phrase]=villagerdeets;
        cout << pair<< "["<<happiness<<", "<<species<<", "<<phrase<<"]"<<endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, tuple<int,string,string>>::iterator it = Villager.begin(); it != Villager.end(); ++it) {
        cout << it->first << "[";
        tuple<int,string,string>villagerdeets=it->second;
        cout<<get<0>(villagerdeets)<<", "<<get<1>(villagerdeets)<<", "<<get<2>(villagerdeets)<<"]";

        cout << endl;
    }

    // delete an element
    Villager.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = Villager.find(searchKey);
    if (it != Villager.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto tuple<int,string,string>villagerdeets : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << Villager.size() << endl;
    Villager.clear();
    cout << "Size after clear: " << Villager.size() << endl;

    return 0;
}
