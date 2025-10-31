// COMSC-210 | Lab 27 | Daniel Santisteban
// IDE used: VS Code

#include <iostream>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

int main() {
    // declarations
    map<string, vector<string>> villagerColors;
   vector<tuple<int,string,string>> Villager; 

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    Villager.push_back({5,"Alligator","Snap to It!"});
    Villager.push_back({10,"Wolf","Hubba hubba!"});
    Villager.push_back({8,"Cat","Nice fit"});


    villagerColors["Audie"] = {"Orange", "Yellow", "Red"};
    villagerColors["Raymond"] = {"Black", "Gray", "White"};
    villagerColors.insert({"Marshal", {"Blue", "White", "Black"}});


    // access the map using a range-based for loop
    cout << "Villager details: " << endl;
    for(auto pair: villagerColors){
        cout<<pair.first;
        for(auto& pair2: Villager){
            if(get<0>)
            cout<<"["<<get<0>(pair2)<<", "<<get<1>(pair2)<<", "<<get<2>(pair2)<<"]";
        }
        cout<<endl;
    }

    
/*
    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

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
    */
    return 0;
}
