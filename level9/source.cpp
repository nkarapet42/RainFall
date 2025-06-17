#include <iostream>
#include <cstring>
#include <cstdlib>

class N {
public:
    N(int value) {
        this->value = value;
    }

    virtual int operator()(N* other) {
        return this->value + other->value;
    }

    int operator+(N& other) {
        return this->value + other.value;
    }

    int operator-(N& other) {
        return this->value - other.value;
    }

    void setAnnotation(char* input) {
        std::memcpy(this->annotation, input, std::strlen(input));
    }

private:
    char annotation[104];
    int value;
};


int main(int argc, char** argv) {
    if (argc < 2)
        exit(1);

    N* a = new N(5);
    N* b = new N(6);

    a->setAnnotation(argv[1]);

    (*b)(a);
}
