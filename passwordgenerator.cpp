//#include <stdio.h>
#include <iostream>
#include <string>

#include <stdlib.h>
#include <sys/random.h>
//#include <string.h>


// struct
unsigned int choice;

int secrets (size_t x) {
    do {
        getrandom(&choice, sizeof(choice),  0);
        choice = choice %  x;
    } while(choice < 0);

   return 0;
}

int main() {
    unsigned int leni;
    std::string end = "";
    const std::string asym = "^1jkl˝^<2ASDFGHJKL3{[]}qwertzu4P5)
=?iop6IO+@~ a7ERTZUsdfg8*QWhyx9cvbnm,0°!§$&/(.-<YXCVBNM;:_|" ;
    const size_t n = sizeof(asym)/sizeof(asym[0]);
    std::cout << "Type in the length of the password you want to
 be generated(X to quit): ";
    //std::cin >> leni;
    if (!(std::cin >> leni)) {
        std::cerr << "Input isn't expected format.\n";
        exit(1);          }
    std::string strb;
    strb.resize(leni);

   for (int len = leni; len > 0; len--) {
       secrets(n);
       strb[len-1] = asym[choice]; // Use choice as an index to
access the asym array
   }
   std::cout << strb << "\n";
   //printf("%s\n", strb);
   do {
        std::cin >> end;
   //scanf("\n%c", &end);
   } while ("X" != end);

   return 0;
}             