#include <iostream>
#include <vector> // Will add custom vector class later
#include <algorithm>

class BigNumber{
    private:
        std::vector<uint64_t> buffer;
        std::vector<uint64_t>::iterator uint64_tit;
    public:

        BigNumber(std::vector<uint64_t> tab){
            try{
                int i2 = 0;
            for (uint64_tit = tab.begin(); uint64_tit != tab.end(); uint64_tit++, i2++){
                //std::cout << *uint64_tit << ' ';
                buffer.push_back(*uint64_tit);
            }
            }catch(std::bad_alloc){
            std::cout << "Out Of Memory/Illegal Memory Access";

            for (uint64_tit = tab.begin(); uint64_tit != buffer.end(); uint64_tit++)
                std::cout << *uint64_tit << ' ';
            }
        }

        bool operator==(uint64_t a){
            bool YN = false;
            int i = 0;
            for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++, i++){
                        if(a - *uint64_tit++ == *uint64_tit){
                            YN = true;
                        }
            }
            return YN;
        }


};

int main(){

std::vector<uint64_t> placeholder = { 4, 4}; // Tested multiple ways, seems to work(Only with 2*, will be fixed later)
BigNumber a(placeholder);


return 0;
}
