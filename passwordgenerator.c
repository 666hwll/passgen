#include <stdio.h>
#include <stdlib.h>
#include <sys/random.h>
#include <string.h>

// struct
unsigned int choice;

int secrets (size_t x) {
    ranD:
    getrandom(&choice, sizeof(choice),  0);
    choice = choice %  x;

    if (choice < 0) { 
    goto ranD;
    }
   /*int fd = open("/dev/urandom", O_RDONLY);
   if (fd == -1) {
       perror("open");
       return 1;
   }

   read(fd, &choice, sizeof(choice));
   choice = choice % 110;
   close(fd);*/
   return 0;
}

int main() {
    unsigned int leni;
    char end[4];
    const char asym[] = "^1jkl˝^<2ASDFGHJKL3{[]}qwertzu4P5)=?`iop6IO+@~ a7ERTZUsdfg8*QWhyx9cvbnm,0°!§$&/(.-<YXCVBNM;:_|" ;
    const size_t n = sizeof(asym)/sizeof(asym[0]);
    printf("Type in the length of the password you want to be generated(X to quit): ");
    if (scanf_s("%d", &leni) != 1) {
        printf("Input isn't expected format.\n");
        exit(1);
    }
   char strb[leni + 1];
   
   for (int len = leni; len > 0; len--) {
       secrets(n);
       strb[len-1] = asym[choice]; // Use choice as an index to access the asym array
   }
   printf("%s\n", strb);
   do {
   scanf("\n%c", &end);
   } while (strcmp(end, "X"));
   
   return 0;
}
