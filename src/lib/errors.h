#include <stdint.h>

#ifndef JANE_ERRORS_H
#define JANE_ERRORS_H

#define JANE_ERROR_GENERIC_STRUCT_ALLOC_ERROR	0x40
#define JANE_ERROR_GET_REMOTE_FILE_ERROR		0x41
#define JANE_ERROR_NO_ERROR						0x42

#define JANE_ERROR_DOC	"http://url_to_jane_errro_doc/#errono"

extern uint16_t jane_error;

#endif