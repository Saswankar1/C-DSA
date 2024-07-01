#include<iostream>
using namespace std;

int main() {
    int savings;
    cin >> savings;

    if ( savings>500){
        cout << "Tandoori Chicken Party";
    } else if ( savings>200){
        if( savings>300){
            cout << "Chicken Biryani Party";
        } else{
            cout << "Egg Biryani Party";
        }
    }
    else{
        cout << "No Party";
    }
    return 0;
}
