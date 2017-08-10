#include <iostream>
#include <vector> // Will add custom vector class later
#include <algorithm>
#include <exception>
#include <numeric>
template <typename T, typename X>
T sum(X container) {
    T sum = 0;
    for (auto& n : container)
        sum += n;
    return sum;
}

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

        bool operator==(uint64_t EqualsVar){
            bool YN = false;
            int i = 0;
            for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++, i++){
                uint64_t temp = *uint64_tit++;
                if(temp.size()/sizeof(uint64_t) == 4){
                    if(EqualsVar == temp[0] + temp[1] + temp[2] + temp[3]){
                        return true;
                    }
                }
                if(uint64_tit != buffer.end()){
                    if(EqualsVar - temp == *uint64_tit){
                        YN = true;
                    }
                }else{
                    std::vector<uint64_t> temp;
                    for(int i = 0; i < buffer.size(); i++){
                        temp.push_back(buffer[i]);
                    }
                    if(EqualsVar == std::accumulate(temp.begin(), temp.end(), 0)){
                        return true;
                    }

                }
            }
            return YN;
        }

        bool operator!=(uint64_t NEqualsVar){
            bool YN = true;
            int i = 0;
            for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++, i++){
                        uint64_t temp = *uint64_tit++;
                        if(NEqualsVar - temp == *uint64_tit){
                            YN = false;
                        }
            }
            return YN;
        }

        bool operator<(uint64_t LTVar){
            int i = 0;
            for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++, i++){
                    uint64_t temp = *uint64_tit++;
                if(LTVar - temp > *uint64_tit){
                    return true;
                }
            }
            return false;
        }

        bool operator>(uint64_t GTVar){
            int i = 0;
            for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++, i++){
                uint64_t temp = *uint64_tit++;
                if(GTVar - temp < *uint64_tit){
                    return true;
                }
            }
            return false;
        }

        bool operator>=(uint64_t GTEVar){
            int i = 0;
            for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++, i++){
                uint64_t temp = *uint64_tit++;
                if(GTEVar - temp < *uint64_tit || GTEVar - temp == *uint64_tit){
                    return true;
                }
            }
            return false;
        }


        bool operator<=(uint64_t LTEVar){
            int i = 0;
            for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++, i++){
                uint64_t temp = *uint64_tit++;
                if(LTEVar - temp > *uint64_tit || LTEVar - temp == *uint64_tit){
                    return true;
                }
            }
            return false;
        }

        void operator=(std::vector<uint64_t> input){
            int i = 0;
            buffer.clear();
            for(uint64_tit = input.begin(); uint64_tit != input.end(); uint64_tit++, i++){
            buffer.push_back(*uint64_tit);
            }
        }
};

int main(){

std::vector<uint64_t> placeholder = { 10, 10, 10, 10}; // Tested multiple ways, seems to work(Only with 2*, will be fixed later)
BigNumber a(placeholder);
if(a == 50) std::cout << "It works!" << std::endl;
return 0;
}
