
#include <string.h>
#include "c24_error.h"


const char *c24_strerror(const int error)
{
    if (error <= 0) {   //  c24 error

        switch (error) {
            
            case SUCCESS:
                return "Success";
            
            case C24_WRONG_CHECKSUM:
                return "Wrong Checksum Received";

            case C24_TIMEOUT_REACHED:
                return "Timeout reached";

            case C24_INCOMPLETE_FRAME:
                return "Imcomplete frame was received";
            
            case C24_UNKNOW_REQUEST_BLOCK :
                return "Unknown request block\n";

            default:
                return "Unknown error";
        }

    }
    else {  //  errno error
        return strerror(error);
    }
}