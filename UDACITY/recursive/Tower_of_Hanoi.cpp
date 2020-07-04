#include <iostream>

void tower_of_Hanoi_soln(int num_disks, char source, char auxiliary, char destination){
    
    if (num_disks == 1){
        std::cout<< source << " " << destination <<std::endl; 
        return;
    }
    
    tower_of_Hanoi_soln(num_disks - 1, source, destination, auxiliary);
    std::cout<< source << " " << destination <<std::endl; 
    tower_of_Hanoi_soln(num_disks - 1, auxiliary, source, destination);
}

void tower_of_Hanoi(int num_disks){
    tower_of_Hanoi_soln(num_disks, 'S', 'A', 'D');
}

int main(){
    tower_of_Hanoi(3);
}