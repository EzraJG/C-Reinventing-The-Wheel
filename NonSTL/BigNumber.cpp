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
                if(buffer.size() == 4){
                    if(EqualsVar == temp + buffer[1] + buffer[2] + buffer[3]){
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
            bool YN = false;
            int i = 0;
            for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++, i++){
                uint64_t temp = *uint64_tit++;
                if(buffer.size() == 4){
                    if(NEqualsVar != temp + buffer[1] + buffer[2] + buffer[3]){
                        //td::cout << "if 1" << std::endl;
                        return true;
                    }
                }
                if(uint64_tit != buffer.end()){
                    if(NEqualsVar - temp != *uint64_tit){
                        YN = false;
                        //std::cout << "if 2" << std::endl;
                    }
                }else{
                    std::vector<uint64_t> temp;
                    for(int i = 0; i < buffer.size(); i++){
                        temp.push_back(buffer[i]);
                    }
                    if(NEqualsVar != std::accumulate(temp.begin(), temp.end(), 0)){
                        //std::cout << "if 3" << std::endl;
                        return true;
                    }

                }
            }
            return YN;
        }

        bool operator<(uint64_t LTVar){
            bool YN = false;
            int i = 0;


            i = 0;
            for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++, i++){
                uint64_t temp = *uint64_tit++;
                if(buffer.size() == 4){
                    if(LTVar < temp + buffer[1] + buffer[2] + buffer[3]){
                        //std::cout << "if 1" << std::endl;
                        return true;
                    }
                }
                if(uint64_tit != buffer.end()){
                    if(LTVar - temp < *uint64_tit){
                        return true;
                        //std::cout << "if 2" << std::endl;
                    }
                }else{
                    std::vector<uint64_t> temp;
                    for(int i = 0; i != buffer.size(); i++){
                        //temp.push_back(buffer[i]);
                    }
                    if(LTVar < std::accumulate(temp.begin(), temp.end(), 0)){
                        //std::cout << "if 3" << std::endl;
                        return false;
                    }
                    if(LTVar == std::accumulate(temp.begin(), temp.end(), 0)){
                        //std::cout << "if 4" << std::endl;
                        return false;
                    }

                }
            }
            return YN;
        }

        bool operator>(uint64_t GTVar){
            bool YN = false;
            int i = 0;
            //std::cout << GTVar;

            i = 0;
            for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++, i++){
                uint64_t temp = *uint64_tit++;
                if(buffer.size() == 4){
                    if(GTVar > temp + buffer[1] + buffer[2] + buffer[3]){
                        //std::cout << "if 1" << std::endl;
                        return true;
                    }
                }
                if(uint64_tit != buffer.end()){
                    if(GTVar - temp > *uint64_tit){
                        //std::cout << "if 2" << std::endl;
                        return true;

                    }
                }else{
                    std::vector<uint64_t> temp;
                    for(int i = 0; i != buffer.size(); i++){
                        temp.push_back(buffer[i]);
                    }
                    if(GTVar > std::accumulate(temp.begin(), temp.end(), 0)){
                        //std::cout << "if 3" << std::endl;
                        return false;
                    }
                    if(GTVar == std::accumulate(temp.begin(), temp.end(), 0)){
                        //std::cout << "if 4" << std::endl;
                        return false;
                    }

                }
            }
            //std::cout << "nothing" << std::endl;
            return YN;
        }

        bool operator>=(uint64_t GTEVar){
            bool YN = false;
            int i = 0;
            //std::cout << GTEVar;

            i = 0;
            for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++, i++){
                uint64_t temp = *uint64_tit++;
                if(buffer.size() == 4){
                    if(GTEVar <= temp + buffer[1] + buffer[2] + buffer[3]){
                        //std::cout << "if 1" << std::endl;
                        return true;
                    }
                }
                if(uint64_tit != buffer.end()){
                    if(GTEVar - temp <= *uint64_tit){
                        //std::cout << "if 2" << std::endl;
                        return true;

                    }
                }else{
                    std::vector<uint64_t> temp;
                    for(int i = 0; i != buffer.size(); i++){
                        temp.push_back(buffer[i]);
                    }
                    if(GTEVar > std::accumulate(temp.begin(), temp.end(), 0)){
                        //std::cout << "if 3" << std::endl;
                        return false;
                    }

                }
            }
            //std::cout << "nothing" << std::endl;
            return YN;
        }


        bool operator<=(uint64_t LTEVar){
            bool YN = false;
            int i = 0;
            std::cout << LTEVar;

            i = 0;
            for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++, i++){
                uint64_t temp = *uint64_tit++;
                if(buffer.size() == 4){
                    if(LTEVar >= temp + buffer[1] + buffer[2] + buffer[3]){
                        //std::cout << "if 1" << std::endl;
                        return true;
                    }
                }
                if(uint64_tit != buffer.end()){
                    if(LTEVar - temp <= *uint64_tit){
                        //std::cout << "if 2" << std::endl;
                        return true;

                    }
                }else{
                    std::vector<uint64_t> temp;
                    for(int i = 0; i != buffer.size(); i++){
                        temp.push_back(buffer[i]);
                    }
                    if(LTEVar < std::accumulate(temp.begin(), temp.end(), 0)){
                        //std::cout << "if 3" << std::endl;
                        return false;
                    }

                }
            }
            //std::cout << "nothing" << std::endl;
            return YN;
        }




        void operator=(std::vector<uint64_t> input){
            int i = 0;
            buffer.clear();
            for(uint64_tit = input.begin(); uint64_tit != input.end(); uint64_tit++, i++){
            buffer.push_back(*uint64_tit);
            }
        }

        void operator-(uint64_t a){ //Basic and can break easily
            buffer.back() - a;
            std::cout << buffer.back();
        }
        void operator+(uint64_t a){
            buffer.push_back(a);
        }
};

int main(){

std::vector<uint64_t> placeholder = { 1, 1, 1}; // Now can hold N amount of numbers, any number above 64 bits needs to be separated for no overflow(May find a solution later)
BigNumber a(placeholder);
a - 5;
std::cout << std::endl << (a < 3);
return 0;
}
