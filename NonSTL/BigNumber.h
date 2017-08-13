#ifndef BIGNUMBER_H
#define BIGNUMBER_H

//Functions
template <typename T, typename X>
T sum(X container) {
    T sum = 0;
    for (auto& n : container)
        sum += n;
    return sum;
}



class BigNumber
{
    private:

    public:
        std::vector<uint64_t> buffer;
        std::vector<uint64_t>::iterator uint64_tit;
        BigNumber(std::vector<uint64_t> tab);
        //Comparisons
        bool operator==(uint64_t EqualsVar);
        bool operator!=(uint64_t NEqualsVar);
        bool operator<(uint64_t LTVar);
        bool operator>(uint64_t GTVar);
        bool operator>=(uint64_t GTEVar);
        bool operator<=(uint64_t LTEVar);

        //Setters
        void operator=(std::vector<uint64_t> input);
        void operator-(uint64_t a);
        void operator+(uint64_t a);
        BigNumber& operator++();
        BigNumber& operator--();
        BigNumber operator++(int);
        BigNumber operator--(int);
        //"Getters"
        friend std::ostream& operator<<(std::ostream& os, const BigNumber& big);
        friend std::istream& operator>>(std::istream in, const BigNumber& big);

};

#endif // BIGNUMBER_H
