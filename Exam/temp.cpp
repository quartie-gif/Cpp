struct A final
{
    explicit A(int i)
    {

    }
};

struct B: public A{};

void foo(A obj) {}


int main()
{
    foo(13);
}