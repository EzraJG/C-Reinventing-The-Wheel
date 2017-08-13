#include <iostream>
#include <vector> // Will add custom vector class later
#include <algorithm>
#include <exception>
#include <numeric>
#include <limits>
#include "BigNumber.h"




BigNumber::BigNumber(std::vector<uint64_t> tab){
    try{
        int i2 = 0;
        for (uint64_tit = tab.begin(); uint64_tit != tab.end(); uint64_tit++, i2++){
            buffer.push_back(*uint64_tit);
        }
    }catch(std::bad_alloc){
        std::cout << "Out Of Memory/Illegal Memory Access";

        for (uint64_tit = tab.begin(); uint64_tit != buffer.end(); uint64_tit++)
            std::cout << *uint64_tit << ' ';
    }
}

bool BigNumber::operator==(uint64_t EqualsVar){
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

bool BigNumber::operator!=(uint64_t NEqualsVar){
    bool YN = false;
    int i = 0;
    for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++, i++){
        uint64_t temp = *uint64_tit++;
        if(buffer.size() == 4){
            if(NEqualsVar != temp + buffer[1] + buffer[2] + buffer[3]){
                return true;
            }
        }
        if(uint64_tit != buffer.end()){
            if(NEqualsVar - temp != *uint64_tit){
                YN = false;
            }
        }else{
            std::vector<uint64_t> temp;
            for(int i = 0; i < buffer.size(); i++){
                temp.push_back(buffer[i]);
            }
            if(NEqualsVar != std::accumulate(temp.begin(), temp.end(), 0)){
                return true;
            }

        }
    }
    return YN;
}

bool BigNumber::operator<(uint64_t LTVar){
    bool YN = false;
    int i = 0;


    i = 0;
    for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++, i++){
        uint64_t temp = *uint64_tit++;
        if(buffer.size() == 4){
            if(LTVar < temp + buffer[1] + buffer[2] + buffer[3]){
                return true;
            }
        }
        if(uint64_tit != buffer.end()){
            if(LTVar - temp < *uint64_tit){
                return true;
            }
        }else{
            std::vector<uint64_t> temp;
            for(int i = 0; i != buffer.size(); i++){
                temp.push_back(buffer[i]);
            }
            if(LTVar < std::accumulate(temp.begin(), temp.end(), 0)){
                return false;
            }
            if(LTVar == std::accumulate(temp.begin(), temp.end(), 0)){
                return false;
            }

        }
    }
    return YN;
}

bool BigNumber::operator>(uint64_t GTVar){
    bool YN = false;
    int i = 0;


    i = 0;
    for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++, i++){
        uint64_t temp = *uint64_tit++;
        if(buffer.size() == 4){
            if(GTVar > temp + buffer[1] + buffer[2] + buffer[3]){
                return true;
            }
        }
        if(uint64_tit != buffer.end()){
            if(GTVar - temp > *uint64_tit){
                return true;

            }
        }else{
            std::vector<uint64_t> temp;
            for(int i = 0; i != buffer.size(); i++){
                temp.push_back(buffer[i]);
            }
            if(GTVar > std::accumulate(temp.begin(), temp.end(), 0)){
                return false;
            }
            if(GTVar == std::accumulate(temp.begin(), temp.end(), 0)){
                return false;
            }

        }
    }
    return YN;
}

bool BigNumber::operator>=(uint64_t GTEVar){
    bool YN = false;
    int i = 0;

    i = 0;
    for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++, i++){
        uint64_t temp = *uint64_tit++;
        if(buffer.size() == 4){
            if(GTEVar <= temp + buffer[1] + buffer[2] + buffer[3]){
                return true;
            }
        }
        if(uint64_tit != buffer.end()){
            if(GTEVar - temp <= *uint64_tit){
                return true;

            }
        }else{
            std::vector<uint64_t> temp;
            for(int i = 0; i != buffer.size(); i++){
                temp.push_back(buffer[i]);
            }
            if(GTEVar > std::accumulate(temp.begin(), temp.end(), 0)){
                return false;
            }

        }
    }
    return YN;
}


bool BigNumber::operator<=(uint64_t LTEVar){
    bool YN = false;
    int i = 0;
    std::cout << LTEVar;

    i = 0;
    for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++, i++){
        uint64_t temp = *uint64_tit++;
        if(buffer.size() == 4){
            if(LTEVar >= temp + buffer[1] + buffer[2] + buffer[3]){
                return true;
            }
        }
        if(uint64_tit != buffer.end()){
            if(LTEVar - temp <= *uint64_tit){
                return true;

            }
        }else{
            std::vector<uint64_t> temp;
            for(int i = 0; i != buffer.size(); i++){
                temp.push_back(buffer[i]);
            }
            if(LTEVar < std::accumulate(temp.begin(), temp.end(), 0)){
                return false;
            }

        }
    }
    return YN;
}




