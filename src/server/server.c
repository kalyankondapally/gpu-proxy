#include "config.h"
#include "server.h"

#include "ring_buffer.h"
#include "dispatch_table.h"
#include "thread_private.h"
#include <time.h>

/* This method is auto-generated into server_autogen.c
 * and included at the end of this file. */
static void
server_fill_command_handler_table (server_t *server);

void
server_start_work_loop (server_t *server)
{
    while (true) {
        size_t data_left_to_read;
        command_t *read_command = (command_t *) buffer_read_address (server->buffer,
                                                                     &data_left_to_read);
        /* The buffer is empty, so wait until there's something to read. */
         /*int times_slept = 0;
         while (! read_command && times_slept < 20) {
             sleep_nanoseconds (500);
             read_command = (command_t *) buffer_read_address (server->buffer,
                                                           &data_left_to_read);
             times_slept++;
         }*/

        /* We ran out of hot cycles, try a more lackadaisical approach. */
        while (! read_command) {
            sem_wait (server->server_signal);
            read_command = (command_t *) buffer_read_address (server->buffer,
                                                              &data_left_to_read);
        }

        if (read_command->type == COMMAND_SHUTDOWN)
            break;

        server->handler_table[read_command->type](server, read_command);

        if (read_command->token) {
            server->buffer->last_token = read_command->token;
            buffer_read_advance (server->buffer, read_command->size);
            sem_post (server->client_signal);
        }
        else
            buffer_read_advance (server->buffer, read_command->size);
    }
}

server_t *
server_new (buffer_t *buffer)
{
    server_t *server = malloc (sizeof (server_t));
    server_init (server, buffer);
    return server;
}

static void
server_handle_no_op (server_t *server,
                     command_t *command)
{
    return;
}

mutex_static_init (name_mapping_mutex);
static HashTable *name_mapping_buffer = NULL;
static HashTable *name_mapping_renderbuffer = NULL;
static HashTable *name_mapping_shader_object = NULL;
static HashTable *name_mapping_texture = NULL;
static HashTable *name_mapping_framebuffer = NULL;

static void
server_handle_glgenbuffers (server_t *server,
                                   command_t *abstract_command)
{
    INSTRUMENT();

    command_glgenbuffers_t *command =
        (command_glgenbuffers_t *)abstract_command;

    GLuint *server_buffers = (GLuint *)malloc (command->n * sizeof (GLuint));
    server->dispatch.glGenBuffers (server, command->n, server_buffers);

    int i;
    mutex_lock (name_mapping_mutex);
    for (i = 0; i < command->n; i++) {
        GLuint *data = (GLuint *)malloc (sizeof (GLuint));
        *data = server_buffers[i];
        hash_insert (name_mapping_buffer, command->buffers[i], data);
    }
    mutex_unlock (name_mapping_mutex);

    free (server_buffers);
    command_glgenbuffers_destroy_arguments (command);
}

static void
server_handle_gldeletebuffers (server_t *server, command_t *abstract_command)
{
    INSTRUMENT();

    command_gldeletebuffers_t *command =
        (command_gldeletebuffers_t *)abstract_command;

    int i;
    mutex_lock (name_mapping_mutex);
    for (i = 0; i < command->n; i++) {
        GLuint *entry = hash_take (name_mapping_buffer, command->buffers[i]);
        if (entry) {
            command->buffers[i] = *entry;
            free (entry);
        }
    }
    mutex_unlock (name_mapping_mutex);

    server->dispatch.glDeleteBuffers (server, command->n, command->buffers);

    command_gldeletebuffers_destroy_arguments (command);
}

static void
server_handle_glgenframebuffers (server_t *server, command_t *abstract_command)
{
    INSTRUMENT();

    command_glgenframebuffers_t *command =
        (command_glgenframebuffers_t *)abstract_command;

    GLuint *server_framebuffers = (GLuint *)malloc (command->n * sizeof (GLuint));
    server->dispatch.glGenFramebuffers (server, command->n, server_framebuffers);

    int i;
    mutex_lock (name_mapping_mutex);
    for (i = 0; i < command->n; i++) {
        GLuint *data = (GLuint *)malloc (sizeof (GLuint));
        *data = server_framebuffers[i];
        hash_insert (name_mapping_framebuffer, command->framebuffers[i], data);
    }
    mutex_unlock (name_mapping_mutex);

    free (server_framebuffers);
    command_glgenframebuffers_destroy_arguments (command);
}

