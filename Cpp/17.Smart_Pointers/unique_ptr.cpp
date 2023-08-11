#include <iostream>
#include <memory>

int main(int argc, char const *argv[])
{
    // Smart pointer: Deleted automatically when no longer needed.
    // std::smart_pointer<CLASS> ptr = ....
    std::unique_ptr<int> smart{new int(3)};
    std::cout << *smart << std::endl;
    return 0;
}
