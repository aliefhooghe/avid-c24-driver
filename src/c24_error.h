#ifndef C24_ERROR_H_
#define C24_ERROR_H_

#include <errno.h>

//  Positive error value are errno error, 
//  negative are c24 error
//  Error are returned with return

enum c24_error {
    SUCCESS = 0,
    C24_WRONG_CHECKSUM = -1,
    C24_TIMEOUT_REACHED = -2,
    C24_INCOMPLETE_FRAME = -3,
    C24_UNKNOW_REQUEST_BLOCK = -4
};

const char *c24_strerror(const int error);

#endif
