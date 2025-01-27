#include <vector>
#include <algorithm>
#include <random>

template<typename T>
class Deck : public std::vector<T> {
public:
    Deck(){}

    T top()
    {
        return this->front();
    }

    T bottom()
    {
        return this->back();
    }

    T draw()
    {
        T val = this->front();
        this->erase(this->begin());
        return val;
    }

    void add(T val)
    {
        this->insert(this->begin(), val);
    }

    void shuffle(int seed = -1)
    {
        if(seed >= 0)
        {
            std::shuffle(this->begin(), this->end(), std::default_random_engine(static_cast<unsigned int>(seed)));
        }
        else
        {
            std::shuffle(this->begin(), this->end(), std::random_device());
        }
    }

};