static void
server_handle_gldeleteframebuffers (server_t *server, command_t *abstract_command)
{
    INSTRUMENT();

    command_gldeleteframebuffers_t *command =
        (command_gldeleteframebuffers_t *)abstract_command;

    int i;
    mutex_lock (name_mapping_mutex);
    for (i = 0; i < command->n; i++) {
        GLuint *entry = hash_take (name_mapping_framebuffer, command->framebuffers[i]);
        if (entry) {
            command->framebuffers[i] = *entry;
            free (entry);
        }
    }
    mutex_unlock (name_mapping_mutex);

    server->dispatch.glDeleteFramebuffers (server, command->n, command->framebuffers);

    command_gldeleteframebuffers_destroy_arguments (command);
}

static void
server_handle_glgentextures (server_t *server, command_t *abstract_command)
{
    INSTRUMENT();

    command_glgentextures_t *command =
        (command_glgentextures_t *)abstract_command;

    GLuint *server_textures = (GLuint *)malloc (command->n * sizeof (GLuint));
    server->dispatch.glGenTextures (server, command->n, server_textures);

    int i;
    mutex_lock (name_mapping_mutex);
    for (i = 0; i < command->n; i++) {
        GLuint *data = (GLuint *)malloc (sizeof (GLuint));
        *data = server_textures[i];
        hash_insert (name_mapping_texture, command->textures[i], data);
    }
    mutex_unlock (name_mapping_mutex);

    free (server_textures);
    command_glgentextures_destroy_arguments (command);
}

static void
server_handle_gldeletetextures (server_t *server, command_t *abstract_command)
{
    INSTRUMENT();

    command_gldeletetextures_t *command =
        (command_gldeletetextures_t *)abstract_command;

    int i;
    mutex_lock (name_mapping_mutex);
    for (i = 0; i < command->n; i++) {
        GLuint *entry = hash_take (name_mapping_texture, command->textures[i]);
        if (entry) {
            command->textures[i] = *entry;
            free (entry);
        }
    }
    mutex_unlock (name_mapping_mutex);

    server->dispatch.glDeleteTextures (server, command->n, command->textures);

    command_gldeletetextures_destroy_arguments (command);
}

static void
server_handle_glgenrenderbuffers (server_t *server,
                                         command_t *abstract_command)
{
    INSTRUMENT();

    command_glgenrenderbuffers_t *command =
        (command_glgenrenderbuffers_t *)abstract_command;

    GLuint *server_renderbuffers = (GLuint *)malloc (command->n * sizeof (GLuint));
    server->dispatch.glGenRenderbuffers (server, command->n, server_renderbuffers);

    int i;
    mutex_lock (name_mapping_mutex);
    for (i = 0; i < command->n; i++) {
        GLuint *data = (GLuint *)malloc (sizeof (GLuint));
        *data = server_renderbuffers[i];
        hash_insert (name_mapping_renderbuffer, command->renderbuffers[i], data);
    }
    mutex_unlock (name_mapping_mutex);

    free (server_renderbuffers);
    command_glgenrenderbuffers_destroy_arguments (command);
}

static void
server_handle_gldeleterenderbuffers (server_t *server, command_t *abstract_command)
{
    INSTRUMENT();

    command_gldeleterenderbuffers_t *command =
        (command_gldeleterenderbuffers_t *)abstract_command;

    int i;
    mutex_lock (name_mapping_mutex);
    for (i = 0; i < command->n; i++) {
        GLuint *entry = hash_take (name_mapping_renderbuffer, command->renderbuffers[i]);
        if (entry) {
            command->renderbuffers[i] = *entry;
            free (entry);
        }
    }
    mutex_unlock (name_mapping_mutex);

    server->dispatch.glDeleteBuffers (server, command->n, command->renderbuffers);
    command_gldeleterenderbuffers_destroy_arguments (command);
}

static void
server_handle_glcreateprogram (server_t *server, command_t *abstract_command)
{
    INSTRUMENT ();

    command_glcreateprogram_t *command =
            (command_glcreateprogram_t *)abstract_command;
    GLuint *program = (GLuint *)malloc (sizeof (GLuint));

    *program = server->dispatch.glCreateProgram (server);

    mutex_lock (name_mapping_mutex);
    hash_insert (name_mapping_shader_object, command->result, program);
    mutex_unlock (name_mapping_mutex);

}

