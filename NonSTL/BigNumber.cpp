#include <iostream>

class BigNumber{
    private:
        uint64_t buffer[2];
    public:
        BigNumber(uint64_t tab[]){
            buffer[0] = tab[0];
            buffer[1] = tab[1];
        }
        bool operator==(auto a){
            if(a - buffer[1] == buffer[0]){
                return true;
            }else{return false;}
        }

};

int main(){

uint64_t placeholder[2] = {9223372036854775807, 1}; // Tested multiple ways, seems to work!
BigNumber a(placeholder);
if(a == 9223372036854775808){
    std::cout << ":thunk:" << std::endl;
}
}
