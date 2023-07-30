#pragma once

/*
Debug my stuff please!
*/

#ifdef _NORB_DEBUG_

#define DEBUG_PRINT(a)          std::cout << a << std::endl
#define DEBUG_PRINT_WAIT(a)     std::cout << a << std::endl; std::cin.get()

#else

#define DEBUG_PRINT(a)
#define DEBUG_PRINT_WAIT(a) 

#endif