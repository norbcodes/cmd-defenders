#pragma once

#ifdef _NORB_DEBUG_
#include <iostream>
#endif // _NORB_DEBUG_

/*
Debug my stuff please!
*/

#ifdef _NORB_DEBUG_
#define DEBUG_PRINT(a)          std::cout << a; std::cout << std::endl
#define DEBUG_PRINT_WAIT(a)     std::cout << a; std::cout << std::endl; std::cin.get()
#else // _NORB_DEBUG_
#define DEBUG_PRINT(a)
#define DEBUG_PRINT_WAIT(a) 
#endif // _NORB_DEBUG_