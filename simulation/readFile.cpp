#include<iostream>
#include<string.h>

using namespace std;
void convertStringtoFloat(char * str, float * local);

int main(){
    // read line from file 
    // and convert float 
    char str[] = "G01 X25.000 Y26.000";
    float  xy[2] = {0.0,0.0};
    convertStringtoFloat(str,xy);
    // active actuator Scara
    // 

    // pause System 
    int a; cout << endl; cin >> a;
    return 0;
}

void convertStringtoFloat(char * str, float * local){
    char * take = strtok(str," ");
    cout << *take <<"/" << *(take+1) << "/" << *(take+2); 
}