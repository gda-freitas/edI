#include <iostream>
#include <sstream>
int main()
{
    //std::cout << "The number 42 in octal:   " << std::oct << 42 << '\n'
    //          << "The number 42 in decimal: " << std::dec << 42 << '\n'
    //          << "The number 42 in hex:     " << std::hex << 42 << '\n';
              
    int x =0;
	 std::istringstream("FF") >> std::hex >> x;
     printf("The number FF in dec: %d  \n", x);
    
    int n;
    std::istringstream("2A") >> std::hex >> n;
    std::cout << std::dec << "Parsing \"2A\" as hex gives " << n << '\n';
    // the output base is sticky until changed
    std::cout << std::hex << "42 as hex gives " << 42
        << " and 21 as hex gives " << 21 << '\n';
        
}