void BigNumber::operator=(std::vector<uint64_t> input){
    int i = 0;
    buffer.clear();
    for(uint64_tit = input.begin(); uint64_tit != input.end(); uint64_tit++, i++){
    buffer.push_back(*uint64_tit);
    }
}

void BigNumber::operator-(uint64_t a){ //A little bit safer with a failsafe(Needs to be improved)
    int i = 0;
    for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++, i++){
        if(buffer[i] != -((2^63)-1)){
            buffer[i] - a;
        }else{
            buffer.push_back(0-a);
        }
    }
}
void BigNumber::operator+(uint64_t a){
    buffer.push_back(a);
}

std::ostream& operator<<(std::ostream& os, BigNumber& big){
    uint64_t a = 0;
    for(big.uint64_tit = big.buffer.begin(); big.uint64_tit != big.buffer.end(); big.uint64_tit++){
        a += *big.uint64_tit;
    }
    os << a;
    return os;
}

std::istream& operator>>(std::istream& in, BigNumber& big){
    uint64_t a = 0;
    for(big.uint64_tit = big.buffer.begin(); big.uint64_tit != big.buffer.end(); big.uint64_tit++){
        a += *big.uint64_tit;
    }
    in >> a;
    return in;
}

BigNumber& BigNumber::operator++(){
    this->buffer.push_back(1);
    return *this;
}

BigNumber& BigNumber::operator--(){
    this->buffer.push_back(-1);
    return *this;
}


BigNumber BigNumber::operator--(int){
    this->buffer.push_back(-1);
    return *this;
}

BigNumber BigNumber::operator++(int){
    this->buffer.push_back(1);
    return *this;
}



double BigNumber::operator*(auto a){
    uint64_t b = 0;
    for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++){
        b += *uint64_tit;
    }
    return b * a;
}


double BigNumber::operator/(auto a){
    uint64_t b = 0;
    for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++){
        b += *uint64_tit;
    }
    return b / a;
}

BigNumber BigNumber::operator*=(auto a){
    uint64_t b = 0;
    for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++){
        b += *uint64_tit;
    }
    this->buffer.clear();
    this->buffer.push_back(a*b);
    return *this;
}

BigNumber BigNumber::operator/=(auto a){
    uint64_t b = 0;
    for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++){
        b += *uint64_tit;
    }
    this->buffer.clear();
    this->buffer.push_back(b/a);
    return *this;
}

BigNumber BigNumber::operator+=(auto a){
    uint64_t b = 0;
    for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++){
        b += *uint64_tit;
    }
    this->buffer.clear();
    this->buffer.push_back(a+b);
    return *this;
}

BigNumber BigNumber::operator-=(auto a){
    uint64_t b = 0;
    for(uint64_tit = buffer.begin(); uint64_tit != buffer.end(); uint64_tit++){
        b += *uint64_tit;
    }
    this->buffer.clear();
    this->buffer.push_back(b - a);
    return *this;
}

void BigNumber::optimize(){
    int buff = 0;
    std::vector<uint64_t> leftover;
    uint64_t localmax = std::numeric_limits<uint64_t>::max();
    for(uint64_tit = buffer.begin(); uint64_tit != buffer.end();){
        if(*uint64_tit >= localmax){
            *uint64_tit - localmax;
            buff++;
            leftover.push_back(localmax);
            std::cout << buff << " : " << localmax << std::endl;
        }else{
            *uint64_tit++;
            leftover.push_back(*uint64_tit);
            std::cout << buff << " : " << *uint64_tit << std::endl;
        }
    }
    buffer.clear();
    std::cout << std::endl << "buff: " << buff << std::endl;
    *this = BigNumber(leftover);
}

int main(){

std::vector<uint64_t> placeholder = {10, 2}; // Now can hold N amount of numbers, any number above 64 bits needs to be separated for no overflow(May find a solution later)
BigNumber a(placeholder);
while(true){
    std::string *temp = new std::string;
    std::cout << std::endl << "Begin loop: " << sizeof(a) << std::endl;
    std::cin >> *temp;
    if(*temp == "optim"){
        std::cout << std::endl << "In a: " << a;
        std::cout << std::endl << "A size(before optim): " << sizeof(a) << std::endl;
        a.optimize();
        std::cout << std::endl << "A size(after optim): " << sizeof(a) << std::endl;
    }else if(*temp == "input"){
        std::cout << std::endl;
        std::cin >> a;
    }
    std::cout << std::endl << "After loop: " << sizeof(a) << std::endl;
    delete temp;

}
return 0;
}
