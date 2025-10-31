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
    for (map<string, tuple<int,string,string>>::iterator it = Villager.begin(); 
                                               it != Villager.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
           
        }
        cout << endl;
    }

    // delete an element
    Villager.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}
