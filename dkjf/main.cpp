#include <iostream>
#include <string>

#define endl "\n"

using namespace std;

int main(){

    /*
        The user will Enter their grade 'A', 'B', 'C', 'D', 'F'
        then the program will output the equivalence wheter
        100, 90, 80.....
        Amazing, Excellent. .... ..
    */

//    first step: prompt user "Enter Your Grade"
//    second step: Check the equivalent output of grade usingconditional statement
//     third step: output equivalent

    char grade = '.';
    cout << "Enter your grade: ";
    cin >> grade;

    // grade = toupper(grade);

    switch(grade){
        case 'A':
            cout << "Amazing" << endl;
            break;
        case 'B':
            cout << "Excellent" << endl;
            break;
        case 'C':
            cout << "Cutoff ka boyyy" << endl;
            break;
        case 'D':
            cout << "Di pasado" << endl;
            break;
        default:
            cout << "Input Not Valid!" << endl;
    }



    //If complex,

    //swtich basic values, speed
    both readability kung tama ang application


    return 0;
}