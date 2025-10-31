// COMSC-210 | Lab 27 | Daniel Santisteban
// IDE used: VS Code

#include <iostream>
#include <map>
#include <tuple>
#include <string>
#include <vector>
using namespace std;

void MainMenu(map<string, tuple<int,string,string>>& Villager);

int main() {
    // declarations
    map<string, tuple<int,string,string>> Villager;
  
    
    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
   
    Villager["Audie"] = {5, "Alligator", "Snap to it!"};
    Villager["Raymond"] = {10, "Wolf", "woof woof"};
    Villager.insert({"Marshal", {8, "Cat", "cyaat"}});
    MainMenu(Villager);
/*
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
        cout << "\nFound " << searchKey << "'s Villager details! "<<endl;
        tuple<int,string,string>villagerdeets=it->second;
        cout<<"["<<get<0>(villagerdeets)<<", "<<get<1>(villagerdeets)<<", "<<get<2>(villagerdeets)<<"]";
        
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << Villager.size() << endl;
    Villager.clear();
    cout << "Size after clear: " << Villager.size() << endl;
    */
    return 0;
}

void MainMenu(map<string, tuple<int,string,string>>& Villager){
   
    int response;
    while(true){
         cout<<"1.Increase Friendship"<<endl<<
        "2.Decrease Friendship"<<endl<<
        "3.Search for Villager"<<endl<<
        "4.Exit"<<endl;
        cout<<"choice  --> ";
        cin>>response;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"Invalid response please try again"<<endl;
            continue;
        }
        if(response==1){
            cout<<"Which Villager to D"
        }
        else if(response==2){

        }
        else if(response==3){
            cin.ignore();
            cout<<"Enter Villager Name:";
            string temp;
            getline(cin,temp);
            string searchKey = temp;
            auto it = Villager.find(searchKey);
            if (it != Villager.end()) {  // the iterator points to beyond the end of the map
                                        // if searchKey is not found
            cout << "\nFound " << searchKey << "'s Villager details! "<<endl;
            tuple<int,string,string>villagerdeets=it->second;
            cout<<"["<<get<0>(villagerdeets)<<", "<<get<1>(villagerdeets)<<", "<<get<2>(villagerdeets)<<"]";
            
            cout << endl;
            } else{
                cout << endl << searchKey << " not found." << endl;
            }
            cout<<endl;
        }
       else if(response==4){
        break;
       }
        else{
            cout<<"Invalid response please try again"<<endl;
        }



    cout << "Villagers details:" << endl;
    for (auto[pair,villagerdeets] : Villager ) {
        auto[happiness,species,phrase]=villagerdeets;
        cout << pair<< "["<<happiness<<", "<<species<<", "<<phrase<<"]"<<endl;
    }
    cout<<endl;
    }



}
