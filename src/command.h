#ifndef GPUPROCESS_COMMAND_H
#define GPUPROCESS_COMMAND_H

#include "compiler_private.h"

#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <stdlib.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum command_type {
    COMMAND_NO_OP,
    COMMAND_SET_TOKEN,

#include "generated/command_types_autogen.h"

    COMMAND_MAX_COMMAND
} command_type_t;

typedef struct command {
    command_type_t type;
    size_t size;
} command_t;

/* SetToken command, it writes a token in the command buffer, allowing
  the client to check when it is consumed in the server. */
typedef struct command_set_token {
    command_t header;
    unsigned int token;
} command_set_token_t;

private void
command_initialize_sizes (size_t* sizes);

private size_t
command_get_size (command_type_t command_type);

private void
command_set_token_init (command_set_token_t *command,
                        unsigned int token);

#include "generated/command_autogen.h"

#ifdef __cplusplus
}
#endif

#endif /* GPUPROCESS_COMMAND_H */
