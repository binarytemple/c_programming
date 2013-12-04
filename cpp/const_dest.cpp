#include<iostream>

class country
{
    public:

    country()
    {
        std::cout<<"\nConstructor called \n";
    }

    void setNumOfCities(int num);
    int getNumOfCities(void);

    ~country()
    {
        std::cout<<"\nDestructor called \n";
        for(int i = 0; i < num_of_cities;i++) {
            std::cout<<"Destroy city "<< i+1 << "\n";
        }
    }

    private:

    int num_of_cities;

};

void country::setNumOfCities(int num)
{
    num_of_cities = num;
}

int country::getNumOfCities(void)
{
    return num_of_cities;
}

int main(void)
{
    country obj;
    int num = 5;

    obj.setNumOfCities(num);
    num = obj.getNumOfCities();

    std::cout<<"\nNumber of cities is equal to "<<num;

    return 0;
}