static void
server_handle_gldeleteprogram (server_t *server, command_t *abstract_command)
{
    INSTRUMENT ();

    command_gldeleteprogram_t *command =
            (command_gldeleteprogram_t *)abstract_command;

    mutex_lock (name_mapping_mutex);
    GLuint *program = hash_take (name_mapping_shader_object, command->program);
    
    if (program) {
        GLuint program_value = *program;
        mutex_unlock (name_mapping_mutex);
        server->dispatch.glDeleteProgram (server, program_value);
    } else
        mutex_unlock (name_mapping_mutex);

    command_gldeleteprogram_destroy_arguments (command);
}

static void
server_handle_glcreateshader (server_t *server, command_t *abstract_command)
{
    INSTRUMENT ();

    command_glcreateshader_t *command =
            (command_glcreateshader_t *)abstract_command;
    GLuint *shader = (GLuint *)malloc (sizeof (GLuint));

    *shader = server->dispatch.glCreateShader (server, command->type);

    mutex_lock (name_mapping_mutex);
    hash_insert (name_mapping_shader_object, command->result, shader);
    mutex_unlock (name_mapping_mutex);
}

static void
server_handle_gldeleteshader (server_t *server, command_t *abstract_command)
{
    INSTRUMENT ();

    command_gldeleteshader_t *command =
            (command_gldeleteshader_t *)abstract_command;

    mutex_lock (name_mapping_mutex);
    GLuint *shader = hash_take (name_mapping_shader_object, command->shader);
    mutex_unlock (name_mapping_mutex);

    if (shader) {
        GLuint shader_value = *shader;
        mutex_unlock (name_mapping_mutex);
        server->dispatch.glDeleteShader (server, shader_value);
    }
    else {
        mutex_unlock (name_mapping_mutex);
        /*XXX: This call should return INVALID_VALUE */
        server->dispatch.glDeleteShader (server, 0xffffffff);
    }

    command_gldeleteshader_destroy_arguments (command);
}

void
server_init (server_t *server,
             buffer_t *buffer)
{
    server->buffer = buffer;
    server->dispatch = *dispatch_table_get_base();
    server->command_post_hook = NULL;

    server->handler_table[COMMAND_NO_OP] = server_handle_no_op;
    server_fill_command_handler_table (server);

    server->handler_table[COMMAND_GLGENBUFFERS] =
        server_handle_glgenbuffers;
    server->handler_table[COMMAND_GLDELETEBUFFERS] =
        server_handle_gldeletebuffers;
    server->handler_table[COMMAND_GLDELETEFRAMEBUFFERS] =
        server_handle_gldeleteframebuffers;
    server->handler_table[COMMAND_GLGENFRAMEBUFFERS] =
        server_handle_glgenframebuffers;
    server->handler_table[COMMAND_GLGENTEXTURES] =
        server_handle_glgentextures;
    server->handler_table[COMMAND_GLDELETETEXTURES] =
        server_handle_gldeletetextures;
    server->handler_table[COMMAND_GLGENRENDERBUFFERS] =
        server_handle_glgenrenderbuffers;
    server->handler_table[COMMAND_GLDELETERENDERBUFFERS] =
        server_handle_gldeleterenderbuffers;
    server->handler_table[COMMAND_GLCREATEPROGRAM] =
        server_handle_glcreateprogram;
    server->handler_table[COMMAND_GLDELETEPROGRAM] =
        server_handle_gldeleteprogram;
    server->handler_table[COMMAND_GLCREATESHADER] =
        server_handle_glcreateshader;
    server->handler_table[COMMAND_GLDELETESHADER] =
        server_handle_gldeleteshader;

    mutex_lock (name_mapping_mutex);
    if (name_mapping_buffer
        && name_mapping_renderbuffer
        && name_mapping_shader_object
        && name_mapping_texture
        && name_mapping_framebuffer) {
	mutex_unlock (name_mapping_mutex);
        return;
    }
    name_mapping_buffer = new_hash_table(free);
    name_mapping_renderbuffer = new_hash_table(free);
    name_mapping_shader_object = new_hash_table(free);
    name_mapping_texture = new_hash_table(free);
    name_mapping_framebuffer = new_hash_table(free);
    mutex_unlock (name_mapping_mutex);
}

bool
server_destroy (server_t *server)
{
    free (server);
    return true;
}

#include "server_autogen.c"
