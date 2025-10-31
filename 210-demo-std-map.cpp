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
    Villager["Audie"] = {5, "Alligator", "Snap to it!"};
    Villager["Raymond"] = {10, "Wolf", "woof woof"};
    Villager.insert({"Marshal", {8, "Cat", "cyaat"}});
    //Main menu Function Handles all of the operations needed.
    MainMenu(Villager);
    return 0;
}

void MainMenu(map<string, tuple<int,string,string>>& Villager){
    int response;
    while(true){
        cout<<"1.Add Villager"<<endl<<
        "2.Delete Villager"<<endl<<
        "3.Increase Friendship"<<endl<<
        "4.Decrease Friendship"<<endl<<
        "5.Search for Villager"<<endl<<
        "6.Exit"<<endl;
        cout<<"Enter choice  --> ";
        cin>>response;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"Invalid response please try again"<<endl;
            continue;
        }
        if(response==1){
            cin.ignore();
            cout<<"Villager name: ";
            string temp;
            getline(cin,temp);
            cout<<"Friendship level: ";
            int temp2;
            // Added this since you wanted the friendship points to be 0-10 
            while(true){
                cin>>temp2;
                if(temp2<0||temp2>10){
                    cout<<"Please pick a number within 0-10"<<endl;
                }
                else{
                    break;
                }
            }
            cin.ignore();
            cout<<"Species: ";
            string temp3;
            getline(cin,temp3);
            cout<<"Catchphrase: ";
            string temp4;
            getline(cin,temp4);
            cout<<temp<<" was added!"<<endl;
            cout<<endl;
            Villager.insert({temp,{temp2,temp3,temp4}});
        }
        if(response==2){
            cout<<endl;
            cout<<"Which Villager to Delete?"<<endl;
            for (auto[pair,villagerdeets] : Villager ) {
                auto[happiness,species,phrase]=villagerdeets;
                cout << pair<< "["<<happiness<<", "<<species<<", "<<phrase<<"]"<<endl;
            }
            cin.ignore();
            cout<<"Enter Villager Name: ";
            string temp;
            getline(cin,temp);
            Villager.erase(temp);
            cout<<"Villager deleted"<<endl;
            cout<<endl;
        }
        if(response==3){
            cout<<endl;
            cout<<"Which Villager to Increase Friendship with?"<<endl;
            for (auto[pair,villagerdeets] : Villager ) {
                auto[happiness,species,phrase]=villagerdeets;
                cout << pair<< "["<<happiness<<", "<<species<<", "<<phrase<<"]"<<endl;
            }
            cin.ignore();
            cout<<"Enter Villager Name: ";
            string temp;
            getline(cin,temp);
            string searchKey = temp;
             auto it = Villager.find(searchKey);
            if (it != Villager.end()) {  
            cout << "\nFound " << searchKey << ""<<endl;
            if(get<0>(Villager[searchKey])<10){
                cout<<"Adding Friendship point now!"<<endl;
                get<0>(Villager[searchKey])+=1;
            }
            else{
                cout<<"Max Friendship reached!"<<endl;
            }
            } 
            else{
                cout << endl << searchKey << " not found." << endl;
            }
            cout<<endl;
        }
        else if(response==4){
            cout<<endl;
            cout<<"Which Villager to Decrease Friendship with?"<<endl;
            for (auto[pair,villagerdeets] : Villager ) {
                auto[happiness,species,phrase]=villagerdeets;
                cout << pair<< "["<<happiness<<", "<<species<<", "<<phrase<<"]"<<endl;
            }
            cin.ignore();
            cout<<"Enter Villager Name: ";
            string temp;
            getline(cin,temp);
            string searchKey = temp;
             auto it = Villager.find(searchKey);
            if (it != Villager.end()) {  
            cout << "\nFound " << searchKey <<endl;
            if(get<0>(Villager[searchKey])>0){
                cout<<"Removing Friendship point now!"<<endl;
                get<0>(Villager[searchKey])-=1;
            }
            else{
                cout<<"Lowest Friendship reached!"<<endl;
            }
            } 
            else{
                cout << endl << searchKey << " not found." << endl;
            }
            cout<<endl;
        }
        else if(response==5){
            cin.ignore();
            cout<<"Enter Villager Name: ";
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
       else if(response==6){
        break;
       }
        else{
            
        }
    cout << "Villagers details:" << endl;
    for (auto[pair,villagerdeets] : Villager ) {
        auto[happiness,species,phrase]=villagerdeets;
        cout << pair<< "["<<happiness<<", "<<species<<", "<<phrase<<"]"<<endl;
    }
    cout<<endl;
    }
}
