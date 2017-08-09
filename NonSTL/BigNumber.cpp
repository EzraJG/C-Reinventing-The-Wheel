#include <iostream>
#include <vector> // Will add custom vector class later
#include <algorithm>
class BigNumber{
    private:

    public:
        std::vector<uint64_t> buffer[];
        BigNumber(std::vector<uint64_t> tab[]){
            for(int i = 0; i < tab->size(); i++){
                buffer[i] = tab[i];
            }
        }
        bool operator==(auto a){
            bool isEqual = false;
            for(int i = 0; i < buffer->size()/8; i++){
                if(a - buffer.at(i+1) == buffer.at(i)){
                    isEqual = true;
                }
            }
            return isEqual;
        }


};

int main(){

std::vector<long long unsigned int> placeholder = {9223372036854775807, 1}; // Tested multiple ways, seems to work!
BigNumber a(&placeholder);
if(a == 9223372036854775808){
    std::cout << ":thunk:" << std::endl;
}
}
