#include <iostream>
#include <vector> // Will add custom vector class later
#include <algorithm>
class BigNumber{
    private:
        std::vector<uint64_t> buffer[];
        std::vector<uint64_t>::iterator uint64_tit;
    public:

        BigNumber(std::vector<uint64_t> tab[]){
            try{
                buffer->resize(tab->size());
                int i2 = 0;
            for (uint64_tit = tab->begin(); uint64_tit != tab->end(); uint64_tit++, i2++){
                //std::cout << *uint64_tit << ' ';
                buffer->assign(i2, *uint64_tit);
            }
            }catch(std::bad_alloc){
            std::cout << "Out Of Memory/Illegal Memory Access";

            for (uint64_tit = tab->begin(); uint64_tit != buffer->end(); uint64_tit++)
                std::cout << *uint64_tit << ' ';
            }
        }
        bool operator==(uint64_t a){
            bool YN = true;
            int i = 0;
            for(uint64_tit = buffer->begin(); uint64_tit != buffer->end(); uint64_tit++, i++){
                    if(i != buffer->size()){
                        if(a - (buffer->at(i+1)) == (buffer->at(i))){

                        }else{
                            YN = false;
                            std::cout << std::endl << (*uint64_tit+1) << std::endl << *uint64_tit;
                        }
                    }
            }
            return YN;
        }


};

int main(){

std::vector<uint64_t> placeholder = { 9223372036854775807, 9223372036854775807}; // Tested multiple ways, seems to work(Only with 2*, will be fixed later)
BigNumber a(&placeholder);
if(a == (9223372036854775807*2)){
    std::cout << ":thunk:" << std::endl;
    return 1;
}
return 0;
}
