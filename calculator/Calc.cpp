#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
void help()
{
    std::cout << "Параматры:\n'-m' умножение\n'-d' деление\n количесво оперантов  5-7  \n строка должна выглядеть так -m 1 2 3 4 5 6 \n умножение720 \n";
    exit(1);
}
int main(int argc, char **argv)
{
    if (argc==1) {
       std::cout << "Параматры:\n'-m' умножение\n'-d' деление\n количесво оперантов  5-7  \n ";
}
    
    int opt, b,multi=1,d,i,st=0;
    for(i=2; i<argc; i++) {
        st+=1;
    }
    if (((st<5) or (st >7)) and (st!=0)){
        help();
    }
    while((opt = getopt(argc, argv, "md:h")) != -1) {
        switch(opt) {  
        case 'm':
            for(i=2; i<argc; i++) {
                b = strtol(argv[i], NULL, 10);
                multi=multi*b;
            }
           	std::cout << "Умножение: " << multi << std::endl;
      		break;
        case 'd':
            b = strtol(argv[2], NULL, 10);
            for(i=3; i<argc; i++) {
                d = strtol(argv[i], NULL, 10);
                b = b/d;
                st+=1;
            }
            	std::cout << "Деление: " << b << std::endl;
            
            break;
        case 'h':
            help();
        case '?':
            help();
        default:
        std::cout <<"-h:"<<std::endl;
        help();
        exit(1);
        }
    }
}
