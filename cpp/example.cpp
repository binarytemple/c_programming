#include<iostream>

class example {
    int var1, var2;
    public:
    void set_request(int a, int b);
    int sum(){return (var1+var2);}
} class_obj;

void example::set_request(int a, int b)
{
    var1 = a;
    var2 = b;
}

int main(void)
{
    class_obj.set_request(1,4);
    std::cout << "\n The sum is " << class_obj.sum() << "\n";
    return 0;
}
